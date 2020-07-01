#include<stdio.h>
#include<stdlib.h>
#define Infinity 10000

int selectedall(int *sel,int n)
{
	for(int i=0;i<n;i++) 
	{
	if(sel[i]==0)
		return 0;
	}
	return 1;
}

void dijistra(int n,int graph[n][n],int start)
{
	int *sel=(int*) calloc(n,sizeof(n));
	int *pred=(int*) calloc(n,sizeof(n));
	
	int *curr=(int*) calloc(n,sizeof(n));
	int min=Infinity,idx=start;
	
	for(int i=0;i<n;i++)
	{
		curr[i]=graph[start][i];
		if(min>curr[i])
		{
			min=curr[i];
			idx=i;
		}
	}
	sel[start]=1;
	curr[start]=0;
	int c=0;
	sel[idx]=1;
	while(c<n-1){
		
		printf("The minimum is %d at %d index\n",min,idx);
		for(int i=0;i<n;i++)
		{
			printf("%d ",curr[i]);
		}
		printf("\n");
			
		for(int i=0;i<n;i++)
		{
			if(sel[i]==1) continue;
			if(min+graph[idx][i]<curr[i])
			{
				curr[i]=min+graph[idx][i];
				pred[i]=idx;
			}
		}
		min=Infinity;//for new minim`
		for(int i=0;i<n;i++)
		{
			if(sel[i]==1) continue;
			if(min>curr[i])
			{
				min=curr[i];
				idx=i;
			}
		}
		sel[idx]=1;
		c++;
		
	}
	for(int i=0;i<n;i++)
	{
		if(i!=start){
			
			printf("\nDistance of Node %d is %d ",i,curr[i]);
			printf("\nPath=%d",i);
			
			int j=i;
			do{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=start);
		}
	}		
	
}

int main(){
	int n,t,start;
	printf("Enter Number of Vertices: ");
	scanf("%d",&n);
	printf("ENter the Adj matrices");
	int graph[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&t);
			if(t==0)
				graph[i][j]=Infinity;
			else
				graph[i][j]=t;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		    if(graph[i][j]==Infinity)
		    {
		        printf("%c ",236);
		    }
		    else
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	printf("Enter the Starting Node:");
	scanf("%d",&start);
	//graph[start][start]=0;
	dijistra(n,graph,start);
}
/*
0 10 0 30 100                       
10 0 50 0 0                                               
0 50 0 20 10                                              
30 0 20 0 60                                              
100 0 10 60 0

*/




