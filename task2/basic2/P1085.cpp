#include<iostream>
using namespace std;
int main()
{
  int a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,f1,f2,g1,g2;
  cin>> a1>>a2 ;
  cin>> b1>>b2 ;
  cin>> c1>>c2 ;
  cin>> d1>>d2 ;
  cin>> e1>>e2 ;
  cin>> f1>>f2 ;
  cin>> g1>>g2 ;
  int t,m;
  t=a1+a2; m=1;
  if (b1+b2>t){t=b1+b2; m=2;}
  if (c1+c2>t){t=c1+c2; m=3;}
  if (d1+d2>t){t=d1+d2; m=4;}
  if (e1+e2>t){t=e1+e2; m=5;}
  if (f1+f2>t){t=f1+f2; m=6;}
  if (g1+g2>t){t=g1+g2; m=7;}
  if (t>8){cout<<m<<endl;}
  if (t<=8){cout<<"0"<<endl;}
  return 0;
}