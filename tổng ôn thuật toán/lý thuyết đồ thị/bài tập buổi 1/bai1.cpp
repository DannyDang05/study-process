/* Cho đơn đồ thị có trọng số gồm n đỉnh và m cạnh (n,m<100). Hãy
- Liệt kê các đỉnh có bậc lẻ
- Liệt kê các đỉnh có bậc chẵn
- Liệt kê các đỉnh cô đơn (đỉnh k nối với bất kì đỉnh nào)
- Tìm đỉnh có tổng trọng số nhỏ nhất
- Tìm đỉnh có tổng trọng số lớn nhất
Ví dụ 
dothi.inp
6 7
1 2 5
2 3 4
3 4 2
4 5 7
1 5 4
4 1 5
4 2 3
dothi.out
dinh bac le: 1 2 
dinh bac chan: 3 4 5 6
đinh co don 6
dinh co trong so lon nhat 4
dinh co trong so be nhat 6*/

#include <iostream>
using namespace std;
int main(){
    int n,m,u,v,w;
    int a[100][100];
    freopen("dothi.inp","r",stdin);
    freopen("dothi.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=w;
         
    }
    cout<<"dinh bac chan : ";
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=1;j<=n;j++){
            if(a[i][j]!=0){
                count++;
            }
        }
        if(count%2==0) cout<<i<<"\t";
    
    }
     cout<<endl<<"dinh bac le : ";
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=1;j<=n;j++){
            if(a[i][j]!=0){
                count++;
            }
        }
        if(count%2!=0) cout<<i<<"\t";
    
    }
    cout<<endl<<"dinh co don : ";
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=1;j<=n;j++){
            if(a[i][j]!=0){
                count++;
            }
        }
        if(count==0) cout<<i<<"\t";
    
    }
    int imax;
    int max =0;
    int imin;
    int min = INT_MAX;
    for(int i=1;i<=n;i++){
        int trongso = 0;
        for(int j=1;j<=n;j++){
            if(a[i][j]!=0) trongso = trongso+w;
        }
        if(trongso>max){
            max = trongso;
            imax = i;
        }
        if(trongso<min){
            min = trongso;
            imin=i;
        }
    }
    cout<<endl<<"dinh co trong so lon nhat: "<<imax;
    cout<<endl<<"dinh co trong so nho nhat: "<<imin;

    return 0;
}


