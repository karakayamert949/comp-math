% mert karakaya 090210362
clc
clear

x=[2, 3, 4, 7, 10];
y=[49, 32, 28, 29, 33];

% lny = lna + (b/x)

Yu=sum(log(y));
Yb=sum((1./x).*log(y));
Y=[Yu;
   Yb];

lu=length(x);
ru=sum(1./x);
lb=sum(1./x);
rb=sum(1./x.^2);

M=[lu, ru;
   lb, rb];

coef=M\Y;
a=exp(coef(1));
b=coef(2);

xp=2:0.01:10;
f=a*exp(b./xp);

plot(x,y,"o")
hold on
plot(xp,f)

f8=a*exp(b./8)
% function value at x=8 is 28.8238
% a=25.2275 b=1.0661