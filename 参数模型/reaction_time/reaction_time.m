[yz_x,yz_y]=textread('C:\Users\csj\Desktop\braking-cures\����ģ��\reaction_time\reaction_time.txt','%f%d','headerlines',0);
cnt = 1
len = length(yz_x)
for i = 1:len
    for j = 1:yz_y(i)
        x(cnt) = yz_x(i)
        cnt=cnt+1
    end
end

subplot(2,2,1)
[n,xout] = hist(x);
bar(xout,n)
title('��Ӧʱ��ֱ��ͼ')
grid on

[f,xi]=ksdensity(x)
sm = sum(f)
subplot(2,2,2)
plot(xi,f)
title('��ϵĸ����ܶ�')
grid on

c=cumsum(f / sm);%�����ۼƷֲ�
subplot(2,2,[3,4]) 
plot(xi,c);%��ͼ
title('�ۻ��ֲ�����')
grid on

