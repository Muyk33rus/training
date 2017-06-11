#include <iostream>
using namespace std;
int main() {
    int v, t, s = 109;
    cin>>v>>t;
    cout << (s + (v * t % s)) % s;
  return 0;
}