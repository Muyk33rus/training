#include <iostream>

using namespace std;

int main() {
    int prev = -1;
    int cur = -1;
    int next =-1;
    int count = 0,t_count=0,max=1;
    if(cin >> prev && prev != 0) {
        if(cin >> cur && cur != 0) {
          while (cin >> next && next != 0) {
             if (prev < cur && cur > next) {
                 if(t_count>count||t_count==0){
                    if(max>1)
                        t_count=count;
                 }
                 count=1;
                 max++;
                 } else{
                    count++;
                 }
                 prev = cur;
                 cur = next;
            }
        }
    }
    cout << t_count;
    return 0;
}