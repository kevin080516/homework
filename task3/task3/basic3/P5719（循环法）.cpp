#include<iostream>
#include<iomanip>
using namespace std;
int main () {
    int n,k,t;
    cin>>n>>k;
    t=n/k;

    double a=0,b=0;
    for (int i=1;i<=n;i++) {
        if (i%k==0) {
            a+=i;
        }
        else {b+=i;}
    }
    a=a/t;b=b/(n-t);
    cout<<fixed<<setprecision(1)<<a<<" "<<b<<endl;
    return 0;
}