#include<stdlib.h> 
#include<stdio.h> 
#include<iostream>
using namespace std;
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2;  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
  
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<A[i]<<" "; 
    cout<<endl; 
} 
  
int main() 
{ 
    int arr[10];
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the elements: ";
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	 
     
  
    cout<<"Given array is: "<<endl; 
    printArray(arr, n); 
  
    mergeSort(arr, 0, n - 1); 
  
    cout<<endl<<"Sorted Array is: "<<endl; 
    printArray(arr, n); 
    return 0; 
} 
