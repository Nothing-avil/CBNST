#include <stdio.h>
#include<math.h>
double f(double x){
    return (x*x*x - 4*x - 9);
}

double df(double x){
	return (3*x*x-4);
}

int i=0;

void Newton_Raphson(double a){
    double r = f(a), x;
    i++;
    printf("\nIteration no : %d,value of x is : %lf , value at current iteration is : %lf \n", i,a, r);

    if(df(a)!=0){
    	x = a - (f(a)/df(a));
    }
    if(fabs(x-a)<=0.0001){
        printf("\n\nThe root of given Equation is -  %lf \n", a);
        printf("Steps are - %d \n", i);
        return;
    }
    
    Newton_Raphson(x);
}

int main()
{
    double a, b, l;
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
    l=(a+b)/2;
    Newton_Raphson(l);
    return 0;
}
