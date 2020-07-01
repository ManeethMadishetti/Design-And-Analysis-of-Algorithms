#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int board[20],count;

int place(int row,int col)
{
	for(int i=1;i<=row-1;i++)
	{
		if(board[i]==col)
			return 0;
		else
			if(abs(board[i]-col)==abs(i-row))
				return 0;
	}
	return 1;
	
}
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);
 
 for(i=1;i<=n;++i)
  printf("\t%d",i);
 
 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) //for nxn board
  {
   if(board[i]==j)
    printf("\tQ"); //queen at i,j position
   else
    printf("\t-"); //empty slot
  }
 }
}
void queen(int row,int n)
{
	for(int col=1;col<=n;col++)
	{
		if(place(row,col))
		{
			board[row]=col;
			if(row==n)
				print(n);
			else
				queen(row+1,n);
		}
		
	}
}

int main()
{
	int n;
	printf("Enter N: ");
	scanf("%d",&n);
	if(n<=3)
		printf("Not Possible");
	else
		queen(1,n);
	return 0;
}