#include <iostream>
using namespace std;
int main() {
    int n,a,num;
    cin>>n;
    cin>>a;
    for(int i=2;i<=n;i++) {
        cin>>num;
        if (num<a) {
            a=num;
        }
    }
    cout<<a;
    return 0;
}