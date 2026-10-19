#include <iostream>
#include <cmath>
using namespace std;
struct student {
    string name;
    int a,b,c,m;
};
student s[1005];
bool bi(student a, student b) {
    if (abs(a.m-b.m)<=10) {
        if (abs(a.a-b.a)<=5&&abs(a.b-b.b)<=5&&abs(a.c-b.c)<=5 ){
            return true;
        }
        else {return false;}
    }
    else {
        return false;
    }
}
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>s[i].name>>s[i].a>>s[i].b>>s[i].c;
        s[i].m=s[i].a+s[i].b+s[i].c;
    }
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (bi(s[i],s[j])) {
                cout<<s[i].name<<" "<<s[j].name<<endl;
            }
        }
    }
    return 0;
}
