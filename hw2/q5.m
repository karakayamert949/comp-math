% MERT KARAKAYA 090210362

clc
clear

format long g

x=[0:0.2:3];
y=cos(x);

% a) If we use the highest order interpolation polynomial, we have to
% use all of the points in x. Because of using all of the same points
% for three methods, they will construct the same polynomial, therefore
% any method is appropriate. I used forward finite difference method.

% b) If we use the same data points, all methods will contruct the same
% polynomial, so any method is appropriate. To construct smaller order
% interpolation polynomial, we choose less data points rather than 
% using all points. In order to make less error, we have to choose data points
% that are closest to the point which we want to estimate the value of
% the function at. 
% For example to contruct 5th order interpolation polynomial we choose
% closest 6 points to the point which we want to estimate the value of
% the function at.

% c)
yreal=cos(0.1) % yreal = 0.995004165278026

yhighest=FFDM(x,y,0.1) % yhighest = 0.982946248672039

xn=x(1:6);
yn=cos(xn);
ysmaller=FFDM(xn,yn,0.1) % ysmaller = 0.984972068450624

% d)
hierr=abs((yreal-yhighest)/yreal) % hierr = 0.0121184584213451
smerr=abs((yreal-ysmaller)/yreal) % smerr =  0.010082467166958

% 5th order interpolation polynomial has less error than highest order
% interpolation polynomial at point 0.1.
% Smaller order polynomials are generally more stable and less prone to
% oscillation, this why smaller order has less error

function Px0 = FFDM(x,y,x0)
    h=x(2)-x(1);
    n = length(x);

    % M is the FFD table
    M=zeros(n);
    M(1:n,1)=y;
    for i=1:n-1
        for j=2:n
            M(i,j)=M(i+1,j-1)-M(i,j-1);
        end
    end

    xt=1;
    Px0=M(1,1);
    for i=1:n-1
        xt = (xt * (x0-x(i)) );
        Px0 = Px0 + M(1,i+1) * (xt / ( (h^i) * factorial(i) ));
    end
end