#include <iostream>
#include <vector>
using namespace std;
void dfs(int x,vector<vector<int>> &a,vector<int> &visited){
    visited[x]=1;
    for(int b :a[x]){
        if(visited[b]== 0 ){
            dfs(b,a,visited);
        }
    }
}

bool checktru(int t,vector<vector<int>> &a){
    int stplt = 1 ;
    int n = a.size();
    vector <int> check(n+1,0);
    check[t]= 1;
    for(int i = 1 ;i<=n;i++){
        if(check[i]==0) stplt++;
    }
    if(stplt==1){
        return 0;
    }
    return 1;


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
    if(checktru(2,a)==0){
        cout<<"khong la dinh tru"<<endl;
    }else cout<<"la dinh tru"<<endl;

}