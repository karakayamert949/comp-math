% mert karakaya 090210362
clc
clear

%solution of differential eq is
% y=2/e^x + (e^3-2e^2)/e^3x

% euler's method
% y' = 4e^-x -3y
% for [1,2]
h=0.1;
x=1:0.1:2;
y=zeros(1,length(x));
y(1)=1;
for i=2:length(x)
    y(i)=y(i-1) + h*(4*exp(-x(i-1)) -3*y(i-1));
end

plot(x,y,'r')
hold on

% for [0,1]
h=-0.1;
x=1:-0.1:0;
y=zeros(1,length(x));
y(1)=1;
for i=2:length(x)
    y(i)=y(i-1) + h*(4*exp(-x(i-1)) -3*y(i-1));
end

plot(x,y,'r')

% runge kutta 4th order method
% y' = 4e^-x -3y
% for [1,2]
h=0.1;
x=1:0.1:2;
x0=1;
y0=1;
y_vals = y0;
for i=2:length(x)
    k1 = (4*exp(-x0) -3*y0);
    k2 = (4*exp(-(x0 + h/2)) -3*(y0 + k1*h/2));
    k3 = (4*exp(-(x0 + h/2)) -3*(y0 + k2*h/2));
    k4 = (4*exp(-(x0 + h)) -3*(y0 + k1*h));
    y0 = y0 + h*(k1/6 + k2/3 + k3/3 + k4/6);
    x0 = x0 + h;
    y_vals = [y_vals y0];
end
plot(x,y_vals,'b')

% for [0,1]
h=-0.1;
x=1:-0.1:0;
x0=1;
y0=1;
y_vals = y0;
for i=2:length(x)
    k1 = (4*exp(-x0) -3*y0);
    k2 = (4*exp(-(x0 + h/2)) -3*(y0 + k1*h/2));
    k3 = (4*exp(-(x0 + h/2)) -3*(y0 + k2*h/2));
    k4 = (4*exp(-(x0 + h)) -3*(y0 + k1*h));
    y0 = y0 + h*(k1/6 + k2/3 + k3/3 + k4/6);
    x0 = x0 + h;
    y_vals = [y_vals y0];
end
plot(x,y_vals,'b')

y = 2./exp(x) + (exp(3)-2*exp(2))./exp(3*x);
plot(x,y,'g')

legend("euler's method [1,2]","euler's method [0,1]","runge kutta 4th order method for [1,2]","runge kutta 4th order method for [0,1]","analytical solution")

% comparing analytical solution with two methods,
% runge kutta 4th order is more accurate than euler's method.