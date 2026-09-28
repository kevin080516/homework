#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double a,b,c,p,ans;
int main()
{
    cin >> a >> b >> c;
    p = (a+b+c)/2;
    ans=sqrt(p*(p-a)*(p-b)*(p-c));
    cout << fixed << setprecision(1)<< ans << endl;
    return 0;
}

