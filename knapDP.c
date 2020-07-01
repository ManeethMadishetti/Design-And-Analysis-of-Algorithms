#include<stdio.h>
#include<stdlib.h>
typedef struct knap{
	int weight,profit;
}knap;

void knapDp(int n,knap arr[],int c)
{
	int mat[n+1][c+1],wi,pro,curr,prev;
	
	for(int i=0;i<=c;i++)
		mat[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		wi=arr[i-1].weight;
		pro=arr[i-1].profit;
		for(int j=0;j<=c;j++)
		{
			if(wi<=j)
			{
				if(pro+mat[i-1][j-wi]>mat[i-1][j])
					mat[i][j]=pro+mat[i-1][j-wi];
				else
					mat[i][j]=mat[i-1][j];
			}
			else mat[i][j]=mat[i-1][j];
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=c;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	int *sel=(int*)calloc(n,sizeof(int));
	 wi=c;
	 int i=n;
	 while(i>0 && wi>0)
	 {
		 if(mat[i][wi]==mat[i-1][wi])
			 i=i-1;
		 else
		 {
			 sel[i-1]=1;
			 wi=i;
			 i=i-1;
			 
		 }
	 }
	 printf("The Selected Items Are:< ");
	for(int ij=0;ij<n;ij++)
		printf("%d , ",sel[ij]);
	printf(">");
			
	
}


int main()
{
	int n,c;
	printf("Enter the Number of items:");
	scanf("%d",&n);
	knap arr[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the Weight and Profit of Item %d:",i+1);
		scanf("%d%d",&arr[i].weight,&arr[i].profit);
	}
	printf("Enter the KnapCapacity:");
	scanf("%d",&c);
	printf("Item No   Weight   Profit\n");
	for(int i=0;i<n;i++)
	{
		printf("%d   %d   %d\n",i+1,arr[i].weight,arr[i].profit);
		
	}
	knapDp(n,arr,c);
	return 0;	
}
	