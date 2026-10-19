#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct stu{
    string name;
    int a,b,c,m;
};stu s[1005];
bool bi(stu x,stu y){
    return x.m>y.m;
}
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>s[i].name>>s[i].a>>s[i].b>>s[i].c;
        s[i].m=s[i].a+s[i].b+s[i].c;
    }
    stable_sort(s,s+n,bi);
    cout<<s[0].name<<" "<<s[0].a<<" "<<s[0].b<<" "<<s[0].c;
    return 0;
}
