package javaa;

import java.util.Arrays;
import java.util.Scanner;

public class Binary {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of elements:");
		int n=sc.nextInt();
		int arr[]=new int[n];
		System.out.println("Enter "+n+" numbers:");
		for (int i=0;i<n;i++)
			arr[i]=sc.nextInt();
		for (int i=0;i<n;i++)
			System.out.print(arr[i]+"\t");
		System.out.print("\nEnter element to search:");
		int ele=sc.nextInt();
		sc.close();
		Arrays.sort(arr);
		BinarySearch(arr,ele,0,n-1);

	}

	private static void BinarySearch(int[] arr, int ele, int front, int last) {
		if(front<=last)
		{
		
			int mid=(front+last)/2;
			//System.out.println(arr[mid]+".........."+mid);
			if(arr[mid]==ele)
			{
				System.out.println("Element found...");
				return;
			}
			else if(arr[mid]>ele)
			{
				BinarySearch(arr, ele, front, mid-1);
			}
			else
				BinarySearch(arr, ele, mid+1,last);
		}
		else
		{
			System.out.println("Element Not Found");
		}
		
	}

}
