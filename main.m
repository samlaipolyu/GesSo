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
win = 3;
j = 2;
temp = 1;
err = [];
err_angle = [];
q_rec = [];

while 1
    tStart = tic;
    % If a hand is detected:
    metaData =  matleap(1);
    if ~isempty(metaData.hands)
        x = 0.1*metaData.hands(1).palm.position(1);
        y = 150-0.05*metaData.hands(1).palm.position(2);
        z = -0.1*metaData.hands(1).palm.position(3);
        x = round(x,2);
        y = round(y,2);
        z = round(z,2);

        ori = (eul2rotm(metaData.hands(1).palm.normal(:)'));
        palm_width = metaData.hands(1).palm.width;
        fist = metaData.hands(1).grab_strength(1);
        %                  figure(2)
        %                  handFrame = drawHandFrame(x,y,z,ori,palm_width,fist);
        gesture = [metaData.hands(1).digits(1).is_extended;
            metaData.hands(1).digits(2).is_extended;
            metaData.hands(1).digits(3).is_extended;
            metaData.hands(1).digits(4).is_extended;
            metaData.hands(1).digits(5).is_extended];
        vSign = [0;1;1;0;0];
        vSign_bias = [0;1;0;0;0];
        goodSign = [1;0;0;0;0];
        fist = [0;0;0;0;0];
        
        % --------------------- Moving Average ---------------------
        if firstShot <= win
            task_tap(:,firstShot) = round([2*x;2*z;y],3);
            set_angle= metaData.hands(1).palm.normal;
            set_angle_tap(firstShot,:) = [set_angle(1,2), set_angle(1,1),set_angle(1,3)]; % 213
            firstShot = firstShot + 1;
        else
            firstShot = 1;
            task_tap(:,firstShot) = round([2*x;2*z;y],3);
            set_angle = metaData.hands(1).palm.normal;
            set_angle_tap(firstShot,:) = [set_angle(1,2), set_angle(1,1),set_angle(1,3)]; % 213
            firstShot = 2;
        end

        task = mean(task_tap,2);
        set_angle = mean(set_angle_tap,1);
        if size(task_tap,2) == 3
            temp_cov = (task_tap - task*ones(1,win)).^2;
            temp_cov_angle = (set_angle_tap - set_angle*ones(win,1)).^2;
            cov_task = sqrt((1/win) * sqrt((temp_cov(:,1) + temp_cov(:,2) + temp_cov(:,3))));
            cov_angle = sqrt((1/win) * sqrt((temp_cov_angle(1,:) + temp_cov_angle(2,:) + temp_cov_angle(3,:))));
            if all(task_tap(:,end) <= task_tap(:,end-1) + cov_task) && all(task_tap(:,end) >= task_tap(:,end-1) - cov_task)
                task = mean(task_tap,2);
            end
            if all(set_angle_tap(end,:) <= set_angle_tap(end-1,:) + cov_angle) &&...
                    all(set_angle_tap(end,:) >= set_angle_tap(end-1,:) - cov_angle)
                set_angle = mean(set_angle_tap,1);
            end
        end
        
        % V-sign for [0 0 Z] tip positioning, but orienetation still counts
        if (gesture == vSign)
            task = round([0;0;y],3);
            disp('V-sign detected!')
        elseif (gesture == vSign_bias)
            task = round([0;0;y],3);
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
            tic
            [q,q_prev] = runOpt_mex(task,q_prev,x0,A,b,lb,ub,set_angle);  %%
            toc
        end
        
        % thumbs-up sign straight configuration
        if gesture == goodSign
            q = [0.00001;0;0;0;0.00001;0;y-100];
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
        
        % Actuation filtering 
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
        pause(0.0001);

    end
    
end

