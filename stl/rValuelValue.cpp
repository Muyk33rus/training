#include <iostream>

struct A{
    A(){std::cout<<"create A"<<std::endl;}
    A(const int& i){std::cout<<"i="<<i<<std::endl;}
    ~A(){std::cout<<"destroy A"<<std::endl;}
    void foo(const int &i){std::cout<<"this is lvalue"<<std::endl;}
    void foo(int &&i){std::cout<<"this is rvalue"<<std::endl;} //forwarding refernce
    template<typename T>
    void fooT(const T &i){std::cout<<"this is lvalue"<<std::endl;}
    template<typename T>
    void fooT(T &&i){std::cout<<"this is rvalue"<<std::endl;} //forwarding refernce

};

struct B{
    B(A a){}
};
struct C{
    void inc(int& i){std::cout<<"this is lvalue"<<std::endl; i++;}
    void inc(int&& i){std::cout<<"this is rvalue"<<std::endl; i++;}
};

int&& move_int( int &i){ return static_cast<int&&>(i);}
int&& move_int( int &&i){ return static_cast<int&&>(i);}

template<typename T>
T&& moveT(T &&t){
    return static_cast<T&&>(t);
}

template<typename T>
struct my_remove_reference{
    typedef T value;
};

template <typename T>
constexpr typename my_remove_reference<T>::value&& moveReal(T&& t)noexcept{
    return static_cast<typename my_remove_reference<T>::value&&>(t);
}

class Data{
public:
    Data(){std::cout<<"create Data"<<std::endl;}
    Data(const Data &d){}
    Data(Data &&data){}
    ~Data(){std::cout<<"destroy Data"<<std::endl;}
};

template <typename T, typename Arg>
T* make_ptr(Arg&&arg){
    return new T(arg);
}

int main(){
    //игра с++ чудо парсер))
    A a();
    {
        void foo();
        foo();
    }
    A a1;
    A a2({});
    A a3{};
    int i=1;
    B b (A(i));
    B b3 ((A(i)));
    B b1 (A(1));
    B b2 (A{i});
    A (x);
    A(x2);
    int (44);
    int (t)(5);
    std::cout<<"t="<<t<<std::endl;
    //rvalue -временный объект
    int ix =5;//rvalue(pure value)
    a1.foo(ix);
    a1.foo(int (1));
    a1.fooT("Hello");
    a1.fooT(nullptr);
    C c;
    int i1=5;
    c.inc(i1);  //void inc(int& i){ i++;}
    std::cout<<i1<<std::endl;
    c.inc(1);   //void inc(int&& i){ i++;}
    c.inc(std::move(i1));
    int i11=11;
    c.inc(static_cast<int&&>(i11));
    c.inc(static_cast<int&>(i11));
    c.inc(move_int(i11));
    c.inc(move_int(11));
    c.inc(move_int(moveReal(i11)));
    c.inc(move_int(moveReal(11)));
    Data d;
    Data* d2=make_ptr<Data>(d);  //Копирование
    Data* d3=make_ptr<Data>(Data()); //перемещение
    delete d2;
    delete d3;
    return 0;
}
void foo(){std::cout<<"foo"<<std::endl;}
