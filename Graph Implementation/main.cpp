#include <iostream>
using namespace std;

int graph[100][100];

void create_Graph(int vertices,int edges){
    graph[vertices+1][vertices+1];
    int src,des;
    for(int i=1; i<=vertices; i++){
    for(int j=1; j<=vertices; j++){
           graph[i][j]=0;
        }
    }
    for(int i=1; i<=edges; i++){
    int flag=0;
    while(flag==0){
    cout<<"\nEnter the Source:";
    cin>>src;
    cout<<"Enter the Destination:";
    cin>>des;
    flag=1;
    if(src>vertices || des>vertices){
    --i;
    cout<<"Invalid Edge!!-Please Enter Again";
    flag=0;
    break;
    }
    }
        graph[src][des]=1;
        graph[des][src]=1;
    }
}

int main()
{
    int vertices,edges;
    cout<<"Enter the number of vertices:";
    cin>>vertices;
    cout<<"Enter the number of edges:";
    cin>>edges;
    create_Graph(vertices,edges);
    cout<<endl;
    cout<<"Connections:"<<endl;
    for(int i=1; i<=vertices; i++){
        for(int j=1; j<=vertices; j++){
            if(graph[i][j]==1){
                cout<<i<<"->"<<j<<endl;
            }
        }
    }
    cout<<"\nAdjacency Matrix Table:"<<endl;
    for(int i=1; i<=vertices; i++){
        for(int j=1; j<=vertices; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}