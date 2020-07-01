#include<stdio.h>
#include<stdlib.h>


void mearge(int a[],int start,int mid,int end)
{
	int n1=mid-start+1,n2=end-mid;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)
		L[i]=a[start+i];
	
	for(int i=0;i<n2;i++)
		R[i]=a[i+mid+1];

	int i=0,j=0,k=start;
	while(i<n1&&j<n2)
		if(L[i]<=R[j])
			a[k++]=L[i++];
		else
			a[k++]=R[j++];
	while(i<n1)  a[k++]=L[i++];
	while(j<n2)  a[k++]=R[j++];
}

void meargeSort(int a[],int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		meargeSort(a,start,mid);
		meargeSort(a,mid+1,end);
		mearge(a,start,mid,end);
	}
			
}
int main()
{
	int n;
	printf("Enter N:");
	scanf("%d",&n);
	int arr[n];
	printf("\n Enter The %d Intergers:",n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	printf("\nThe Array Before Sorting:");
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	
	meargeSort(arr,0,n);
	
	printf("\nThe Array After Sorting:");
	for(int i=0;i<n;i++) printf("%d ",arr[i]);
	
}