#include <iostream>
using namespace std;
int main() {
	int a,b,c;
		cin>>a>>b>>c;
	int v=(a+b+c)/2;
	if((a+b+c)%2)
		cout<<v+1<<endl;
	else
		cout<<v<<endl;
  return 0;
}