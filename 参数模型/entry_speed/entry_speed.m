[yz_x, yz_y]=textread('C:\Users\csj\Desktop\braking-cures\����ģ��\entry_speed\entry_speed.txt','%d%d','headerlines',0);
cnt = 1
len = length(yz_x)
for i = 1:len
    for j = 1:yz_y(i)
        x(cnt) = yz_x(i)
        cnt=cnt+1
    end
end

subplot(2,2,1)
[n,xout] = hist(x,yz_x);
bar(xout,n)
title('����ٶ�ƫ��ֱ��ͼ')
grid on

[f,xi]=ksdensity(x)
subplot(2,2,2)
plot(xi,f)
title('��ϵĸ����ܶ�')
grid on



















sm = sum(f)
c=cumsum(f / sm);%�����ۼƷֲ�
subplot(2,2,[3,4]) 
plot(xi,c);%��ͼ
title('�ۻ��ֲ�����')
grid on

fid=fopen('C:\Users\csj\Desktop\braking-cures\����ģ��\entry_speed\entry_speed_out_�����ܶ�.txt','a+');
fprintf(fid,'%g\r\n', xi);
fclose(fid);

fid=fopen('C:\Users\csj\Desktop\braking-cures\����ģ��\entry_speed\entry_speed_out_����.txt','a+');
fprintf(fid,'%g\r\n', f);
fclose(fid);

fid=fopen('C:\Users\csj\Desktop\braking-cures\����ģ��\entry_speed\entry_speed_out_�ۻ��ֲ�.txt','a+');
fprintf(fid,'%g\r\n', c);
fclose(fid);

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