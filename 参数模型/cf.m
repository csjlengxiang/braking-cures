
% for i=1:100
%     a(i)=i
%     b(i)=i
% end
% 
% b = b'
% 
% c = b * a   

dx = 0.001;
Num = 100000;
x = -4:dx:4;
y = randn(Num,1);
[n,xout] = hist(y,x);
pdf = n/Num/dx;
subplot(1,2,1)
bar(xout,pdf);
len = length(n)
d = int32(len / 40)

for i=1:len
    st = i - d;
    if st < 1
        st = 1;
    end
    en = i + d;
    if en > len
        en = len;
    end
    sx = 0;
    cnt = 0;
    for j=st:en
        sx = sx + n(j);
        cnt = cnt + 1;
    end
    sx = sx / cnt;
    nx(i) = sx;
end
subplot(1,2,2)
bar(xout, nx/Num/dx);
hold on
plot(x, normpdf(x,0,1),'r-','LineWidth',1);hold off
