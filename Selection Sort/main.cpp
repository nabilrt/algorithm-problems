#include <iostream>
using namespace std;

void selection_sort(int arr[],int n){
int temp;
int min_index;
for(int i=0; i<n; i++){
    min_index=i;
    for(int j=i+1; j<n; j++){
        if(arr[j]<arr[min_index]){
          min_index=j;
        }
    }
    if(min_index!=i){
        temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
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
    selection_sort(arr,n);
    cout<<"\nSorted Array:";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
