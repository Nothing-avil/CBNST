#include <stdio.h>
#include<math.h>

double f(double x){
    return (x*x*x - 2*x - 4);
}

double g(double x){
	return pow((2*x*x+4), (1/3));
}

double h(double x){
	return (4*x*pow((2*x*x+4), (-2/3)))/3;
}

int i=0;

void iteration(double a){
    double r = f(a), x;
    i++;
    printf("\nIteration no : %d,value of x is : %lf , value at current iteration is : %lf \n", i,a, r);

    x = g(a);
    if(fabs(x-a)<=0.0001){
        printf("\n\nThe root of given Equation is -  %lf \n", a);
        printf("Steps are - %d \n", i);
        return;
    }
    
    iteration(x);
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
        m=(a+b)/2;
        if(fabs(h(a))<1 && fabs(h(b))<1 && fabs(h(m))<1){
            printf("Roots are accepted.\n");
            z=0;
        }
        else{
            printf("Invalid Roots ,Please Enter Correct values.\n");
        }
    }while(z);
    iteration(m);
    return 0;
}
