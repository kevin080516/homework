#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double dis(double aa,double bb,double cc,double dd)
{
    double di=sqrt((aa-cc)*(aa-cc)+(bb-dd)*(bb-dd));
    return di;
}
int main() {

    double a[2],b[2],c[2];
    cin>>a[0]>>a[1]>>b[0]>>b[1]>>c[0]>>c[1];
    cout<<fixed<<setprecision(2)<<dis(a[0],a[1],b[0],b[1])+dis(b[0],b[1],c[0],c[1])+dis(c[0],c[1],a[0],a[1]);
    return 0;
}
