#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int x , vector<vector<int>> &a, vector<int> &visited){
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<"\t";
        for(int v : a[u]){
            if(visited[v]== 0){
                q.push(v);
                visited[v] = 1;
            }
        }

    }

}
int main(){
    int n,m,u,v;
    freopen("bfs.inp","r",stdin);
    freopen("bfs.out","w",stdout);
    cin>>n>>m;
    vector<vector<int>> a(n+1);
    vector<int> visited(n+1,0);
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i =1;i<=n;i++){
        if(visited[i]==0){
            bfs(i,a,visited);
        }
    }

}