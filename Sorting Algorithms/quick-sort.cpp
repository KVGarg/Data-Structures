#include <iostream> 
using namespace std;  
  

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  

        int pi = partition(arr, low, high);  
   
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  

void display(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  

int main()  
{  
    int arr[10];  
    int n;
	cout<<"Enter the size of array: ";
	cin>>n;  
	cout<<"Enter the elements of array: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the index of element you want to pivot: ";
	int pivot;
	cin>>pivot;
	swap(&arr[pivot],&arr[n-1]);
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    display(arr, n);  
    return 0;  
}
