clear
clc
close all

ii = 1;
tTemp = [];

hrange = .4;
hbias = .4;
low  = max(min(hbias - (hrange./2), 1), 0);
high = max(min(hbias + (hrange./2), 1), 0);
hrangeLimited = high - low;

while 1
    metaData =  matleap(1);
    if ~isempty(metaData.hands)
        tStart = tic;
        x = metaData.hands(1).palm.position(1);
        y = metaData.hands(1).palm.position(2);
        z = metaData.hands(1).palm.position(3);
        
        vx = metaData.hands(1).palm.velocity(1);
        vy = metaData.hands(1).palm.velocity(2);
        vz = metaData.hands(1).palm.velocity(3);
        
        if isempty(tTemp)
            deltaT = 0.05;
        else
            deltaT = tTemp;
        end
        
        x = round(x,2);
        y = round(y,2);
        z = round(z,2);

        
        % Kalman
        
        A = [1,deltaT,0.5*deltaT^2,      0,0,0,                  0,0,0;
            0,1,deltaT,                  0,0,0,                  0,0,0;
            0,0,1,                       0,0,0,                  0,0,0;
            
            0,0,0,       1,deltaT,0.5*deltaT^2,                  0,0,0;
            0,0,0,                  0,1,deltaT,                  0,0,0;
            0,0,0,                       0,0,1,                  0,0,0;
            
            0,0,0,                       0,0,0,   1,deltaT,0.5*deltaT^2;
            0,0,0,                       0,0,0,              0,1,deltaT;
            0,0,0,                       0,0,0,                   0,0,1];
        
        B = eye(9);
        
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
        
        initState = [x vx 0 y vy 0 z vz 0]; % as [x vx ax y vy ay z vz az]
        prevState = transpose(initState);
        
        
        x_seq(ii,1) = x;
        y_seq(ii,1) = y;
        z_seq(ii,1) = z;
        vx_seq(ii,1) = vx;
        vy_seq(ii,1) = vy;
        vz_seq(ii,1) = vz;
        
        
        
        if ii >= 6
            for i = ii-5:ii-1
                predictState = A*prevState; % equation 1
                P = A*P*A'+B*Q*B'; % equation 2
                prevState = predictState;
                
                detectState = [x_seq(i), vx_seq(i), 0,  y_seq(i), vy_seq(i), 0, z_seq(i), vz_seq(i), 0]'; % zt
                % update
                K = P*H'/(H*P*H'+R); % equation 3
                predictState = prevState+K*(detectState-H*prevState); % equation 4
                P = (eye(9)-K*H)*P; % equation 5
                
                prevState = predictState;
                % pause(0.1);
                if i == ii-1
                    plot3(predictState(1),predictState(4),predictState(7),'r^','linewidth',2);
                    hold on
                end
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

            x = predictState(1);
            y = predictState(4);
            z = predictState(7);

            %ori = (eul2rotm(metaData.hands(1).palm.normal(:)'));
            palm_width = metaData.hands(1).palm.width;
            plotCircle3D([x,y,z],quat2eul(quat_int'),palm_width);
            hold on
            plotCircle3D([x,y,z],quat2eul(quat_int'),palm_width/2);
            plot3(x,y,z,'ko','LineWidth',2);
            hold on
            
            plot3([x;x-80*ori(1,1)],[y;y-80*ori(2,1)],[z;z-80*ori(3,1)],'r-','linewidth',2)
            plot3([x;x-80*ori(1,2)],[y;y-80*ori(2,2)],[z;z-80*ori(3,2)],'b-','linewidth',2)
            plot3([x;x-80*ori(1,3)],[y;y-80*ori(2,3)],[z;z-80*ori(3,3)],'color',[0 .6 .2],'linewidth',2)
            hold off
            fist = metaData.hands(1).grab_strength;
            title (num2str(fist))
            
          %  text(x,z,y,['(' num2str(x) ',' num2str(z) ',' num2str(y) ')']);
            grid on;
            axis([-600 600 -600 600 -600 600]);
            view([0 90]);
            axis square
            camproj perspective
            ax = gca;
            ax.LineWidth = 1;
            % set(ax,'Color','[0.9 0.9 0.9]');
            % ax.GridColor = [.5, .5, .5];
        end
        
        tTemp = toc(tStart)
        ii = ii + 1;
        drawnow;
       % hold on
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


