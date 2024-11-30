        #include <iostream>
        #include <vector>
        #include <cstring>
        using namespace std;
        void dfs(int x,vector<vector<pair<int,int>>> &a,vector<int> &visited){
            cout<<x<<"\t";
            visited[x]=1;
            for(auto u : a[x]){
                if(visited[u.first]==0){
                    dfs(u.first,a,visited);
                }
            }
        }

        void dfss(int x,vector<vector<pair<int,int>>> &a,vector<int> &visited){
            visited[x]=1;
            for(auto u : a[x]){
                if(visited[u.first]==0){
                    dfss(u.first,a,visited);
                }
            }
        }

            void dfsss(int x,vector<vector<pair<int,int>>> &a,vector<int> &visited,int &maxx){
            visited[x]=1;
            for(auto u : a[x]){
                if(visited[u.first]==0){
                    maxx = maxx + u.second;
                    dfsss(u.first,a,visited,maxx);
                }
            }
            
        }


        int main(){
            int n,m,u,v,w;
            freopen("dothi.inp","r",stdin);
            freopen("dothi.out","w",stdout);
            cin>>n>>m;
            vector<vector<pair<int,int>>> a(n+1);
            vector<int> visited(n+1,0);
            for(int i = 1;i<=m;i++){
                cin>>u>>v>>w;
                a[u].push_back({v,w});
                a[v].push_back({u,w});
            }
            int count = 0 ;
            for(int i = 1;i<=n;i++){
                if(visited[i]== 0 ){
                    count++;
                    cout<<"dinh thanh phan lien thong thu "<<count<<": ";
                    dfs(i,a,visited);
                    cout<<endl;
                }
            }
            memset(&visited[0], 0, visited.size() * sizeof(int));
            int count1=0;
            for(int i =1;i<=n;i++){     
                if(visited[i]==0){
                    count1++;
                    dfss(i,a,visited);
                }
            }
            cout<<"so thanh phan lien thong co trong do thi:"<<count1<<endl;
            memset(&visited[0], 0, visited.size() * sizeof(int));
            int maxxx = 0;
            for(int i =1;i<=n;i++){
                if(visited[i]==0){
                    int maxx = 0;
                    dfsss(i,a,visited,maxx);
                    maxxx = max(maxxx,maxx);
                }
            }
            cout << "Thanh phan lien thong co tong trong so lon nhat: " << maxxx << endl;
            
        
            
            return 0;

        }