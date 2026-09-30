#include <iomanip>
#include<iostream>
using namespace std;
int main() {
    int a;
    double b;
    cin >> a ;
    if (a <= 150) {
        b=a*0.4463;
        cout<<fixed<<setprecision(1)<<b<<endl;
    }
    else if (a >150 && a <= 400) {
        b=150*0.4463+(a-150)*0.4663;
        cout<<fixed<<setprecision(1)<<b<<endl;
    }
    else {
        b=150*0.4463+250*0.4663+(a-400)*0.5663;
        cout<<fixed<<setprecision(1)<<b<<endl;
    }
    return 0;
}