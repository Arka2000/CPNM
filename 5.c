/*  This is an program to find the ROOTS of an equation by GAUSS ELIMINATION METHOD
   
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*Gauss Elimination method is appicalbe for a non singular matrix
  In this method first we make a upper Triangular matrix the we use 
  the Backsubstitution method to get the required values(roots)
*/
int main()
{
	int n;
	printf("Enter the order of the matrix:");
	scanf("%d",&n);
	
	float arr[n][n+1], out[n];
	int i,j,k;
	float f;
	printf("Enter the augmented matrix:\n");
	for(i=1; i<=n; i++)	// here we take input of the required matrix
	{
		for(j=1; j<=n+1; j++)
		{
			scanf("%f",&arr[i][j]);
		}
	}
	
	FILE *fp;	
	fp=fopen("5.txt","w");
	int it=1;
	
	for(k=1; k<=n; k++,it++)	 /* loop for the generation of upper triangular matrix*/
	{fprintf(fp,"Iteration:%d\n",it);
		for(i=k+1; i<=n; i++)
		{
			f=arr[i][k]/arr[k][k];
			for(j=k+1; j<=n+1; j++)
			{
				arr[i][j]-=f*arr[k][j];
			}
			arr[i][k]=0;
		}
		
		for (int i=1; i<=n; i++, fprintf(fp,"\n")) 
        	for (int j=1; j<=n+1; j++) 
        	    fprintf(fp,"%f ", arr[i][j]); 
  
   		 fprintf(fp,"\n"); 
	}
	fprintf(fp,"\nMatrix in Echelon Form\n");
	
	for (int i=1; i<=n; i++, fprintf(fp,"\n")) 
        for (int j=1; j<=n+1; j++) 
            fprintf(fp,"%f ", arr[i][j]); 
  
    	fprintf(fp,"\n"); 

	
	
	for(i=n; i>=1; i--)	/* this loop is for backward substitution*/
	{
		out[i]=arr[i][n+1];
		for(j=i+1; j<=n; j++)
		{
			out[i]-=arr[i][j]*out[j];
		}
		out[i]=out[i]/arr[i][i];
	}
	
	
	fprintf(fp,"\nThe solution of the equations\n");
	
	for(i=1; i<=n; i++)	/* x1, x2, x3 are the required solutions*/
	{
		fprintf(fp,"x%d = %f\n",i,out[i]);
	}

	return 0;
}
