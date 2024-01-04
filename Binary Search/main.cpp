#include <iostream>
using namespace std;

void insertion_sort(int arr[],int n){
    int initialvalue;
    int j;
    for(int i=1; i<n; i++){
        initialvalue=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>initialvalue){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=initialvalue;
    }
}

int binary_search(int arr[],int start,int end,int element){
if(start<=end){
    int mid=(start+end)/2;
    if(arr[mid]==element){
        return mid;
    }
    else if(element>arr[mid]){
        binary_search(arr,mid+1,end,element);
    }
    else{
        binary_search(arr,start,mid-1,element);
    }
}
    else
    return -1;
}
int main()
{
    int n,element;
	cout<<"Enter the Array Size:";
	cin>>n;
	int arr[n];
	cout<<"Enter the array elements:";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Initial Array:";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	insertion_sort(arr,n);
	cout<<"\nAfter Insertion Sort:";
		for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\nEnter the element to search:";
	cin>>element;
	int result=binary_search(arr,0,n-1,element);
	if(result==-1){
        cout<<"Element is not present in the Array";
	}
	else{
        cout<<element<<" is present in the index "<<result;
	}
    return 0;
}
