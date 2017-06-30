#include "factorymethod.h"
#include "factorymetho_classic.h"
int main ()
{
    vector<Warrior*> v;
// Создание объектов при помощи параметризированного фабричного метода
    v.push_back( Warrior::createWarrior( Infantryman_ID));
    v.push_back( Warrior::createWarrior( Archer_ID));
    v.push_back( Warrior::createWarrior( Horseman_ID));
    v.push_back( Warrior::createWarrior( Warrior_ID::LightHorseman_ID));

// Создание объектов при помощи параметризированного фабричного метода
    InfantryFactory* infantry_factory = new InfantryFactory;
    ArchersFactory*  archers_factory  = new ArchersFactory ;
    CavalryFactory*  cavalry_factory  = new CavalryFactory ;
    LightCavalryFactory*  lightcavalry_factory  = new LightCavalryFactory ;
    TemplateFactory<Infantryman>* template_factory= new TemplateFactory<Infantryman>;
    v.push_back( infantry_factory->createWarrior());
    v.push_back( archers_factory->createWarrior());
    v.push_back( cavalry_factory->createWarrior());
    v.push_back( lightcavalry_factory->createWarrior());
    v.push_back( template_factory->create());
    for(auto i:v)
        i->info();
}
