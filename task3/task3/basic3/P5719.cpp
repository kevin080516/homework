#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k,t;
    double a,b;
    cin>>n>>k;
    t=n/k;
    a=0;
    for(int i=1;i<=t;i++) {
        a+=k*i;
    }
    b=(n*(n+1)/2-a)/(n-t);
    a=a/t;
    cout << fixed << setprecision(1) << a << " " << b << endl;
    return 0;
}