#include<stdio.h>
#define Infinity 10000

int main()
{
	int n,t;
	printf("Enter Number of Vertices of the GRAPH:");
	scanf("%d",&n);
	int graph[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&t);
			if(t==0)
			if(i==j)
				graph[i][j]=0;
			else
				graph[i][j]=10000;
			else
				graph[i][j]=t;
		}
	}
	
	printf("\n++++++++++++++++++++++++++++++\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d  ",graph[i][j]);
		}
		printf("\n");
	}
	printf("\n++++++++++++++++++++++++++++++\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(graph[i][k]+graph[k][j]<graph[i][j])
				{
					graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}
	printf("\n++++++++++++++++++++++++++++++\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d  ",graph[i][j]);
		}
		printf("\n");
	}
	printf("\n++++++++++++++++++++++++++++++\n");
	return 0;
}
/*
0 1 0 1 0
0 0 2 0 0
3 0 0 0 3
0 0 4 0 4
5 5 0 0 0

0 5 0 2 0
0 0 2 0 0
3 0 0 0 7
0 0 4 0 1
1 3 0 0 0
*/