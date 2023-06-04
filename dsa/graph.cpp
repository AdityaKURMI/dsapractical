#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int const N=100000;
vector<int>graph[N];
int vis[N];
int mod=1000000007;
void dfs(int p){
    vis[p]=1;
    cout<<p<<" ";
    for(auto c : graph[p]){
        if(vis[c]) continue;
        vis[c]=1;
        
        dfs(c);
    }
}
void BFS(int a){
    vis[a]=1;
    queue<int>q;
    q.push(a);
    cout<<a<<" ";
    while(q.size()>0){
        int b=q.front();
        q.pop();
        for(auto i : graph[b]){
            if(vis[i]) continue;
            vis[i]=1;
            cout<<i<<" ";
            q.push(i);
        }
       
    }
}
signed main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);

    }
    BFS(1);
    for(int i=0;i<=n;i++){
        vis[i]=0;
    }
    cout<<endl;
    dfs(1);
    return 0;
}