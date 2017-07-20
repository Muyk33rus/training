#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
//variadic trmplate
//parameter pack
//std::tuple

using std::cout;
using std::endl;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::string;
using std::vector;
using std::for_each;
using std::sort;

template<typename... Args>
void print(Args... args){}

template<typename Head,typename... Args>
void print(Head h,Args... args){
    cout<<h<<endl;
    print(args...);
}

tuple<int ,string> get(){
    return make_tuple(1,"lol");
}

auto get3(){
    return make_tuple(3,"lol3");
}
auto get2= [](){
    return make_tuple(2,"lol2");
};

struct Man{
    short age;
    short langs;
    string name;
};

template <std::size_t> struct int_{};

template <typename Tuple>
 std::ostream& print_tuple( std::ostream& out,const Tuple & t,int_<1>){
     return out<<std::get<std::tuple_size<Tuple>::value-1>(t);
 }

template <typename Tuple, std::size_t Pos>
 std::ostream& print_tuple( std::ostream& out,const Tuple & t,int_<Pos>){
    out<<std::get<std::tuple_size<Tuple>::value-Pos>(t)<<", ";
    return print_tuple(out,t,int_<Pos-1>());
}

template<typename... Args>
std::ostream& operator<<(std::ostream& out, const tuple<Args...>& t){

    out<<"(";
    print_tuple(out,t,int_<sizeof...(Args)>());
    return out<<")";
}


int main()
{
    print();
    print(1);
    print(1,6,'4');
    tuple<> tupleN;
    tuple<int ,string> t1 (1,"479");
    auto t2= make_tuple(34794 ,"fjoo");
    print(std::get<0>(t1));
    print(std::get<1>(t1));
//    print(std::get<2>(t1)); //ERROR
    int a;
    string b;
    tie(a,b)=t2;
    print(a);
    print(b);
    auto t3= get();
    print(std::get<0>(t3));
    print(std::get<1>(t3));
    t3=get3();
    print(std::get<0>(t3));
    print(std::get<1>(t3));
    auto t4= get2();
    print(std::get<0>(t4));
    print(std::get<1>(t4));
    Man man1{12,2,string("kolya")};
    Man man2{9,4,string("kostya")};
    Man man3{45,1,string("ivan")};
    vector<Man> vecMan{man1, man2,man3};
    for_each(vecMan.begin(),vecMan.end(),[](const Man& man){ cout<<"name: "<<man.name<<" Age:"<<man.age<<" Langs:"<<man.langs<<endl;});
    sort(vecMan.begin(),vecMan.end(),[](const Man& man1,const Man& man2){return tie(man1.name,man1.langs)<tie(man2.name,man2.langs);});
    for_each(vecMan.begin(),vecMan.end(),[](const Man& man){ cout<<"name: "<<man.name<<" Age:"<<man.age<<" Langs:"<<man.langs<<endl;});
    auto sup_tuple=std::tuple_cat(make_tuple(2,4,5),make_tuple(1,5,4));
    cout<<sup_tuple;
    return 0;
}
