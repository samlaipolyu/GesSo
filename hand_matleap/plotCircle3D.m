function plotCircle3D(center,normal,radius)
    theta=0:0.05:2*pi;
    v=null(normal);
    points=repmat(center',1,size(theta,2))+radius*(v(:,1)*cos(theta)+v(:,2)*sin(theta));
    plot3(points(1,:),points(2,:),points(3,:),'color',[0.6 0.4 0.6],'linewidth',2);
end