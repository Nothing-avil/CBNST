#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int n; 
	float coe;
	printf("Enter number of variables of equation: ");
	scanf("%d", &n);
	float arr[n+1][n+1];
	float res[n+1];
	for(int i=1; i<=n; i++){
		printf("Enter x, y, z and constant: ");
		for(int j=1; j<=n+1; j++){
			scanf("%f", &arr[i][j]);
		}
	}
	for(int i=1;i<=n-1;i++){
		
		for(int j=i+1;j<=n;j++){
		   coe = arr[j][i]/arr[i][i];
		   for(int k=1;k<=n+1;k++)
		   {
		  		arr[j][k] = arr[j][k] - coe*arr[i][k];
		   }
		}
	}
	res[n] = arr[n][n+1]/arr[n][n];
	for(int i=n-1;i>=1;i--)
	{
	  res[i] = arr[i][n+1];
	  for(int j=i+1;j<=n;j++)
	  {
		res[i] = res[i] - arr[i][j]*res[j];
	  }
	  res[i] = res[i]/arr[i][i];
	}
	printf("\nSolution:\n");
	for(int i=1;i<=n;i++)
	{
		printf("res[%d] = %f\n",i, res[i]);
	}
	return 0;
}
