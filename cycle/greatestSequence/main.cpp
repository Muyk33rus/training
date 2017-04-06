
#include <iostream>

using namespace std;

int main() {
    int x,temp=-1,t_count=0,res=0,count=0;

    while (cin >> x && x != 0) {
            if(temp!=x){
                t_count=count;
                temp=x;
                count=1;
            }else{
                count++;
            }
            if(res<count){
                res=count;
            }else if(res<t_count){
                res=t_count;
            }
    }

    cout << res;

    return 0;
}