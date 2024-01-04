#include <iostream>

#include <iomanip>

using namespace std;



struct Item{

    int itemWeight;

    int benefit;

};



int getmaxElement(int a,int b){

    if(a>b){

        return a;

    }

    return b;

}



int zoknapsack(Item items[],int numofItems,int bagsize){



    int table[numofItems+1][bagsize+1];

    for(int i=0; i<=numofItems; i++){

        for(int j=0; j<=bagsize; j++){

                if(i==0 || j==0){

                table[i][j]=0;

                }

                else if(items[i].itemWeight<=j){

                    table[i][j]= getmaxElement(table[i-1][j-items[i].itemWeight]+items[i].benefit, table[i-1][j]);

                }

                else{

                    table[i][j]=table[i-1][j];

                }

                cout<<setw(5)<<table[i][j]<<setw(10);

        }

        cout<<endl;

    }
    return table[numofItems][bagsize];

}



int main()

{

    int size,bagsize;

    cout<<"Enter the number of items:";

    cin>>size;

    Item items[size];



    for(int i=1; i<=size; i++){

        cout<<"Enter the weight of item no "<<i<<":";

        cin>>items[i].itemWeight;

        cout<<"Enter the benefit for item no "<<i<<":";

        cin>>items[i].benefit;

    }



    cout<<"Enter the knapsack size:";

    cin>>bagsize;

    cout<<endl;

    cout<<"   Table for Solving 0/1 Knapsack Problem"<<endl<<endl;

    int result=zoknapsack(items,size,bagsize);

    cout<<"\nTotal weight in the knapsack:"<<bagsize;

    cout<<"\nMax Benefit:"<<result;

    return 0;

}
