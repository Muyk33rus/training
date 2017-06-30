#include "prototype.h"
int main ()
{
    PrototypeFactory factory;
      vector<Warrior*> v;
      v.push_back( factory.createInfantrman());
      v.push_back( factory.createArcher());
      v.push_back( factory.createHorseman());

     for(auto i: v)
       i->info();
}
