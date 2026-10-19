#include <iostream>
using namespace std;

struct student {
    int n;
    int a,b,m,z;
};
student s[1005];
bool bi(student s)
{
    if (s.m>140&&s.a*7+s.b*3>=800) {
        return true;

    }
    else {return false;}

}
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>s[i].z>>s[i].a>>s[i].b;
        s[i].m=s[i].a+s[i].b;
    }
    for (int i=0;i<n;i++) {
        if (bi(s[i])) {
            cout<<"Excellent"<<endl;
        }
        else { cout<<"Not excellent"<<endl;}
    }
    return 0;
}
