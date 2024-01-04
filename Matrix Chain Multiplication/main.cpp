#include <iostream>
using namespace std;
int max_val=100000;
void mcm(int output[],int numofItems){
        cout<<endl;
        int mcmTable[numofItems+1][numofItems+1];
        int value;
        for( int i = 1; i <= numofItems; i++) {
            mcmTable[i][i] = 0;
        }
        for (int len=2; len <= numofItems; len++) {
            for (int i=1; i <= numofItems-len+1; i++) {
                int j = i+len-1;
                mcmTable[i][j] = max_val;
                for (int k = i; k <= j-1; k++) {
                    value = mcmTable[i][k] + mcmTable[k+1][j] + output[i-1] * output[k] * output[j];
                    if (mcmTable[i][j] > value){
                        mcmTable[i][j] = value;
                    }
                }
            }
        }
        cout<<"\nMinimum Number of Multiplications Required:"<<mcmTable[1][numofItems];
}
int main()
{
int numofMatrices;
cout<<"Enter number of matrices:";
cin>>numofMatrices;
int output[numofMatrices+1];
cout<<"\nEnter dimensions:";
for(int i=0;i<=numofMatrices;i++)
{
cin>>output[i];
}
mcm(output, numofMatrices);
    return 0;
}