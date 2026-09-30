#include <bits/stdc++.h>
using namespace std;
int main() {
    double m,h,bmi;
    cin >> m >> h ;
    bmi = m/h/h ;


    if (bmi<18.5) {
        cout<<"Underweight"<<endl;
    }
    else if (24>bmi && bmi>=18.5) {
        cout<<"Normal"<<endl;
    }
    else {
        cout <<setprecision(6)<< bmi << endl;
        cout<<"Overweight"<<endl;
    }

    return 0;
}
