#include <iostream>
using namespace std;

void insertion_sort(int arr[],int n){
int index;
int j;
for(int i=1; i<n; i++){
    index=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>index){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=index;
}
}
int main()
{
    int n;
	cout<<"Enter the Array Size:";
	cin>>n;
	int arr[n];
	cout<<"Enter the Array elements:";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Unsorted Array:";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	insertion_sort(arr,n);
	cout<<"\nSorted Array:";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}
