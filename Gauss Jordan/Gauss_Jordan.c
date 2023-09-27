#include<stdio.h>
#include<conio.h>
#include<math.h>

#define SIZE 20

int main()
{
	 double arr[SIZE][SIZE], x[SIZE], ratio;
	 int i,j,k,n;

	 /* Reading number of unknowns */
	 printf("Enter number of unknowns: ");
	 scanf("%d", &n);
	 /* Reading Augmented Matrix */
	 printf("Enter coefficients of Augmented Matrix:\n");
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   printf("arr[%d][%d] = ",i,j);
			   scanf("%lf", &arr[i][j]);
		  }
	 }
	 /* Applying Gauss Jordan Elimination */
	 for(i=1;i<=n;i++)
	 {
		  if(arr[i][i] == 0.0)
		  {
			   printf("Mathematical Error!");
			   exit(0);
		  }
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
				    ratio = arr[j][i]/a[i][i];
				    for(k=1;k<=n+1;k++)
				    {
				     	arr[j][k] = arr[j][k] - ratio*arr[i][k];
				    }
			   }
		  }
	 }
	 /* Obtaining Solution */
	 for(i=1;i<=n;i++)
	 {
	  	x[i] = arr[i][n+1]/a[i][i];
	 }
	 /* Displaying Solution */
	 printf("\nSolution of given Equations:\n");
	 for(i=1;i<=n;i++)
	 {
	  	printf("x[%d] = %0.6lf\n",i, x[i]);
	 }
	 return(0);
}
