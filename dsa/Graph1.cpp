// Input:
// 5
// 5
// 1 2
// 1 3
// 1 5
// 2 4
// 3 4

#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        map<int, list<int > > Adj;
        vector<int > ans;
        map<int , bool> visited;
        queue<int> q;
        void insert(int , int , bool);
        void printGraph();
        void BFS(int);
        void DFS(int);
};

void Graph::insert(int i, int j, bool directed){
    Adj[i].push_back(j);
    if(!directed){
        Adj[j].push_back(i);
    }
}

void Graph::printGraph(){
    for(auto i:Adj){
        cout<<i.first<<"-> ";
        for(auto j:i.second){
            cout<<j<<", ";
        }
        cout<<endl;
    }
}

void Graph::BFS(int node){
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        ans.push_back(q.front());
        for(auto i:Adj[q.front()]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }   
        }
        q.pop();
    }
}

void Graph::DFS(int node){
    ans.push_back(node);
    visited[node]= 1;

    for(auto i: Adj[node]){
        if(!visited[i]) DFS(i);
    }
}

int main(){
    int n,e, u, v;
    //cout<<"Enter Number Of Nodes:-\n";
    cin>>n;
    //cout<<"Enter number of edges in graph:-\n";
    cin>>e;

    Graph g;
    for(int i=0;i<e;i++){
        //cout<<"Enter the Nodes existing between:-";
        cin>>u>>v;
        g.insert(u, v, 0);
    }
    // cout<<"Graph representation through Adjency List:- "
    // g.printGraph();

    //------BFS-----
    // cout<<"\n\n\n\nBFS:-\n";
    
    // for(int i=0;i<n;i++){
    //     if(!g.visited[i]){
    //         g.BFS(i+1);
    //     }
    // }

    // for(int i=0; i < n; i++){
    //     cout<<g.ans.at(i)<<" ";
    // }

    //-----DFS------
    cout<<"\n\n\n\nDFS:-\n";
    
    for(int i=0;i<n;i++){
        if(!g.visited[i]){
            g.DFS(i+1);
        }
    }

    for(int i=0; i < n; i++){
        cout<<g.ans.at(i)<<" ";
    }
}