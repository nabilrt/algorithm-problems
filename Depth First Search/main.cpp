#include <iostream>
#include <stack>
using namespace std;

int graph[100][100];
int state[100];
int initial=1;
int waiting=2;
int visited=3;
int vertices;
stack<int> s;

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
void DFS(int v){
    cout<<"DFS: ";
    int i;
    s.push(v);
    state[v]=waiting;

    while(!s.empty()){
        cout<<s.top()<<" ";
        v=s.top();
        state[v]=visited;
        s.pop();
        for(i=1;i<=vertices;i++){
            if(graph[v][i]==1 && state[i]==initial){
                s.push(i);
                state[i]=waiting;
            }
        }
    }
    cout<<endl;
}
void DFS_Traversal(){
	int v;
	for(v=1; v<=vertices; v++){
		state[v]=initial;
	}

	cout<<"Enter Start Vertex for DFS:";
	cin>>v;
	DFS(v);
}


int main()
{
    int edges;
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
    DFS_Traversal();
    return 0;
}
