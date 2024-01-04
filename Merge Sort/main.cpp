#include <iostream>

using namespace std;

void merge(int arr[],int start,int mid,int end){
    int leftside=start;
    int rightside=mid+1;
    int temp[end+1];
    int k=start;
    while(leftside<=mid && rightside<=end){
        if(arr[leftside]<=arr[rightside]){
            temp[k]=arr[leftside];
            k++; leftside++;
        }
        else{
            temp[k]=arr[rightside];
            k++; rightside++;
        }
    }
    while(leftside<=mid){
        temp[k]=arr[leftside];
        leftside++; k++;
    }
    while(rightside<=end){
        temp[k]=arr[rightside];
        rightside++; k++;
    }
    for(int i=start; i<=end; i++){
        arr[i]=temp[i];
    }
}

void merge_sort(int arr[],int start,int end){
    int mid=(start+end)/2;
    if(start<end){
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,mid,end);
    }
    return;
}
int main()
{
    int n;
	cout<<"Enter the Array Size:";
	cin>>n;
	int arr[n];
	cout<<"Enter the array elements:";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Unsorted Array:";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	merge_sort(arr,0,n-1);
	cout<<"\nSorted Array:";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
    return 0;
}
