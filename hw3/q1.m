% mert karakaya 090210362
clc
clear

x = [0.9,1.3,1.9,2.1,2.6,3,3.9,4.4,4.7,5,6,7,8,9.2,10.5,11.3,11.6,12,12.6];
y = [1.3,1.5,1.85,2.1,2.6,2.7,2.4,2.15,2.05,2.1,2.25,2.3,2.25,1.95,1.4,0.9,0.7,0.6,0.5];

n = length(x);
h = zeros(1,n-1);
for i = 1:n-1
    h(i) = x(i+1) - x(i);
end

M = zeros(n);
M(1,1) = 1;
M(n,n) = 1;
for i = 2:n-1
    M(i,i-1) = h(i-1);
    M(i,i) = 2*(h(i-1) + h(i));
    M(i,i+1) = h(i);
end

alpha = zeros(n,1);
for i = 2:n-1
    alpha(i) = -3*((y(i)-y(i-1))/h(i-1) - (y(i+1)-y(i))/h(i));
end

c = M\alpha;

d = zeros(n-1,1);
for i = 1:n-1
    d(i) = (c(i+1) - c(i))/(3*h(i));
end

a = y';

b = zeros(n-1,1);
for i = 1:n-1
    b(i) = (a(i+1) - a(i))/h(i) - h(i)*(c(i+1) + 2*c(i))/3;
end

plot(x,y,'o')
hold on
xp = 0.9:0.001:12.6;
for i = 1:n-1
    idx = xp >= x(i) & xp <= x(i+1);
    si = a(i) + b(i)*(xp(idx)-x(i)) + c(i)*(xp(idx)-x(i)).^2 + d(i)*(xp(idx)-x(i)).^3;
    plot(xp(idx),si)
end
hold off