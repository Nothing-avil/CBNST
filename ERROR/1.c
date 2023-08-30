#include<stdio.h>
int main(){
	double x, y, Ea, Er, Ep;
	printf("Enter the X: ");
	scanf("%lf", &x);
	printf("Enter the X': ");
	scanf("%lf", &y);
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
