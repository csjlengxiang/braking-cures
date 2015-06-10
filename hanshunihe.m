yz_x = [-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]
yz_y = [1, 2, 7, 10, 46, 103, 17, 23, 6, 2, 1]

cnt = 1
for i = 1:11
    for j = 1:yz_y(i)
        x(cnt) = yz_x(i)
        cnt=cnt+1
    end
end

subplot(2,2,1)
[n,xout] = hist(x,yz_x);
bar(xout,n)
title('入口速度偏差直方图')
grid on

[f,xi]=ksdensity(x)
subplot(2,2,2)
plot(xi,f)
title('拟合的概率密度')
grid on

sm = sum(f)
c=cumsum(f / sm);%计算累计分布
subplot(2,2,[3,4]) 
plot(xi,c);%画图
title('累积分布函数')
grid on


% [h,stats] = cdfplot(f)
% xd = h.XData
% yd = h.YData
% dx = 0.5;  
% Num = 100000;  
% x = -4:dx:4;  
% y = randn(Num,1);
% [n,xout] = hist(y,x);
% 
% [f,xi]=ksdensity(y)
% plot(xi,f)

% [h,stats] = cdfplot(y)
% xd = h.XData
% yd = h.YData
% bar(x,n)
% plot(x, n)

% cdf = cumsum(n)/Num;  
% plot(x,cdf,'b-','LineWidth',6); hold on  
% plot(x,normcdf(x,0,1),'r-','LineWidth',2)  
% legend('Empirical CDF via hist', 'Analytical CDF via normpdf',4);  
% axis tight 


% dx = 0.001;  
% Num = 8001;  
% x = -4:dx:4;  
% y = randn(Num,1);  
% [f,xi]=ksdensity(y)
% plot(xi,f)