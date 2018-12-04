#include <stdio.h>


int main(){
int i,j,k,n;

float a[10][10],x[10],c;
scanf("%d",&n);
FILE* fp=fopen("j.txt","w");
for(i=1;i<=n;i++)
for(j=1;j<=n+1;j++)
scanf("%f",&a[i][j]);

for(j=1;j<=n;j++)
	{for(i=2;i<=n;i++)
	if(i>j)
	{
	c=a[i][j]/a[j][j];
	for(k=1;k<=n+1;k++)
	{
	a[i][k]-=c*a[j][k];
	}


	}

	}

	for(i=1;i<=n;i++)
	{for(j=1;j<=n+1;j++)
	fprintf(fp,"%f ",a[i][j]);

	fprintf(fp,"\n");
	
	}

float sum=0;
for(j=n;j>0;j--)
{
for(i=n-1;i>0;i--)
if(j>i)
{
c=a[i][j]/a[j][j];
for(k=1;k<=n+1;k++)
a[i][k]-=c*a[j][k];


}

}

	for(i=1;i<=n;i++)
	{for(j=1;j<=n+1;j++)
	fprintf(fp,"%f ",a[i][j]);

	fprintf(fp,"\n");
	
	}




/*x[n]=a[n][n+1]/a[n][n];
//printf("%f\n",x[n]);
for(i=n-1;i>0;i--){
sum=0;
for(j=i+1;j<=n;j++)
sum+=a[i][j]*x[j];
x[i]=a[i][n+1]-sum;
x[i]/=a[i][i];

}
for(i=1;i<=n;i++)
printf("%f\n",x[i]);
*/
for(i=1;i<=n;i++)
x[i]=a[i][n+1]/a[i][i];


for(i=1;i<=n;i++)
printf("%f\n",x[i]);
}
