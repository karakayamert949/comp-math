% mert karakaya 090210362
clc
clear

% for [2,3]
% y''' = -y'*x^2 + 2xy
% y3' = -y2*x^2 + 2x*y1

x0=2;
y0=[3;2;1];

x=2:0.1:3;
h=0.1;
y_vals=y0;
for i=2:length(x)
    k1=-y0*x0^2 + 2*x0*y0;
    k2=-(y0+ k1*2*h/3)*(x0+2*h/3)^2 + 2*(x0+2*h/3)*(y0+ k1*2*h/3);
    x0=x0+h;
    y0 = y0 + h*(k1/4 +k2*3/4);
    y_vals = [y_vals y0];
end
yp=y_vals(3,:);

plot(x,yp,'b')
hold on

% for [1,2]

x0=2;
y0=[3;2;1];

x=2:-0.1:1;
h=-0.1;
y_vals=y0;
for i=2:length(x)
    k1=-y0*x0^2 + 2*x0*y0;
    k2=-(y0+ k1*2*h/3)*(x0+2*h/3)^2 + 2*(x0+2*h/3)*(y0+ k1*2*h/3);
    x0=x0+h;
    y0 = y0 + h*(k1/4 +k2*3/4);
    y_vals = [y_vals y0];
end
yp=y_vals(3,:);

plot(x,yp,'b')

legend('2nd order runde kutta heun method')