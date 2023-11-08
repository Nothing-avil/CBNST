#include<stdio.h>
int main(){
  int n;
  printf("Enter the number of intervals: ");
  scanf("%d", &n);
  float x[n], y[n], X, product, sum=0;
  printf("Enter the values of X: ");
  for(int i=0; i<n; i++){
    scanf("%f", &x[i]);
  }
  printf("Enter the values of Y: ");
  for(int i=0; i<n; i++){
    scanf("%f", &y[i]);
  }
  printf("Enter the value of X for the value of Y: ");
  scanf("%f", &X);
  for(int i=0; i<n; i++){
    product=1;
    for(int j=0; j<n; j++){
      if(i!=j){
        product= product*((X-x[j])/(x[i]-x[j]));
      }
    }
    sum= sum + product*y[i];
  }
  printf("The value of X is %f and value of Y for that is %f: ", X, sum);
}
