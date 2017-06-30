#ifndef SINGLETON_H
#define SINGLETON_H

#include "iostream"
class Singleton;  // опережающее объявление

class SingletonDestroyer
{
  private:
    Singleton* p_instance;
  public:
    ~SingletonDestroyer();
    void initialize( Singleton* p );
};

class Singleton
{
  private:
    static Singleton* p_instance;
    static SingletonDestroyer destroyer;
  protected:
    Singleton() { }
    Singleton( const Singleton& );
    Singleton& operator=( Singleton& );
   ~Singleton() {std::cout<<"delete Singleton"<<std::endl; }
    friend class SingletonDestroyer;
  public:
    static Singleton* getInstance();
    void info(){std::cout<<"Singleton info"<<std::endl;};
};

#endif // SINGLETON_H
