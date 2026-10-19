#include<iostream>
using namespace std;
int main() {
    int l,m,n,c,b;
    cin>>l>>m;
   int a[l+1];
    for(int i=0;i<=l;i++){a[i]=1;}
    for(int i=1;i<=m;i++) {
        cin>>c>>b;
        for(int j=c;j<=b;j++) {a[j]=0;}
    }
    int num=0;
    for(int i=0;i<=l;i++) {
        num+=a[i];
    }
    cout<<num;
    return 0;
}