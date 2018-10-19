#include <iostream>
using namespace std;

void countsort(int *arr, int n, int mul);

int getMax(int arr[], int n);

void radixsort(int* arr, int n, int max);

void print(int arr[], int n);


int main() {
	int no;
	cout<<"Enter Number of Elements: ";		cin>>no;
	int arr[no];
	
	for(int i=0;i<no;i++)
	cin>>arr[i];
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = getMax(arr,n);

    radixsort(arr, n,max);
    print(arr,n);
}

void countsort(int *arr, int n, int mul) {
    int freq[10] = {};  //this will contain the number of occurences of a digit,this is 10 as there can be 10 different digits for a place
    int output[n];

    for (int i = 0; i < n; ++i) {   //this will count the number of occurences for similar digit places in the list
        freq[(arr[i] / mul) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        freq[i] += freq[i - 1];
    }

//    for (int i = 0; i < 10; ++i) {
//        cout << freq[i] << " ";
//    }
//
//    cout << endl;

    for (int i = n - 1; i >= 0; i--) {
        output[freq[(arr[i] / mul) % 10] - 1] = arr[i];
        freq[(arr[i] / mul) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

}

void radixsort(int* arr, int n, int max)            //maxx is the maximum element in the array
{
    for (int exp = 1; max/exp > 0; exp *= 10)
        countsort(arr, n, exp);
}


int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
