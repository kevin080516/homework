#include<iostream>
using namespace std;
int main() {
    int n,num=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<0<<" ";
     for(int i=1;i<n;i++) {//n个数的循环
         for(int j=0;j<i;j++)//每个数的判断循环
         {
             if(a[i]>a[j]) {
               num++;
             }

         }
         cout<<num<<" ";
         num=0;
     }
           return 0;
}
