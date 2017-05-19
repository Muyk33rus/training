#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

using namespace std;

template <typename T>
string* retStr(const T &st){
   string *str =new string;
   bool isFirst = true;
   for (auto i :st){
       if(isFirst) {
           str->append(i);
           isFirst = false;
       } else {
           str->append("_");
           str->append(i);
       }
   }
   return str;
}



int main(){

    vector<string> vec;
    vec.emplace_back("vec");
    vec.emplace_back("vec1");
    vec.emplace_back("vec2");
    vec.emplace_back("vec3");
    vec.emplace_back("vec4");
    std::cout<<*retStr(vec)<<std::endl;

    set<string> s;
    s.insert("set");
    s.insert("set1");
    s.insert("set2");
    cout << *retStr(s) << endl;

    list<string> ls;
    ls.emplace_back("ls");
    ls.emplace_back("ls1");
    ls.emplace_back("ls2");
    ls.emplace_back("ls3");
    ls.emplace_back("ls4");
    std::cout<<*retStr(ls)<<std::endl;

}
