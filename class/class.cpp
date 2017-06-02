#include <iostream>
using namespace std;

class c{
    int a;
public:
   c():a(0){
        cout<<"ini C ";
    }
   ~c(){
       cout<<"des C ";
   }
};

class d
{
    mutable int a;
public:
    d(int a){
        this->a=a;
        cout<<"ini D ";
    }
    ~d(){
        cout<<"des D ";
    }
   inline int GetA()const{return this->a;}
   void Add (int add)const{
       a+=add;
   }
};

class a
{
    c objC;
public:
    a() {
        cout<<"ini A ";
    }
    virtual ~a(){
        cout<<"des A ";
    }
    virtual void foo(){
        bar();
        cout<<"foo A ";
    }
    void bar(){
//        foo();
        cout<<"bar A ";
    }
};

class b:public a
{
    d objD=d(7);
public:
    b():a() {
       cout<<"ini B ";
    }
    ~b(){
        cout<<"des B ";
    }
    void foo(){
        bar();
        cout<<"foo B ";
    }
    void bar(){
//        foo();
        cout<<"bar B ";
    }
     b operator =(b &objb){
        this->objD=objb.objD;
        return *this;
    }
};

int main(){
    a* obja1 = new a;
    cout<<endl;
    a* obja2 = new b;
    cout<<endl;
    b* objb  = new b;
    cout<<endl;
    const d objd(5);
    cout<<endl;
    
    cout<<"const objd.a ="<<objd.GetA()<<endl;
    objd.Add(4);
    cout<<"const objd.a ="<<objd.GetA()<<endl;
    
    obja1->foo();
    cout<<endl;
    obja2->foo();
    cout<<endl;
    objb->foo();
    cout<<endl;

    obja1->bar();
    cout<<endl;
    obja2->bar();
    cout<<endl;
    objb->bar();
    cout<<endl;
   
    delete obja1;
    cout<<endl;
    delete obja2;
    cout<<endl;
    delete objb;
}
