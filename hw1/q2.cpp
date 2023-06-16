// MERT KARAKAYA 090210362
#include <iostream>
#include <cmath>

double f(double x)
{
    return -pow(x,4) + 3*pow(x,2) + 2;
}

double df(double x)
{
    return -4*pow(x,3) + 6*x;
}

double Newton(double (*f)(double), double (*df)(double), double x0, double tol, int iter)
{
    double x = x0;
    int n = 0;
    while (n < iter)
    {
        if (fabs(f(x)) < tol){
            std::cout <<"[NEWTON METHOD] Number of iterations: " <<n <<std::endl;
            return x;
        }
        else
            x = x - (f(x) / df(x));
        n++;
    }
    std::cout <<"[NEWTON METHOD] Number of iterations: " <<n <<std::endl;
    return x;
}

int main()
{
    double xa = Newton(f, df, 1.224744871391589, 1e-5, 1000);
    std::cout <<"Root found using newton method is " <<xa <<std::endl;
    double xb = Newton(f, df, -1.3, 1e-5, 100);
    std::cout <<"Root found using newton method is " <<xb <<std::endl;
    double xc = Newton(f, df, 1.6, 1e-5, 100);
    std::cout <<"Root found using newton method is " <<xc <<std::endl;
    /*
    d şıkkı: newton yöntemi için bu üç x0 noktaları arasından en kötü seçenek
    a şıkkındaki x0mış. çünkü aralarında kökü bulabilmek için en fazla iterasyon
    adım sayısına bu x0 ihtiyaç duydu, 127 adımda kökü bulabildi. sonraki kötü
    olan x0 b şıkkı çünkü 9 adımda kökü bulabildi. en iyi x0 ise c şıkkındaki x0
    5 adımda köke ulaştı.
    */
    
}

/*
    OUTPUT
    [NEWTON METHOD] Number of iterations: 127
    Root found using newton method is -1.88721
    [NEWTON METHOD] Number of iterations: 9
    Root found using newton method is -1.88721
    [NEWTON METHOD] Number of iterations: 5
    Root found using newton method is 1.88721
*/