#include "singleton.h"
int main ()
{
    Singleton * one =Singleton::getInstance();
    one->info();
    Singleton * two =Singleton::getInstance();
    two->info();
}
