#include <iostream>
#include <windows.h>

using namespace std;

struct itemInfo{
string name;
int amount;
int price;
float density;
};

void getIteminformation(itemInfo items[],int size);
void printItemList(itemInfo items[],int size);
void build_minheap(itemInfo items[],int size,int root);
void heap_sort(itemInfo items[],int size);
void knapsack(itemInfo items[],int size,int bag_size);

int main()
{
    int size;
    int knapsacksize;
    cout<<"Enter the size of your item list:";
    cin>>size;
    itemInfo items[size];
    getIteminformation(items,size);
    cout<<"\nEnter the Knapsack size:";
    cin>>knapsacksize;
    system("CLS");
    cout<<"\nInitial List"<<endl;
    cout<<endl;
    printItemList(items,size);
    cout<<"\nList After Arranging"<<endl;
    cout<<endl;
    heap_sort(items,size);
    printItemList(items,size);
    cout<<endl;
    cout<<"Calculations"<<endl;
    system("Color E9");
    cout<<endl;
    cout<<"Name "<<" Weight "<<"  Price "<<" Accumulated Spending"<<endl;
    knapsack(items,size,knapsacksize);
    cout<<endl;
    return 0;
}

void getIteminformation(itemInfo items[],int size){
    cout<<"Enter the inventory Details"<<endl;
    for(int i=0; i<size; i++){
        cout<<"Enter the name of item number "<<i+1<<":";
        cin>>items[i].name;
        cout<<"Enter the amount of item number "<<i+1<<":";
        cin>>items[i].amount;
        cout<<"Enter the price of item number "<<i+1<<":";
        cin>>items[i].price;
        items[i].density=float(items[i].price)/(items[i].amount);
    }
}

void printItemList(itemInfo items[],int size){
   cout<<"Name "<<" Weight "<<"  Price "<<" Density"<<endl;
   for(int i=0; i<size; i++){
   cout<<items[i].name<<"\t "<<items[i].amount<<"\t "<<items[i].price<<"\t "<<items[i].density<<endl;
   }
}

void build_minheap(itemInfo items[],int size,int root){
    itemInfo temp;
    int parent=root;
    int leftchild=2*root+1;
    int rightchild=2*root+2;
    if(leftchild<size && items[parent].density>items[leftchild].density){
        parent=leftchild;
    }
    if(rightchild<size && items[parent].density>items[rightchild].density){
        parent=rightchild;
    }
    if(parent!=root){
        temp=items[parent];
        items[parent]=items[root];
        items[root]=temp;
        build_minheap(items,size,parent);
    }
}

void heap_sort(itemInfo items[],int size){
    itemInfo temp;
    for(int i=(size/2)-1; i>=0; i--){
        build_minheap(items,size,i);
    }
    for(int i=size-1; i>=0; i--){
        temp=items[0];
        items[0]=items[i];
        items[i]=temp;
        build_minheap(items,i,0);
    }
}

void knapsack(itemInfo items[],int size,int maxsize){
    float total_amount=0;
    float extra_value;
    int extra_Amount;
    float min_spendings=0;
    for(int i=0; i<size; i++){
        if(items[i].amount+total_amount<=maxsize){
            total_amount=total_amount+items[i].amount;
            min_spendings=min_spendings+items[i].price;
            cout<<items[i].name<<"\t "<<items[i].amount<<"\t "<<items[i].price<<"\t "<<min_spendings<<endl;
        }
        else{
            extra_Amount=maxsize-total_amount;
            extra_value=extra_Amount*(float(items[i].price)/(items[i].amount));
            total_amount=total_amount+extra_Amount;
            min_spendings=min_spendings+extra_value;
            cout<<items[i].name<<"\t "<<extra_Amount<<"\t "<<extra_value<<"\t "<<min_spendings<<endl;
            break;
        }
    }
    cout<<"\nTotal Juice:"<<total_amount<<endl;
    cout<<"Minimum Spendings:"<<min_spendings;
}
