
#include <iostream>

using namespace std;

int main() {
    int n;
    int f_0 = 0;
    int f_1 = 1;

    cin >> n;

    while (--n) {
        int tmp = f_1;

        f_1 += f_0;
        f_0 = tmp;
    }

    cout << f_1;

    return 0;
}
