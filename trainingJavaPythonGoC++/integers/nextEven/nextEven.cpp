#include <iostream>
using namespace std;
int main() {
int i;
    cin>>i;
    i++;
    for (int k = 1; k < 10000; k++){
	    if (!(i%2)){
	        cout<<i<<endl;
	        break;
	    }
	    	i+=k;
	}
  return 0;
}