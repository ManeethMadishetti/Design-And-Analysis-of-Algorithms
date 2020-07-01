#include<stdio.h>
#include<stdlib.H>
#include<limits.h>

void printOptimal(int n,int s[n][n],int i,int j){
	if(i==j){
		printf("A%d",i);

	}
	else{
		printf("(");
	
		printOptimal(n,s,i,s[i][j]);
		printOptimal(n,s,(s[i][j])+1,j);	
		printf(")");
	}
	
}
		
int matmul(int p[],int n){
	int c[n][n];int m,i,j,k;
	for(i=1;i<n;i++){
		c[i][i]=0;	
	}
	int s[n][n];
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			printf("%d  ",c[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
	for(i=0;i<n;i++){
			printf("%d  ",p[i]);	
	}
	printf("\n");
	printf("-------------------\n");
	int length=2;
	for(length=2;length<n;length++){
		for(i=1;i<n-length+1;i++){
			j=i+length-1;
			c[i][j]=INT_MAX;
			for(k=i;k<j;k++){
				m=c[i][k]+c[k+1][j]+(p[i-1]*p[j]*p[k]);
				if(m<c[i][j]){
					c[i][j]=m;
					if(s[i][j]!=k)
					s[i][j]=k;
				}
			}
			printf("%d ",c[i][j]);
		}
	}
	printf("\n");
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if(i>j){
				printf("0 ");
			}
			else{
				printf("%d  ",c[i][j]);
			}
		}
		printf("\n");
	}
	
	printOptimal(n,s,1,n-1);
	printf("\n");
	return c[1][n-1];
}		


int main(){
	int i,n;
	printf("enter the number:");
	scanf("%d",&n);
	int p[n];
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	int result=matmul(p,n);
	printf("%d",result);
	return 0;
}

