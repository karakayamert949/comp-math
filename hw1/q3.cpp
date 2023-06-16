// MERT KARAKAYA 090210362
#include <iostream>
#include <cmath>
#include <ctime>
#include <bits/stdc++.h>

double f1(double x)
{
    return pow(x,3) - 2*x - 5;
}

double f2(double x)
{
    return cos(2*x) - pow(x,3);
}

double f3(double x)
{
    return exp(x) - pow((x - 3),2);
}

double df1(double x)
{
    return 3*pow(x,2) - 2;
}

double df2(double x)
{
    return -2*sin(2*x) -3*pow(x,2);
}

double df3(double x)
{
    return exp(x) -2*(x-3);
}


double Newton(double (*f)(double), double (*df)(double), double x0, double tol, int iter)
{
    double x = x0;
    int n = 0;
    while (n < iter)
    {
        if (fabs(f(x)) < tol){
            return x,n;
        }
        else
            x = x - (f(x) / df(x));
        n++;
    }
    return x,n;
}

double Secant(double (*f)(double), double x0, double x1, double tol, int iter)
{
    double x=x1;
    int n = 0;
    while (n < iter)
    {
        if (fabs(f(x)) < tol)
        {
            return x,n;
        }
        else
        {
            x = (x0*f(x1) - x1*f(x0)) / (f(x1) - f(x0));
        }
        x0=x1;
        x1=x;
        n++;
    }
    return x,n;
}

double Muller(double (*f)(double), double x0, double x1, double x2, double tol, int iter) {
    double h1 = x1 - x0;
    double h2 = x2 - x1;
    double delta1 = (f(x1) - f(x0)) / h1;
    double delta2 = (f(x2) - f(x1)) / h2;
    double d = (delta2 - delta1) / (h2 + h1);
    double a = d;
    double b = delta2 + h2 * d;
    double c = f(x2);
    double x;
    double x3;

    int n = 0;

    while (n < iter) {
        double disc = b*b - 4*a*c;
        double sqrtd = sqrt(disc);
        double denom = (b > 0) ? (b + sqrtd) : (b - sqrtd);
        x3 = x2 - (2*c) / denom;
        x = x3;

        if (fabs(f(x3)) < tol) {
            return x3,n;
        }

        x0 = x1;
        x1 = x2;
        x2 = x3;

        h1 = x1 - x0;
        h2 = x2 - x1;
        delta1 = (f(x1) - f(x0)) / h1;
        delta2 = (f(x2) - f(x1)) / h2;
        d = (delta2 - delta1) / (h2 + h1);
        a = d;
        b = delta2 + h2 * d;
        c = f(x2);

        n++;
    }
    return x3,n;
}

template<typename F, typename... Args>
double getCpuTime(F func, Args ... args)
{
    clock_t start, end;

    start = clock();
    double x;
    for (int i = 0; i < 1e6; i++) {
        func(args...);
    }
    end = clock();
    double t = double(end-start) / double(1e6*CLOCKS_PER_SEC);
    return t;
}

int main()
{
    std::cout << std::setprecision(10);
    double xn1,nn1 = Newton(f1, df1, 1, 1e-5, 100);
    double xn2,nn2 = Newton(f2, df2, 1, 1e-5, 100);
    double xn3,nn3 = Newton(f3, df3, 1, 1e-5, 100);

    double xs1,ns1 = Secant(f1, 1, 1.5, 1e-5, 100);
    double xs2,ns2 = Secant(f2, 1, 1.5, 1e-5, 100);
    double xs3,ns3 = Secant(f3, 1, 1.5, 1e-5, 100);

    double xm1,nm1 = Muller(f1, 1, 1.5, 2, 1e-5, 100);
    double xm2,nm2 = Muller(f2, 1, 1.5, 2, 1e-5, 100);
    double xm3,nm3 = Muller(f3, 1, 1.5, 2, 1e-5, 100);

    double tn1=getCpuTime(&Newton,f1, df1, 1, 1e-5, 100);
    double tn2=getCpuTime(&Newton,f2, df2, 1, 1e-5, 100);
    double tn3=getCpuTime(&Newton,f3, df3, 1, 1e-5, 100);

    double ts1=getCpuTime(&Secant,f1, 1, 1.5, 1e-5, 100);
    double ts2=getCpuTime(&Secant,f2, 1, 1.5, 1e-5, 100);
    double ts3=getCpuTime(&Secant,f3, 1, 1.5, 1e-5, 100);

    double tm1=getCpuTime(&Muller,f1, 1, 1.5, 2, 1e-5, 100);
    double tm2=getCpuTime(&Muller,f1, 1, 1.5, 2, 1e-5, 100);
    double tm3=getCpuTime(&Muller,f1, 1, 1.5, 2, 1e-5, 100);

    std::cout <<"\nFunction 1\n              Convergence rate | CPU Time | Iteration Number"
    <<"\nNewton method" <<"          2         " <<tn1 << "          " <<nn1
    <<"\nSecant method" <<"          1,618     " <<ts1 << "          " <<ns1
    <<"\nMuller's method" <<"        1,819     " <<tm1 << "          " <<nm1;

    std::cout <<"\n\nFunction 2\n              Convergence rate | CPU Time | Iteration Number"
    <<"\nNewton method" <<"          2         " <<tn2 << "          " <<nn2
    <<"\nSecant method" <<"          1,618     " <<ts2 << "          " <<ns2
    <<"\nMuller's method" <<"        1,819     " <<tm2 << "          " <<nm2;

    std::cout <<"\n\nFunction 3\n              Convergence rate | CPU Time | Iteration Number"
    <<"\nNewton method" <<"          2         " <<tn3 << "          " <<nn3
    <<"\nSecant method" <<"          1,618     " <<ts3 << "          " <<ns3
    <<"\nMuller's method" <<"        1,819     " <<tm3 << "          " <<nm3;

    /*
    Yakinsama oranlarina gore genelde en hizli newton sonra muller sonra secant metodu seklinde
    yakinsamalarini bekliyordum.

    Newton metodunun yakinsama orani 3 metod arasinda en yuksek olmasina ragmen 
    1. fonksiyonda 8 adimla en yavas yakinsayan yontem oldu. 2. fonksiyonda 2. hizli yakinsayan
    yontem oldu. 3. fonksiyonda Muller fonksiyonuyla ayni adim sayisiyla
    Secanta gore hizla yakinsadi. Bu sonucun secilen ilk noktalarla ilgisi olabilir.

    Newton yontemi ile Muller yontemi CPU zamani acisindan birbirlerine yakin sonuc verdiler.
    Secant yontemi bu iki yonteme gore yavas calisti.
    */

}
/*
    OUTPUT
    Function 1
                Convergence rate | CPU Time | Iteration Number
    Newton method          2         1.665e-006          8
    Secant method          1,618     2.272e-006          7
    Muller's method        1,819     1.265e-006          2

    Function 2
                Convergence rate | CPU Time | Iteration Number
    Newton method          2         1.513e-006          4
    Secant method          1,618     2.8e-006          5
    Muller's method        1,819     1.241e-006          3

    Function 3
                Convergence rate | CPU Time | Iteration Number
    Newton method          2         6.79e-007          2
    Secant method          1,618     1.711e-006          3
    Muller's method        1,819     1.247e-006          2
*/