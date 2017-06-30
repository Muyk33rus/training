#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

enum Warrior_ID { Infantryman_ID=0, Archer_ID, Horseman_ID,LightHorseman_ID, Animal_ID };

// Иерархия классов игровых персонажей
class Warrior
{
  public:
    virtual void info() = 0;
    virtual ~Warrior() {}
    // Параметризированный статический фабричный метод
    static Warrior* createWarrior( Warrior_ID id );
};

class Infantryman: public Warrior
{
  public:
    void info() {
      cout << "Infantryman" << endl;
    }
};

class Archer: public Warrior
{
  public:
    void info() {
      cout << "Archer" << endl;
    }
};

class Horseman: public Warrior
{
  public:
    void info() {
      cout << "Horseman" << endl;
    }
};

class LightHorseman: public Horseman
{
  public:
    void info() {
      cout << "LightHorseman" << endl;
    }
};
#endif // FACTORYMETHOD_H
