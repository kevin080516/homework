#include<iostream>
using namespace std;
int main() {
    int n,num=0,c=0;
    cin>>n;
    int a[3*n],b[n];
    for(int i=0;i<n;i++) {
        cin>>a[3*i]>>a[3*i+1]>>a[3*i+2];
        b[i]=a[3*i]+a[3*i+1]+a[3*i+2];
    }
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if (b[i]-b[j]<=10&&b[j]-b[i]<=10) {
                for(int k=0;k<3;k++) {
                    if (a[3*i+k]-a[3*j+k]<=5&&a[3*j+k]-a[3*i+k]<=5) {
                        c++;
                    }
                }
            }
            if (c==3){num++;}
            c=0;
        }

    }
    cout<<num;
    return 0;
}