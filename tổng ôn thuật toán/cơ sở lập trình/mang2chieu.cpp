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

void sumduongcheophu(int a[100][100],int m,int n){
    int sum = 0;
    for ( int i =0;i<n;i++){
        sum = sum + a[i][n-1-i];
    }
    cout<<"tong cua duong cheo phu :"<<sum;

}

void sumduongcheochinh(int a[100][100],int m, int n){
    int sum = 0 ;
    for(int i = 0;i<n;i++){
        sum = sum + a[i][i];
    }
    cout<<"tong cua duong cheo chinh:"<<sum<<endl;
}

void maxmatranduoi(int a[100][100],int m , int n){
    int maxx = -1;
    for(int i = 0; i<n;i++){
        for(int j = 0 ;j<n;j++){
            if(j<i && a[i][j]>maxx) maxx = a[i][j];
        }
    }
    cout<<"max ma tran duoi:"<<maxx<<endl;
}

void maxmatrantren(int a[100][100],int m , int n){
    int maxx = -1;
    for(int i =0 ;i<n;i++){
        for(int j =0;j<n;j++){
            if(j>i&&a[i][j]>maxx) maxx = a[i][j];
        }
    }
    cout<<"max ma tran tren:"<<maxx<<endl;
}

void demmatrantren(int a[100][100],int m ,int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            if(j>i&&a[i][j]%2==0) count++;
        }
    }
    cout<<"so luong gia tri chan cua ma tran tren la:"<<count;
}




int main(){
    int a[100][100];
    int m,n;
    cout<<"nhap vao dong va cot:";
    cin>>m;
    cin>>n;
    nhapmang(a,m,n);
    xuatmang(a,m,n);
    sumduongcheophu(a,m,n);
    sumduongcheochinh(a,m,n);
    maxmatranduoi(a,m,n);
    maxmatrantren(a,m,n);
    demmatrantren(a,m,n);
    return 0;

}
