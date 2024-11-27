#include <iostream>
using namespace std;
void nhapmang(int a[100][100],int &m , int &n ){
    for (int i =0;i<m;i++){
        for ( int j = 0;j<n;j++){
            cout<<"a["<<i<<"]["<<j<<"]=";
            cin>>a[i][j];
        }
    }
}

void xuatmang(int a[100][100],int m , int n){
    for(int i = 0 ; i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}


int main(){
    int a[100][100];
    int m,n;
    cout<<"nhap vao dong va cot:";
    cin>>m;
    cin>>n;
    nhapmang(a,m,n);
    xuatmang(a,m,n);
    return 0;

}
