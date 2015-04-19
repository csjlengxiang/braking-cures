[d1,v1]=textread('C:\Users\csj\Desktop\braking-cures\标准\out.txt','%f%f','headerlines',0);
[d2,v2]=textread('C:\Users\csj\Desktop\braking-cures\铁道部签字\out.txt','%f%f','headerlines',0);
semilogx(d1,v1)
hold on
plot(d1, v1, d2, v2)
grid on
hold on
%标定坐标
axis([700 18000 0 450])
gd = [888.889,1000.45,1112.68,1225.13,1337.48,17352.9,17357.5];
gd_len = length(gd);
for i=1:1:gd_len
    gd(i)
    plot([gd(i), gd(i)],[0, 450],'--k')
    hold on
end
