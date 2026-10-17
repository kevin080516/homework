#include <iostream>
using namespace std;
int main() {
    int n,a[7],m=0,c[8];
    cin>>n;
    int b[n*7];
    c[0]=0,c[1]=0,c[2]=0,c[3]=0,c[4]=0,c[5]=0,c[6]=0,c[7]=0;
    for(int i=0;i<=6;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n*7;i++) {
        cin>>b[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<7;j++) {
            for(int k=0;k<7;k++) {
                if(a[j]==b[i*7+k]) {
                    m++;
                }
            }
        }
        c[7-m]+=1;
        m=0;
    }
    cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<" "<<c[5]<<" "<<c[6]<<endl;
    return 0;
}