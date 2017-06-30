#include "factorymethod.h"


// Реализация параметризированного фабричного метода
Warrior* Warrior::createWarrior( Warrior_ID id )
{
    Warrior * p=nullptr;
    switch (id)
    {
        case Infantryman_ID:
            p = new Infantryman();
            break;
        case Archer_ID:
            p = new Archer();
            break;
        case Horseman_ID:
            p = new Horseman();
            break;
        case LightHorseman_ID:
            p = new LightHorseman();
            break;
        default:
            assert( false);
    }
    return p;
}
