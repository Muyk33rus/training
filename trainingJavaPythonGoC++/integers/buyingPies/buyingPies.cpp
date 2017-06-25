#include <iostream>
using namespace std;
int main() {
 int a,b,c,v=0,w=0;
   cin>>a>>b>>c;
   v=a*c;
   w=b*c;
   v+=w/100;
   w=w%100;
   cout<<v<<" "<<w<<endl;
  return 0;
}
