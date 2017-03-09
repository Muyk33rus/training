#include <iostream>
using namespace std;
int main() {
 int N;
   cin>>N;
   cout.width(2);
   cout.fill('0');
   cout<<N/3600%24<<":";
   cout.width(2);
   cout.fill('0');
   cout<<N%3600/60<<":";
   cout.width(2);
   cout.fill('0');
   cout<<N%60<<endl;
  return 0;
}