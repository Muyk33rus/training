#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int t = 1;

    while (t <= n) {
        if(t==n){
            cout<<"YES"<<endl;
            break;
        }
        t *= 2;
    }
    if (t!=n){
        cout<<"NO"<<endl;
    }
    return 0;
}
