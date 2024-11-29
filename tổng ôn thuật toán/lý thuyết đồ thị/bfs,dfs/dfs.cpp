    #include <iostream>
    #include <vector>
    using namespace std;
    void dfs(int x,vector<vector<int>>&a,vector<int> &visited){
        cout<<x<<"\t";
        visited[x] = 1;
        for(int u : a[x]){
            if(visited[u]== 0){
                dfs(u,a,visited);
            }
        }
    }
    int main(){
        int n,m,u,v;
        freopen("dfs.inp","r",stdin);
        freopen("dfs.out","w",stdout);
        cin>>n>>m;
        vector<vector<int>> a(n+5);
        vector<int> visited(n+5,0);
        for(int i=1;i<=m;i++){
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int count = 0 ;
        for(int i =1;i<=n;i++){
            if(visited[i]==0){
            count++ ;
            dfs(i,a,visited);
            }
        }
        cout<<endl<<"so thanh phan lien thong:"<<count;
    return 0;
    }