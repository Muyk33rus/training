#include <iostream>
using namespace std;
int main() {
	int n=0;
	cin>>n;
	cout<<(n/100+n%100/10+n%10);
	return 0;
}