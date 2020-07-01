#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,n,c,temp,j;
	printf("enter the number of items:");
	scanf("%d",&n);
	printf("enter the capacity:");
	scanf("%d",&c);
	int p[n],w[n];
	for(i=0;i<n;i++){
		printf("enter the profit and weight[%d]:",i+1);
		scanf("%d%d",&p[i],&w[i]);
	}
	
	float r[n];
	for(i=0;i<n;i++){
		r[i]=(float)p[i]/w[i];
	}
	for(i=0;i<n;i++){
		
		printf("%d %d\t %f\n",p[i],w[i],r[i]);
	}
	float t;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(r[i]<r[j]){
				t=r[i];
				r[i]=r[j];
				r[j]=t;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				temp=w[i];
				w[i]=w[j];
				w[j]=temp;
			}
		}
	}
	/*for(i=0;i<n;i++){
		
		printf("%d %d\t %f\n",p[i],w[i],r[i]);
	}*/
	printf("\n");
	float pro=0.00;float f;
	for(i=0;i<n;i++){
		if(w[i]<c && c>0){
			
			c=c-w[i];
			pro=pro+(float)p[i];
		}
		else{
			f=(float)c/w[i]; 
            pro=pro+(float)p[i]*f ;
            c= (int)(c-(w[i]*f)); 
			break;
		}
	}
	printf("profit is %f ",pro);
	return 0;
	
}