#include<iostream>
using namespace std;
int main () {
    int n,a=1;
    cin>>n;
    int m=n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if (a<10){cout<<0;}
            cout<<a;a++;
        }
        cout<<endl;
        m--;
    }
    return 0;
}