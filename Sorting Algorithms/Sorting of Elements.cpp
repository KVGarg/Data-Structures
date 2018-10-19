#include<iostream>
#include<conio.h>
using namespace std;
int binary(int arr[],int l,int r,int a);
int main()
{
	int n,choice;
	cout<<"Enter no. of Elements: ";
	cin>>n;
	system("cls");
	int arr[n];
	cout<<"Enter Elements: "<<endl;
	for(int count=0;count<n;count++)
	{
		cout<<"Element no."<<count+1<<"=";
		cin>>arr[count];
	}
	system("cls");
	//Unsorted array
	cout<<endl<<"Non Sorted Array:";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	
	system("cls");
	cout<<"Sort Array Using: "<<endl;
	cout<<"1. Bubble Sort "<<endl;
	cout<<"2. Insertion Sort "<<endl;
	cout<<"3. Selection Sort "<<endl;
	cout<<endl<<"Enter Choice No. ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			//Bubble Sorting 
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n-1;j++)
				{
					if(arr[j+1]<arr[j])
					{
						int temp=arr[j+1];
						arr[j+1]=arr[j];
						arr[j]=temp;
					}
				}
				//On every pass displays result
				cout<<endl<<"Pass "<<i+1<<": ";
				for(int i=0;i<n;i++)
				cout<<arr[i]<<" ";
			}
			//Sorted Array
			cout<<endl<<"Sorted Array:";
			for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
			break;
		case 2:	
			//Insertion Sort Algo
			for(int i=1;i<n;i++)
			{
				bool b=true;
				int j=0;
				int element=arr[i];
				while(b=true && j<=i)
				{
					if(arr[j]>arr[i])
					{
						for(int k=i;k>j;k--)
						{
							arr[k]=arr[k-1];
						}
						arr[j]=element;
						b==false;
					}
					j++;
				}
				//Every Pass Result
				cout<<endl<<"Pass "<<i<<": ";
				for(int k=0;k<n;k++)
				cout<<arr[k]<<" ";		
			}
			//Sorted array
			cout<<endl<<endl<<"Sorted Array: ";
			for(int k=0;k<n;k++)
			cout<<arr[k]<<" ";
			break;
		case 3:
			//Selection Sort Algo
			for(int i=0;i<n;i++)
			{		
				for(int j=i;j<n;j++)
				{
					if(arr[i]>arr[j])
					{
						int temp=arr[i];
						arr[i]=arr[j];
						arr[j]=temp;
				
					}	
					cout<<endl;
					for(int k=0;k<n;k++)
					cout<<arr[k]<<" ";		
				}
				cout<<"\n--------\n";
			}
			break;
		default:
			cout<<"Enter Correct Option";
			fflush(stdin);
	}
	
LOOP:	cout<<endl<<endl<<"Enter Element u want to search: ";
	int no,i=0,j=0;
	cin>>no;
	int index;
	index=binary(arr,0,n,no);
	if(index==-1)
	cout<<"Element Not Present"<<endl<<endl;
	else
	cout<<"Index: "<<index<<" and Position: "<<index+1<<endl<<endl;
	cout<<" Press (1) for Another Search, (2) for New Array and (3) for Exit"<<endl;	
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1:
			fflush(stdin);
			goto LOOP;
		case 2:
			system("cls");
			fflush(stdin);
			main();
		case 3:
			break;
		default:
			cout<<"Enter Correct Option";
			fflush(stdin);
	}		
	
}
int binary(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2; 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid; 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binary(arr, l, mid-1, x); 
        // Else the element can only be present in right subarray
        return binary(arr, mid+1, r, x);
   }
   // We reach here when element is not present in array
   return -1;
}


