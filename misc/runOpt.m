function [q,q_prev] = runOpt(task,q_prev,x0,A,b,lb,ub,set_angle) 

fun = @(q)((norm(task-fwk(q)))^2 +  (1)*(norm(q(1:6)-q_prev(1:6)))^2  +...
    norm(fwkeul_alpha(q(1:6)) - (set_angle(1,1)))^2 +...
    norm(fwkeul_gamma(q(1:6)) - (set_angle(1,3)))^2 +...
    norm(fwkeul_beta(q(1:6))  - (set_angle(1,2)))^2);
option = optimoptions('fmincon','Display','off','Algorithm','sqp');
q = fmincon(fun,x0,A,b,[],[],lb,ub,[],option);   % //'interior-point-convex';
q_prev = q;


end

