function handFrame = drawHandFrame(x,y,z,ori,palm_width,fist)

handFrame = figure(11);
plotCircle3D([x,y,z],rotm2eul(ori),palm_width/5);
% hold on
plotCircle3D([x,y,z],rotm2eul(ori),palm_width/10);
% plot3(x,y,z,'ko','LineWidth',2);
% hold on
%  plot3([x;x+80*ori(1,1)],[y;y+80*ori(2,1)],[z;z+80*ori(3,1)],'r-','linewidth',2)
plot3([x;x+10*ori(1,2)],[y;y+10*ori(2,2)],[z;z+10*ori(3,2)],'b-','linewidth',2)
%  plot3([x;x-80*ori(1,3)],[y;y-80*ori(2,3)],[z;z+80*ori(3,3)],'color',[0 .6 .2],'linewidth',2)
hold off

title (num2str(fist))
text(x,y,z,['(' num2str(x) ',' num2str(z) ',' num2str(y) ')']);
grid on;
set(gca,'Ydir','reverse')
set(gca,'Xdir','reverse')
set(gca,'Zdir','reverse')
axis([-100 100 100 200 -100 100]);
view([0 90]);
axis square
camproj perspective
drawnow;

end

