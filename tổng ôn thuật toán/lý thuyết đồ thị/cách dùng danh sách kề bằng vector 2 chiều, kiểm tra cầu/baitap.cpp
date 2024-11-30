        #include <iostream>
        #include <vector>
        #include <cstring>
        using namespace std;
        void dfs(int x,vector<vector<int>> &a,vector<int> &visited){
            cout<<x<<"\t";
            visited[x]=1;
            for(int u : a[x]){
                if(visited[u]==0){
                    dfs(u,a,visited);
                }
            }
        }

        void dfss(int x,vector<vector<int>> &a,vector<int> &visited){
            visited[x]=1;
            for(int u : a[x]){
                if(visited[u]==0){
                    dfss(u,a,visited);
                }
            }
        }
                void remove(int u,int v,vector<vector<int>> &a){
            for( auto it = a[u].begin();it!=a[u].end();it++){
                if(*it == v){
                    a[u].erase(it); 
                    return;
                }
            }

        }
        bool isconnected(int u , int v , vector<vector<int>> &a){
            int n = a.size();
            vector<int> check(n+1,0);
            remove(u,v,a);
            remove(v,u,a);
            dfss(u,a,check);
            a[u].push_back(v);
            a[v].push_back(u);
            if(check[v]==1) return 0 ;
            return 1;

        }


        int main(){
            int n,m,u,v,w;
            freopen("dothi.inp","r",stdin);
            freopen("dothi.out","w",stdout);
            cin>>n>>m;
    
            vector<vector<int>> a(n+1);
            vector<int> visited(n+1,0);
            for(int i = 1;i<=m;i++){
                cin>>u>>v>>w;
                a[u].push_back(v);
                a[v].push_back(u);
    
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
            int ss = 0 ;
            int ss1=INT_MAX;
            int imax;
            int imin;
            for(int i = 1;i<=n;i++){
                int cnt = a[i].size();
                if (cnt>ss) {
                    ss = cnt ;
                    imax = i;

                }

                if(cnt<ss1){
                    ss1 = cnt;
                    imin = i;
                }
                }
            
            cout<<"dinh noi voi nhieu dinh khac nhat(bac) la:"<<imax<<endl;
            cout<<"dinh noi voi it dinh khac nhat(bac) la: "<<imin<<endl;
            memset(&visited[0], 0, visited.size() * sizeof(int));
            for ( int i =1;i<=n;i++){
                for(int v : a[i]){
                    
                    if(isconnected(i,v,a)){
                        cout<<i<<"\t"<<v<<"khong la canh cau"<<endl;
                    }
                
                }
            }
         
         
        



            return 0;

        }