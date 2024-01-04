#include <iostream>
using namespace std;

void bubble_sort(int arr[],int size){
int temp;
int flag;
for(int i=0; i<size-1; i++){
    flag=0;
    for(int j=0; j<size-i-1; j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            flag=1;
        }
    }
    if(flag==0){
        cout<<"\nArray Was Already Sorted!!!";
        break;
    }
}
}
int main()
{
    int n;
    cout<<"Enter the Array Size:";
    cin>>n;
    int arr[n];
    cout<<"Enter the Array Elements:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Unsorted Array:";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    bubble_sort(arr,n);
    cout<<"\nSorted Array:";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
