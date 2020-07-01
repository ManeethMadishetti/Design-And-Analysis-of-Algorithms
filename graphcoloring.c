#include<stdio.h> 
#include<stdbool.h> 
  
#define V1 20 
int count;  
void printSolution(int V, int color[]); 
bool isSafe (int v,int V, bool graph[V1][V1], int color[], int c) 
{ 
    for (int i = 0; i < V; i++) 
        if ((graph[v][i] || graph[i][v]) && c == color[i] ) 
            return false; 
    return true; 
} 
  
bool graphColoringUtil(int V,bool graph[V1][V1], int m, int color[], int v) 
{ 
    if (v == V) 
    {
        printSolution(V, color);   
        return true; 
    }
	
    for (int c = 1; c <= m; c++) 
    {
        for (int j = v; j < V; j++) 
            color[j] = 0;
        if (isSafe(v, V, graph, color, c)) 
        { 
           color[v] = c; 
           if (graphColoringUtil (V, graph, m, color, v+1) == false) 
             color[v]=0; 
        } 
    } 
  
    return false; 
} 
  
bool graphColoring(int V, bool graph[V1][V1], int m) 
{ 
    int color[V]; 
    for (int i = 0; i < V; i++) 
       color[i] = 0; 
  
    if (graphColoringUtil(V, graph, m, color, 0) == false) 
    {
        if(count==0)
            printf("\n\nSolution does not exist\n\n"); 
      return false; 
    } 
  
    return true; 
} 
  
void printSolution(int V, int color[]) 
{   
    if(count==0)
    printf("The Colouring possibilites are:\n");
    ++count; 
    for (int i = 0; i < V; i++) 
      printf("%d\t", color[i]); 
    printf("\n"); 
} 
int main() 
{ 
    int i,j,m,V;
    printf("The maximum possible colours that can be assinged are :");
    scanf("%d",&m);
    printf("enter number of vertices :");
    scanf("%d",&V);
    /*bool graph[V][V] = {{0, 1, 0, 0}, 
        {0, 0, 1, 0}, 
        {0, 0, 0, 1}, 
        {1, 0, 0, 0}, 
    };*/
    bool graph[V1][V1];
    printf("enter the graph matrix :\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        scanf("%d",&graph[i][j]);
    }
    graphColoring (V, graph, m); 
    printf("%d solutions available\n",count);
    return 0; 
}