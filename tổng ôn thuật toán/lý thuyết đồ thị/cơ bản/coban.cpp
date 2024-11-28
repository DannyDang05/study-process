#include <iostream>
using namespace std;
int main(){
    int n,m,u,v;
    int a[100][100];
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    cin>>n>>m;
    for (int i = 1 ; i<=m;i++){
        cin>>u>>v;
        a[u][v] = a[v][u]= 1;
    }
    int max = 0;
    int imax;
    int imin;
    int min = INT_MAX; 
    for(int i =1;i<=n;i++){
        int count = 0;
        for(int j=1;j<=n;j++){
            if(a[i][j]==1) count++;
        }
        if(count>max){
            max = count;
            imax = i;
        }
        if(count<min){
            min = count;
            imin = i;
        }
    }
    cout<<"dinh co bac lon nhat :"<<imax<<endl;
    cout<<"dinh co bac nho nhat :"<<imin<<endl;
    return 0;

}