#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,t;
    double l;
    cin >> a >> b;
    l=a*3.14*b*b;
    t=ceil(20000/l);
    cout << t << endl;
    return 0;
}