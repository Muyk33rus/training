#include <iostream>
using namespace std;
int main() {
    int a,b,c;
  cin>>a>>b>>c;
    if ((a==b&&b!=c)||(a==c&&a!=b)||(c==b&&c!=a))
        cout<<2<<endl;
    else if (b==c&&a==c)
        cout<<3<<endl;
    else
        cout<<0<<endl;
  return 0;
}