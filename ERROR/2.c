#include<stdio.h>
double truncate(double n){
	int x;
	double y;
	x=n*(10e3);
	y=(double)x;
	y=y/10000;
	return y;
}
int main(){
	double x, y, Ea, Er, Ep;
	printf("Enter the X: ");
	scanf("%lf", &x);
	y=truncate(x);
	printf("Enter the X': %lf\n", y);
	Ea=x-y;
	if(Ea<0){
		Ea=-Ea;
	}
	Er=Ea/x;
	Ep=Er*100;
	printf("Enter the Absolute Error: %lf\n", Ea);
	printf("Enter the Relative Error: %lf\n", Er);
	printf("Enter the Percentage Error: %lf\n", Ep);
}
