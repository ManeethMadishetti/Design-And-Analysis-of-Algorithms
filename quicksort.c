#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int l,int h){
    int pivot=a[l],temp;
    int i=l,j=h;
    while(i<j){
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}


void quicksort(int a[],int l,int h){
    if(l<h){
        int j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}

void main(){
    int n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter elements of the array\n");
    for(int i=0;i<n;i++){
        printf("Enter element-%d\n",i+1);
        scanf("%d",&a[i]);
    }
    a[n]=32767;
    quicksort(a,0,n);
    printf("Elements of array after sorting are:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}