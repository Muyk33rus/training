#include <iostream>

using namespace std;

int main() {
    int n,y = 2;

    cin >> n;
    
    while (n % y != 0) {
        ++y;
    }

    cout << y;

    return 0;
}
