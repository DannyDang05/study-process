#include <iostream>
#include <math.h>
using namespace std;

void nhapmang(int a[],int &n ){
    for ( int i =0;i<n;i++){
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }
}

void xuatmang(int a[],int n){
    for ( int i =0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

void timkiem(int a[],int n){
    int k;
    cout<<"nhap vao so k can tim trong mang";
    cin>>k;
    for(int i = 0 ; i < n ; i ++){
        if (a[i] == k){
            cout<<"ton tai k trong mang";
        }else cout<<"khong tim thay k trong mang nay";
    }
}

bool checksnt(int k){
    for ( int i = 2; i<=sqrt(k);i++){
        if (k%i==0) return false;
    }
    return true;
}

void check(int a[],int n){
    int checkk=0;
    for(int i =0 ;i<n;i++){
        if(checksnt(a[i])== true){cout<<a[i]<<"\t"; checkk=1;}
    }
    cout<<endl;
    if(checkk=0) cout<<"khong co so nguyen to nao trong mang nay"<<endl;
}

void lonnhat(int a[],int n){
    int maxx = a[0];
    for(int i =1;i<n;i++){
        if(a[i]>maxx) maxx = a[i];
    }
    cout<<"gia tri lon nhat :"<<maxx<<endl;;
}

void nhonhat(int a[],int n){
    int minn = a[0];
    for(int i = 1;i<n;i++){
        if (a[i]<minn) minn = a[i];
    }
    cout<<"gia tri nho nhat trong mang:"<<minn<<endl;
}
void selectionsort(int a[],int n){
    for(int i =0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(a[j]<a[i]) swap(a[i],a[j]);
        }
    }
}

void bubblesort(int a[],int n){
    for(int i=n-1;i>=1;i--){
        for ( int j=0;j<i;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}


void insertionsort(int a[],int n){
    for(int i = 1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main(){
    int a[100];
    int n ;
    cout<<"vui long nhap vao mot so nguyen:";
    cin>>n;
    nhapmang(a,n);
    xuatmang(a,n);
    check(a,n);
    lonnhat(a,n);
    nhonhat(a,n);
    insertionsort(a,n);
    xuatmang(a,n);
    return 0;

}