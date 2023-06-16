// MERT KARAKAYA 090210362
#include <iostream>
#include <cmath>
#include <ctime>

double f(double x)
{
    return pow(x,2) -4*exp(-x) -3;
}

double g0(double x)
{
    return -log((3 - pow(x,2))/-4);
}

double g1(double x)
{
    return sqrt(3 + 4*exp(-x));
}

double Fixed(double (*f)(double), double (*g)(double), double x0, double tol, int iter)
{
    double x = x0;
    int n = 0;
    while (n < iter)
    {
        if(fabs(f(x)) < tol){
            std::cout <<"[FIXED POINT ITERATION METHOD] Number of iterations: " <<n <<std::endl;
            return x;
        }
        else{
            x = g(x);
        }
        n++;
    }
    std::cout <<"[FIXED POINT ITERATION METHOD] Number of iterations: " <<n <<std::endl;
    return x;
}

int main()
{
    double xf0 = Fixed(f, g0, 1, 1e-5, 100);
    double xf1 = Fixed(f, g1, 1, 1e-5, 100);
    std::cout <<"Root found using g(x)=g0 fixed point iteration method is " <<xf0 <<std::endl;
    std::cout <<"Root found using g(x)=g1 fixed point iteration method is " <<xf1 <<std::endl;
    /*
    when g(x) = sqrt(3 + 4*exp(-x)) method converges
    when g(x) = -log((3 - pow(x,2))/-4) method fails to converge because log function is defined
    on positive numbers and initially if we choose x0 = 1 we have -log(-1/2) which is undefined. 
    this is why program outputs nan as well.
    */

}
/*
    OUTPUT
    [FIXED POINT ITERATION METHOD] Number of iterations: 100
    [FIXED POINT ITERATION METHOD] Number of iterations: 8
    Root found using g(x)=g0 fixed point iteration method is nan
    Root found using g(x)=g1 fixed point iteration method is 1.89733
*/