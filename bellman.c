#include<stdio.h>
#include<stdlib.h>
#define Infinity 10000

void bellman(int n,int graph[n][n],int ed,int edges[ed][2],int start)
{
	int cost[n];
	for(int i=0;i<n;i++)
		cost[i]=Infinity;
	cost[start]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<ed;j++)
		{
			int u=edges[j][0],v=edges[j][1];
			if(cost[u]+graph[u][v]<cost[v])
				cost[v]=cost[u]+graph[u][v];
		}
	}
	int x=1;                                                       
	for(int j=0;j<ed;j++)
		{
			int u=edges[j][0],v=edges[j][1];
			if(cost[u]+graph[u][v]<cost[v])
				x=0;
		}
	if(x==1)
	{
		printf("There Are No Negative Cycles\n");
	}
	else
		printf("Negative Cycle Detected\n");
		
	for(int i=0;i<n;i++)
           printf("Vertex %d -> cost = %d \n",i,cost[i]);
}

int main(){
	int n,t,start;
	printf("Enter Number of Vertices: ");
	scanf("%d",&n);
	printf("ENter the Adj matrices:\n");
	int x=(n*(n-1))/2;
	int graph[n][n],ed=0,edges[x][2];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&t);
			graph[i][j]=t;
			if(t!=0)
			{
				edges[ed][0]=i;
				edges[ed][1]=j;
				ed=ed+1;
			}
				
		}
	}
	printf("Enter the Starting Node:");
	scanf("%d",&start);
	bellman(n,graph,ed,edges,start);
}
/*
0 -1 4 0 0
0 0 3 2 2
0 0 0 0 0
0 1 5 0 0
0 0 0 -3 0

*/




