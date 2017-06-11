#include <iostream>

using namespace std;
//наибольший общий делитель сложность O(Log(b))
int GCD(int a, int b){
    while(b!=0){
        int remainder=a%b;
        a=b;
        b=remainder;
    }
    return a;
}

int main(){
    cout<<GCD(100, 4687)<<endl;
    cout<<GCD(4, 462)<<endl;
    cout<<GCD(3804, 48904)<<endl;
    cout<<GCD(4890, 840)<<endl;
    cout<<GCD(3663, 33332)<<endl;
}
