#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

double translationsOfNumberSystem(string const &std){
    double tmp=stof(std.c_str());

    if(std.find("cm")!=string::npos){
        tmp/=100;
    }else if(std.find("in")!=string::npos){
        tmp/=100;
        tmp*=2.54;
    }else if (std.find("ft")!=string::npos) {
        tmp/=100;
        tmp*=(2.54*12);
    }else if(std.find("m")==string::npos){
        cout<<"Num error"<<endl;
        return -1;
    }
    return tmp;
}

bool mySortFun(string& a,string& b){
    double tempA,tempB;
    tempA=translationsOfNumberSystem(a);
    tempB=translationsOfNumberSystem(b);
    return tempA>tempB;
}

int main(){
    string cur="0";
    double max=0,min=10000,sum=0;
    vector<string> vec;
    cout<<"Enter the distance"<<endl;
    while(cur!="|"){
        cin>>cur;
        if(cur=="|"){
            break;
        }
        double tmp=translationsOfNumberSystem(cur);
        if (tmp==-1){
            continue;
        }
        vec.emplace_back(cur);
        if(max<tmp)
            max=tmp;
        if(min>tmp)
            min=tmp;
        sum+=tmp;
        cout<<" min ="<<min<<"m"<<endl;
        cout<<" max ="<<max<<"m"<<endl;
        cout<<" sum ="<<sum<<"m"<<endl;
        cout<<"Enter the distance."<<endl;
        cout<<"Enter '|' to exit."<<endl;
    }
    sort(vec.begin(),vec.end(),mySortFun);
    for(auto i:vec){
        cout<<i<<" "<<endl;
    }
}
