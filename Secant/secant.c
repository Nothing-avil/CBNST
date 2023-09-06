#include <stdio.h>

double f(double x){
    return (x*x*x - 5*x + 1);
}

int i=0;

void secant(double a, double b){
    double m= b- ((b-a)/(f(b)-f(a)))*f(b);
    double r=  f(m);
    printf("The Roots are %lf  , %lf  and the  values of x, f(x) are %lf  , %lf \n", a, b, m,r);
    i++;
    
    if(m-a<=0.0001 || b-m<=0.0001){
        printf("\n\nThe root of given Equation is -  %f \n", m);
        printf("Steps are - %d \n", i);
        return;
    }
    
    if(f(a)*f(m)<0){
        secant(a,m);
    }
    else if(f(m)*f(b)<0){
        secant(m,b);
    }
}

int main()
{
    double a, b, m;
    int z=1;
    printf("The equation is =  x^3 - 4*x - 9. \n");

    do{
        printf("Enter the first root = ");
        scanf("%lf", &a);
    
        printf("Enter the second root = ");
        scanf("%lf", &b);
        if(f(a)*f(b)<0){
            printf("Roots are accepted.\n");
            z=0;
        }
        else{
            printf("Invalid Roots ,Please Enter Correct values.\n");
        }
    }while(z);
    secant(a,b);
    return 0;
}
