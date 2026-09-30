#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a;
    cin >> a;
    if (a%4==0)
    {
        if (a%100>0) {
            cout << "1" << endl;
        }
        else if (a%400==0) {
            cout << "1" << endl;
        }
        else {
            cout << "0" << endl;
        }
    }
    else
    {
        cout << "0" << endl;
    }

    return 0;

}