#include <iostream>

using namespace std;

int main() {
    int n;
    int max = -1;
    int s_max = -1;

    while (cin >> n && n != 0) {
        if (max <= n) {
            s_max = max;
            max = n;
        }
        else if (s_max < n) {
            s_max = n;
        }
    }

    cout << s_max;

    return 0;
}