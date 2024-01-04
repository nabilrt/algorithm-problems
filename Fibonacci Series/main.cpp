
/*#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    else {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;
    int result=fibonacci(n);
    cout<<"Result:"<<result;
    return 0;
}
*/
#include <iostream>

using namespace std;

int fibonacciI(int n){
int a,b,c;
a=0;
b=1;
for(int i=2; i<=n; i++){
    c=a+b;
    a=b;
    b=c;
}
return c;
}

int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;
    int result=fibonacciI(n);
    cout<<"Result:"<<result;
    return 0;
}
