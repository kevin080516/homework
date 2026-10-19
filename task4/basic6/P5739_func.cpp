#include <iostream>
using namespace std;
long long m(long long n){
    if(n==0) {
        return 1;
    }
     return m(n-1)*n;
}
int main() {
    long long n;
    cin>>n;
    cout<<m(n);
    return 0;
}