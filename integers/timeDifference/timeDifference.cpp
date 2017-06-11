#include <iostream>
using namespace std;
int main() {
    int tim,ch1,mi1,sec1,ch2,mi2,sec2;
    cin>>ch1>>mi1>>sec1;
    cin>>ch2>>mi2>>sec2;
    tim=(ch2-ch1)*3600+(mi2-mi1)*60+(sec2-sec1);
    cout<<tim<<endl;
  return 0;
}