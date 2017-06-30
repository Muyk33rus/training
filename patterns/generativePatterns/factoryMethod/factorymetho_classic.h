#ifndef FACTORYMETHO_CLASSIC_H
#define FACTORYMETHO_CLASSIC_H
#include "factorymethod.h"

// Фабрики объектов
class Factory
{
  public:
    virtual Warrior* createWarrior()=0;
    virtual Warrior* createWarrior( Warrior_ID id );
    virtual ~Factory() {}
};

class InfantryFactory: public Factory
{
  public:
    Warrior* createWarrior() {
      return new Infantryman;
    }
};

class ArchersFactory: public Factory
{
  public:
    Warrior* createWarrior() {
      return new Archer;
    }
};

class CavalryFactory: public Factory
{
  public:
    Warrior* createWarrior() {
      return new Horseman;
    }
};

class LightCavalryFactory: public Factory
{
  public:
    Warrior* createWarrior() {
      return new LightHorseman;
    }
};

template<typename T>
class TemplateFactory
{
public:
    T* create(){
        return new T;
    }
};

#endif // FACTORYMETHO_CLASSIC_H
