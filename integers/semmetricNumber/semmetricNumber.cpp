#include <iostream>
using namespace std;
int main() {
 int n;
 cin >> n;
 cout << (((n / 1000) - (n % 10)) * ((n / 1000) - (n % 10))) + (((n / 100 % 10) - (n / 10 % 10)) * ((n / 100 % 10) - (n / 10 % 10)))+ 1;
 return 0;
}