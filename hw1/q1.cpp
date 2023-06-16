// MERT KARAKAYA 090210362
#include <iostream>
#include <cmath>

double f(double x)
{
    return exp(-2*x)*x + x*cos(x) -4*sin(2*x);
}

double Bisection(double (*f)(double), double a, double b, double tol, int iter)
{
    double c;
    int n=0;
    while (n < iter){
        c = (b + a) / 2;

        if (fabs(f(c)) <= tol){
            std::cout <<"[BISECTION METHOD] Number of iterations: " <<n <<std::endl;
            return c;
        }
        else if (f(c)*f(a) < 0){
            b = c;
        }
        else{
            a = c;
        }
        n++;
    }
        
    std::cout <<"[BISECTION METHOD] Number of iterations: " <<n <<std::endl;
    return c;
}

double RegulaFalsi(double (*f)(double),double a, double b, double tol, int iter)
{
    double w;
    int n = 0;
    while (n < iter){
        w = (b*f(a) -a*f(b)) / (f(a) - f(b));
        if (fabs(f(w)) < tol){
            std::cout <<"[REGULA FALSI METHOD] Number of iterations: " <<n <<std::endl;
            return w;
        }
        else if (f(a)*f(w) < 0)
            b = w;
        else
            a = w; 
        n++;
    }
    std::cout <<"[REGULA FALSI METHOD] Number of iterations: " <<n <<std::endl;
    return w;
}

int main()
{
    double biRoot = Bisection(f, 1, 2, 1e-5, 100);
    std::cout <<"Root found using bisection method is " <<biRoot <<std::endl;
    
    double regRoot = RegulaFalsi(f, 1, 2, 1e-5, 100);
    std::cout <<"Root found using regula falsi method is " <<regRoot;

}

/*
    OUTPUT
    [BISECTION METHOD] Number of iterations: 17
    Root found using bisection method is 1.5601
    [REGULA FALSI METHOD] Number of iterations: 3
    Root found using regula falsi method is 1.5601
*/