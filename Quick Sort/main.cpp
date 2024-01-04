#include <iostream>
using namespace std;

int partition(int arr[],int startIndex,int lastIndex){
int pivot=arr[lastIndex];
int pivotIndex=startIndex;
int temp;
for(int i=startIndex; i<lastIndex; i++){
    if(arr[i]<=pivot){
    temp=arr[i];
    arr[i]=arr[pivotIndex];
    arr[pivotIndex]=temp;
    pivotIndex++;
    }
}
    temp=arr[lastIndex];
    arr[lastIndex]=arr[pivotIndex];
    arr[pivotIndex]=temp;
return pivotIndex;
}

void quick_sort(int arr[],int start,int end){
int mid=(start+end)/2;
if(start<end){
    int part=partition(arr,start,end);
    quick_sort(arr,start,(part-1));
    quick_sort(arr,part+1,end);
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
    quick_sort(arr,0,n-1);
    cout<<"\nSorted Array:";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
