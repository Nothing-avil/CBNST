#include<stdio.h>
double truncate(double n){
	int x;
	double y;
	x=n*(10e3);
	y=(double)x;
	y=y/10000;
	return y;
}
double round_off(double n){
	int x, z;
	double y;
	x=n*(10e4);
	z=x%10;
	if(z>5){
		x=x/10;
		x=x+1;
		y=(double)x;
		y=y/10000;
	}
	else if(z<5){
		x=x/10;
		y=(double)x;
		y=y/10000;
	}
	else{
		x=x/10;
		int a;
		a=x%10;
		if(a%2==0){
			x=x+1;
		}
		y=(double)x;
		y=y/10000;
	}
	return y;
}
int main(){
	double x, y, z, Ea, Er, Ep;
	printf("Enter the X: ");
	scanf("%lf", &x);
	y=truncate(x);
	printf("Enter the X'(Truncate): %lf\n", y);
	z=round_off(x);
	printf("Enter the X'(Round Off): %lf\n", z);
	Ea=x-y;
	if(Ea<0){
		Ea=-Ea;
	}
	Er=Ea/x;
	Ep=Er*100;
	printf("Truncate Absolute Error: %0.8lf\n", Ea);
	printf("Truncate Relative Error: %0.8lf\n", Er);
	printf("Truncate Percentage Error: %0.8lf\n", Ep);
	Ea=x-z;
	if(Ea<0){
		Ea=-Ea;
	}
	Er=Ea/x;
	Ep=Er*100;
	printf("Round Off Absolute Error: %0.8lf\n", Ea);
	printf("Round Off Relative Error: %0.8lf\n", Er);
	printf("Round Off Percentage Error: %0.8lf\n", Ep);
}
