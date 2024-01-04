#include <iostream>

using namespace std;

void min_heapify(int arr[],int size,int p){
    int temp;
    int parent=p;
    int left=2*p+1;
    int right=2*p+2;
    if(left<size && arr[left]>arr[parent]){
        parent=left;
    }
    if(right<size && arr[right]>arr[parent]){
        parent=right;
    }
    if(parent!=p){
        temp=arr[p];
        arr[p]=arr[parent];
        arr[parent]=temp;
    min_heapify(arr,size,parent);
    }
}

void heap_sort(int arr[],int size){
    int temp;
    for(int i=(size/2)-1; i>=0; i--){
        min_heapify(arr,size,i);
    }
    for(int i=size-1; i>=0; i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
    min_heapify(arr,i,0);
    }
}

int main()
{
    int size;
    cout<<"Enter the array size:";
    cin>>size;
    int arr[size];
    cout<<"Enter the array elements:";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"Initial Array:";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    heap_sort(arr,size);
    cout<<"\nSorted Array:";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
