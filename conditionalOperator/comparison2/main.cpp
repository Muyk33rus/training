#include <iostream>
using namespace std;

int a,b;
int main() {

    cin>>a>>b;
    if (a>b)
        cout<<1<<endl;
    else if (b > a)
        cout <<2<<endl;
        else 
            cout<<0<<endl;
    return 0;
}