#include<iostream>
using namespace std;
int main() {
    int n,x,p,t=0,y,j=10;
    cin>>n>>x;
    for(int i=1;i<=n;i++) {
        while (j<=i*10)
        {

            y=(i%j)/(j/10);
            if (y==x) {
                t++;
            }
            j=j*10;
        }
        j=10;
    }
    cout<<t;
    return 0;
}
