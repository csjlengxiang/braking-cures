[d1,v1]=textread('C:\Users\csj\Desktop\braking-cures\标准\out.txt','%f%f','headerlines',0);
[d2,v2]=textread('C:\Users\csj\Desktop\braking-cures\铁道部签字\out.txt','%f%f','headerlines',0);

% lg = log(100);
% d1 = log(d1) / lg;
% d2 = log(d2) / lg;
semilogx(d1,v1)
hold on
plot(d1, v1, d2, v2)
grid on
hold on
%标定坐标
axis([700 18000 0 450])
gd = [888.889,1000.45,1112.68,1225.13,1337.48,17352.9,17357.5];
% gd = log(gd) / lg;
gd_len = length(gd);
for i=1:1:gd_len
    gd(i)
    plot([gd(i), gd(i)],[0, 450],'--k')
    hold on
end

% x=0:0.1:2.2;
% y=160./(1+exp(-6*(x-1)));
% plot(x,y,'k')
% 画 85% 的横竖线
% max_y = max(y);
% y1 = 0.85 * max_y;
% x1 = interp1(y,x,y1);
% hold on
% plot([x1 x1], [0 y1],'--k')
% plot([0 x1], [y1 y1],'--k')
% text(x1/2,y1,'85% 位','horiz','center','vert','bottom')
