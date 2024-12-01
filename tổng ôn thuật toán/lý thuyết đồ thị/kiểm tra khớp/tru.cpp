#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
void dfs(int x,vector<vector<int>> &a,vector<int> &visited){
    visited[x]=1;
    for(int b :a[x]){
        if(visited[b]== 0 ){
            dfs(b,a,visited);
        }
    }
}
void checktru(int x,vector<vector<int>>&a,vector<int> &visited,int &dem){
    fill(visited.begin(), visited.end(), 0);
    int n = a.size();
    int cnt = 0;
   for(int i=1;i<=n;i++){
    if(visited[i]==0){
        cnt++;
        dfs(i,a,visited);
    }
   }
   fill(visited.begin(), visited.end(), 0);
   visited[x]=1;
   int count = 0;
   for(int i = 1;i<=n;i++){
    if(visited[i]==0){
        count++;
        dfs(i,a,visited);
    }
   }
   
    if(count>cnt){
        cout<<x<<"\t";
        dem++;
    }   

}

int main(){
    int n,m,u,v;
    freopen("khop.inp","r",stdin);
    freopen("khop.out","w",stdout);
    cin>>n>>m;
    vector<vector<int>> a(n+1);
    vector<int> visited(n+1,0);
    for(int i =1;i<=m;i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int dem=0;
    for(int i = 1;i<=n;i++){
        checktru(i,a,visited,dem);
    }
    cout<<endl<<"so dinh tru co trong do thi la:"<<dem;
    return 0;



}