package javaa;

import java.util.Scanner;
   
public class Hashing {


		
		public static void main(String[] args) {
		// TODO Auto-generated method stub
			int n,t,ele;
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter table size:");
			t=sc.nextInt();
			System.out.println("Enter number of elements:");
			n=sc.nextInt();
			int[] arr=new int[t];
			for (int i=0;i<t;i++)
				arr[i]=-1;
			System.out.println("Enter "+n+"element:");
			for (int i=0;i<n;i++)
			{
				ele=sc.nextInt();
				int in=ele%t;
				if(arr[in]==-1)
					arr[in]=ele;
				else
				{
					int j;
					for(j=in+1;j<t;j++)
					{
						if(arr[j]==-1)
						{ 
							arr[j]=ele;
							break;
						}
					}
					if(j==t)
					{
						for(j=0;j<in;j++)
						{
							if(arr[j]==-1)
							{ arr[j]=ele;
							break;
							}
			
						}
					}
			   }
			
			}
			System.out.println("::::::::::the Table you buid is:::::::::");
			for ( int i : arr)
				System.out.print(i+"\t");
			System.out.println();
			System.out.println("Enter element to be Searched:");
			ele=sc.nextInt();
			search(ele,t,arr);
			
			}
			
			private static void search(int ele, int t,int[] arr) {
			// TODO Auto-generated method stub
				int in=ele%t;
				if(arr[in]==ele)
				{
					System.out.println("Element found");
					return;
				}
				else
				{
					int j;
					for(j=in+1;j<t;j++)
					{
						if(arr[j]==ele)
						{
							System.out.println("Element found");
							return;
						}
					}
					if(j==t)
					{
						for(j=0;j<in;j++)
						{
						if(arr[j]==ele)
						{
							System.out.println("Element found");
							return;
						}
						}
					}
				}
				System.out.println("Element Not found");
			}
		
}
