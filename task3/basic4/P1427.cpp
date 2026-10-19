#include <iostream>
using namespace std;

int main() {
    int a[110],n;
    for(int i=0;i<110;i++) {
        cin>>a[i];
        n=i;
        if (a[i]==0) {
            break;
        }
    }
    for (int j=n-1;j>=0;j--) {
        cout<<a[j]<<" ";
    }
    return 0;
}
