#include <iostream>
using namespace std;
struct stu {
    string name;
    int age,m;
};
stu s[1005];
int change(stu s){
    if (s.m>500) {
        s.m=600;
    }
    else{s.m=s.m*1.2;}
    return s.m;
}
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>s[i].name>>s[i].age>>s[i].m;
        s[i].age=s[i].age+1;
        s[i].m=change(s[i]);
    }
    for (int i=0;i<n;i++) {
        cout<<s[i].name<<" "<<s[i].age<<" "<<s[i].m<<endl;
    }
    return 0;
}
