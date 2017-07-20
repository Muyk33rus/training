#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
using std::vector;

struct point{
  int x;
  int y;
  point():x(1),y(1){}
  point( int x, int y):x(x),y(y){}
};
std::ostream& operator <<(std::ostream& os, const point &p ){
    return os<<"x:"<<p.x<<" y:"<<p.y;
}

//функтор
struct des{
    des(){std::cout<<"create des functor"<<std::endl;}
    ~des(){std::cout<<"destroy des functor"<<std::endl;}
    void bar(){std::cout<<"lol, you click bar()"<<std::endl;}
    void operator ()(point *p){std::cout<<"destroy point"<<std::endl; delete[] p;}
};


//перекресные ссылки
struct Foo;
struct Bar{
    Bar(){std::cout<<"create Bar"<<std::endl;}
    ~Bar(){std::cout<<"destroy Bar"<<std::endl;}
    std::weak_ptr<Foo> foo;
};

struct Foo{
    Foo(){std::cout<<"create Foo"<<std::endl;}
    ~Foo(){std::cout<<"destroy Foo"<<std::endl;}
    std::shared_ptr<Bar> bar;
};



int main()
{
    point x1;
    std::cout<<x1<<std::endl;
    {
        std::cout<<std::endl<<"auto_ptr"<<std::endl;
        std::auto_ptr<point> ptr_point=std::auto_ptr<point>(new point);
        std::cout<<*ptr_point<<std::endl;
        vector<std::auto_ptr<point>> vecAuto;
        vecAuto.push_back(std::auto_ptr<point>(new point));
        vecAuto.push_back(std::auto_ptr<point>(new point(2,2)));
        auto elem=vecAuto[0];
        std::cout<<*elem<<std::endl;
    //    std::cout<<*vecAuto[0]<<std::endl; //ERROR
        auto p1 =std::auto_ptr<point>(new point(2,2));
        std::cout<<p1.get()<<std::endl;
    }
    {
        std::cout<<std::endl<<"unique_ptr"<<std::endl;
        std::unique_ptr<point> up1=std::unique_ptr<point>(new point);
//        std::unique_ptr<point> up= up1; //ERROR
        std::unique_ptr<point> up2= std::move(up1);
        std::cout<<*up2<<std::endl;
        if(up2){
          std::cout<<"if (un2 )"<<*up2<<std::endl;
        }
        auto up3= std::make_unique<point>(3,6);
        std::cout<<*up3.get()<<std::endl;
        std::unique_ptr<point,des>up4(new point[6],des());
        std::cout<<up4.get()[3]<<std::endl;
        auto del=up4.get_deleter();
        del.bar();
        std::unique_ptr<point,std::function<void(point*)>>up5(new point[6],[](auto*p){std::cout<<" lamda destroy point"<<std::endl;delete[] p;});
        std::cout<<up5.get()[1]<<std::endl;
        up1.swap(up2);
        up1.reset();// null_ptr
        up1.reset(new point(64,5));
        std::cout<<*up1<<std::endl;
    }
    {
        std::cout<<std::endl<<"shared_ptr"<<std::endl;
        std::shared_ptr <point> sp1 =std::make_shared<point>(1,3);
        std::shared_ptr <point> sp2 =sp1;
        std::cout<<*sp1<<std::endl;
        std::cout<<*sp2<<std::endl;
        std::cout<<sp2.use_count()<<std::endl;
        std::cout<<sp1.use_count()<<std::endl;

        auto test_use_count=[]( const auto& value){
            std::cout<<value.use_count()<<std::endl;
        };
        auto test_use_count1=[]( const auto& value){
            std::cout<<value.use_count()<<std::endl;
        };
        test_use_count(sp1);// out 2
        test_use_count1(sp1);// out 3
//        auto sp3 =std::make_shared<point[]>(); //ERROR

        {
            std::cout<<std::endl<<"weak_ptr"<<std::endl;
            auto foo =std::shared_ptr<Foo>(new Foo);
            foo->bar=std::shared_ptr<Bar>(new Bar);
            foo->bar->foo=foo;
            auto spW =std::make_shared<point>();
            std::weak_ptr<point> w(spW);
//            std::cout<<*w<<std::endl;//ERROR
            std::cout<<*w.lock()<<std::endl;
            std::cout<<w.expired()<<std::endl;
        }
    }
    return 0;
}
