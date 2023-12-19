#include<stdio.h>
#include<math.h>
#define f(x) (1/(1+(x*x)))
int main(){
  int n;
  float a, b, h;
  printf("Enter the number of Intervals = ");
  scanf("%d",&n);
  
  printf("Enter the value of a and b = ");
  scanf("%f%f",&a,&b);
  h = (b-a)/n;
  printf("%f %f %f\n",a, b, h);
  float sum=0;
  sum = f(a) + f(b);
  for(int i=1; i<n; i++){
    sum= sum+ 2*f((a+i*h));
  }
  sum = (sum*h)/2.0;
  printf("Answer: %f", sum);
}
