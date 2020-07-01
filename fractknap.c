#include<stdio.h>
#include<stdlib.h>

typedef struct knap{
	int item,weight,profit;
	float pw;
}knap;

int main()
{
	int n,c;
	printf("Enter the Number of elements:");
	scanf("%d",&n);
	printf("Enter the KnapSack Capacity:");
	scanf("%d",&c);
	
	knap arr[n];
	for(int i=0;i<n;i++){
		printf("Enter the Weight & Profit of %d item",i+i);
		arr[i].item=i+1;
		scanf("%d%d",&arr[i].weight,&arr[i].profit);
		arr[i].pw=(float)arr[i].profit/arr[i].weight;
	}                      
	printf("Item No\t Weight\t Profit \t P/W\n");
	for(int i=0;i<n;i++)
	{
		printf("%d \t %d \t %d \t %f\n",arr[i].item,arr[i].weight,arr[i].profit,arr[i].pw);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j+1].pw>arr[j].pw)
			{
				knap temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	   
	printf("Item No\t Weight\t Profit \t P/W\n");
	for(int i=0;i<n;i++)
	{
		printf("%d \t %d \t %d \t %f\n",arr[i].item,arr[i].weight,arr[i].profit,arr[i].pw);
	}
	
	int i=0;float pro=0;
	float* sel=(float *)calloc(n,sizeof(float));
	while(c>0)
	{
		if(c>=arr[i].weight){
		c=c-arr[i].weight;
		pro=pro+arr[i].profit;
		sel[arr[i].item-1]=1;
		i++;
		}
		else {
			//c=c-arr[i].weight;
			pro=pro+arr[i].pw*c;
			sel[i]=(float)c/arr[i].weight;
			
			break;
		}
	}
	printf("Profit is:%f\n",pro);
	for(int i=0;i<n;i++)
	{
		printf("%f  ",sel[i]);
	}
	
	return 0;
}
	
		
		
	