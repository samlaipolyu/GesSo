clear
clc
close
dbstop if error

% Optimization Constraints Setting
x0 = -1*[0.01 0.02 0.01 0.01 0.02 0.02 -1]';
q_prev = zeros(7,1);
q = [-0.01*ones(6,1);20];
A = [1 1 1 1 1 1 (10^-3)];
b = 10^-3;
ub = [-eps; -eps; -eps; -eps; -eps; -eps; 50];
lb = -[2; 2; 2; 2; 2; 2; 30];
tStart = tic;

firstShot = 1;
firstShot_q = 1;
temp = 1;

ii = 1;
tTemp = [];

hrange = .4;
hbias = .4;
low  = max(min(hbias - (hrange./2), 1), 0);
high = max(min(hbias + (hrange./2), 1), 0);
hrangeLimited = high - low;

while 1
    tStart = tic;
    % If a hand is detected:
    metaData =  matleap(1);
    if ~isempty(metaData.hands)
%          x = 0.1*metaData.hands(1).palm.position(1);
%          y = 150-0.05*metaData.hands(1).palm.position(2);
%          z = -0.1*metaData.hands(1).palm.position(3);
         x = metaData.hands(1).palm.position(1);
         y = metaData.hands(1).palm.position(2);
         z = metaData.hands(1).palm.position(3);


        vx = metaData.hands(1).palm.velocity(1);
        vy = metaData.hands(1).palm.velocity(2);
        vz = metaData.hands(1).palm.velocity(3);
        
        if isempty(tTemp)
            deltaT = 0.02;
        else
            deltaT = tTemp;
        end
    
        % Kalman
        AA = [1,deltaT,0.5*deltaT^2,      0,0,0,                  0,0,0;
            0,1,deltaT,                  0,0,0,                  0,0,0;
            0,0,1,                       0,0,0,                  0,0,0;
            
            0,0,0,       1,deltaT,0.5*deltaT^2,                  0,0,0;
            0,0,0,                  0,1,deltaT,                  0,0,0;
            0,0,0,                       0,0,1,                  0,0,0;
            
            0,0,0,                       0,0,0,   1,deltaT,0.5*deltaT^2;
            0,0,0,                       0,0,0,              0,1,deltaT;
            0,0,0,                       0,0,0,                   0,0,1];
        
        B = [];
        
        H = [1 0 0 0 0 0 0 0 0;
            0 1 0 0 0 0 0 0 0;
            0 0 0 0 0 0 0 0 0;
            0 0 0 1 0 0 0 0 0;
            0 0 0 0 1 0 0 0 0;
            0 0 0 0 0 0 0 0 0;
            0 0 0 0 0 0 1 0 0;
            0 0 0 0 0 0 0 1 0;
            0 0 0 0 0 0 0 0 0];
        
        p = diag([1e+9,1e+9,1e+9]);
        P = blkdiag(p,p,p);
        Q = diag(ones(1,9));
        R = (2.5e6)*eye(9);
        
        initState = [x vx 0 y vy 0 z vz 0];
        prevState = transpose(initState);
    
        x_seq(ii,1) = x;
        y_seq(ii,1) = y;
        z_seq(ii,1) = z;
        vx_seq(ii,1) = vx;
        vy_seq(ii,1) = vy;
        vz_seq(ii,1) = vz;
    
        if ii >= 6
            for i = ii-5:ii-1
                predictState = AA*prevState; % equation 1
                P = AA*P*AA'+Q; % equation 2
                prevState = predictState;
                detectState = [x_seq(i), vx_seq(i), 0,  y_seq(i), vy_seq(i), 0, z_seq(i), vz_seq(i), 0]'; % zt
                % update
                K = P*H'/(H*P*H'+R); % equation 3
                predictState = prevState+K*(detectState-H*prevState); % equation 4
                P = (eye(9)-K*H)*P; % equation 5
                prevState = predictState;
                x = prevState(1);
                y = prevState(4);
                z = prevState(7);
                task = [0.2*prevState(1),-0.2*prevState(7),150-0.1*prevState(4)]';
            end
        end

        quat_seq(ii,:) = eul2quat(metaData.hands(1).palm.normal(:)');
        
        if ii >= 6
            quat_int = quat_seq(ii-1,:)';
            d = dist(quaternion(quat_seq(ii-1,:)),quaternion(quat_seq(ii,:)));
            hlpf = (d./pi).*hrangeLimited + low;
            quat_out = slerp(quat_int,quat_seq(ii,:)',hlpf);
            quat_int = quat_out;   
            ori = quat2rotm(quat_int');
            set_angle = quat2eul(quat_int');
            palm_width = metaData.hands(1).palm.width;
            fist = metaData.hands(1).grab_strength(1);
            gesture = [metaData.hands(1).digits(1).is_extended;
                metaData.hands(1).digits(2).is_extended;
                metaData.hands(1).digits(3).is_extended;
                metaData.hands(1).digits(4).is_extended;
                metaData.hands(1).digits(5).is_extended];
            vSign = [0;1;1;0;0];
            vSign_bias = [0;1;0;0;0];
            goodSign = [1;0;0;0;0];
            fist = [0;0;0;0;0];

            % V-sign for [0 0 Z] tip positioning, but orienetation still counts
            if (gesture == vSign)
                task = round([0;0;task(3)],3);
                disp('V-sign detected!')
            elseif (gesture == vSign_bias)
                task = round([0;0;task(3)],3);
                disp('V-sign detected!')
            end
            
            % Workspace protection
            if (abs(task(1,1)) >= 70) == 1
                disp('Out of Safe Workspace!')
                if task(1,1) >=0
                    task(1,1) = 70;
                else
                    task(1,1) = -70;
                end
            elseif (abs(task(2,1)) >= 70) == 1
                disp('Out of Safe Workspace!')
                if task(2,1) >=0
                    task(2,1) = 70;
                else
                    task(2,1) = -70;
                end
            elseif (task(3,1) <= 120) == 1
                disp('Out of Safe Workspace!')
                task(3) = 120;
            end
            
            q_prev = q;
            
            if all(gesture == fist) == 0
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                tic                                                           %%
                [q,q_prev] = runOpt_mex(task,q_prev,x0,A,b,lb,ub,set_angle);  %%
                toc                                                           %%
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            end
            
            % thumbs-up sign straight configuration
            if gesture == goodSign
                q = [0.00001;0;0;0;0.00001;0;task(3)-80];
                disp('Thumbs-up gesture detected!')
            end

            % Fist-pump sign to freeze the proximal motion
            if all(gesture == fist)
                disp('Fist-pump detected!')
                if temp == 1
                    task_mid= fwk_fist_mid(q);
                    temp = 0;
                end
                q_prev = q;
                tic
                [q,q_prev] = runOpt_fist_mex(task,task_mid,q_prev,x0,A,b,lb,ub);
                toc
            else
                temp = 1;
            end
            
            % Actuation filtering %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            if firstShot_q <=3
                q_tap(:,firstShot_q) = q;
                firstShot_q = firstShot_q + 1;
            else
                firstShot_q = 1;
                q_tap(:,firstShot_q) = q;
                firstShot = 2;
            end
            q = mean(q_tap,2);
            
            [~, p_02, sim_angle] = drawAnimation(q);
            
            elapsedTime = toc;
            fps = 1/elapsedTime;
            txt = sprintf('%.2f Hz.',fps);
            disp(txt)
        end
        tTemp = toc(tStart);
        ii = ii + 1;
    end
    
end




function [q3] = slerp(q1,q2,t)
%SLERP quaternion slerp
%   computes the slerp of value t between quaternions q1 and q2

q1 = q1./norm(q1);
q2 = q2./norm(q2);

one = 1.0 - eps;
d = q1'*q2;
absD = abs(d);

if(absD >= one)
    scale0 = 1 - t;
    scale1 = t;
else
    theta = acos(absD);
    sinTheta = sin(theta);
    
    scale0 = sin((1-t)*theta)/sinTheta;
    scale1 = sin((t*theta))/sinTheta;
end
if(d < 0)
    scale1 = -scale1;
end

q3 = scale0 * q1 + scale1 * q2;
q3 = q3./norm(q3);
end


