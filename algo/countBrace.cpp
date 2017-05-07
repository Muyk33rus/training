#include <iostream>
#include<string>
#include<stack>

using namespace std;

int countBrace(string str){
    string first="({[",second=")}]";
    int i=str.length(),count=0;
    stack<int> stackStr,stacIndex;
    while(i!=0){
        count++;
        if(first.find(str[0])<first.length()){
            stackStr.push(first.find(str[0]));
            stacIndex.push(count);
        }else if(second.find(str[0])<second.length()){
                int id=second.find(str[0]);
                if(!stackStr.empty()){
                    if(id==stackStr.top()){
                        stackStr.pop();
                        stacIndex.pop();
                    }
                    else
                        return count;
                }
                else
                    return count;
         }
         i--;
         str.erase(0,1);
    }
    if((stackStr.empty()||stackStr.size()==0)) return -1;
    else return stacIndex.top();
}


int main(){
//    while (true) {
std::string str;
std::cin>>str;
if (countBrace(str)==-1)
    cout<<"Success";
else if (countBrace(str)>0)
    cout<<countBrace(str);
//    }
}
