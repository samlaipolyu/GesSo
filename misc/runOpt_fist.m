function [q,q_prev] = runOpt_fist(task,task_mid,q_prev,x0,A,b,lb,ub) 


fun = @(q)((norm(task-fwk_fist_tip(q)))^2 + (1)*(norm(q(1:6)-q_prev(1:6)))^2  +...
          (norm(task_mid-fwk_fist_mid(q)))^2);
option = optimoptions('fmincon','Display','off','Algorithm','sqp');
q = fmincon(fun,x0,A,b,[],[],lb,ub,[],option);   % //'interior-point-convex';
q_prev = q;


end

