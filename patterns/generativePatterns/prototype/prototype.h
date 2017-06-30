#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <vector>
using namespace std;
// Иерархия классов игровых персонажей
// Полиморфный базовый класс
class Warrior
{
  public:
    virtual Warrior* clone() = 0;
    virtual void info() = 0;
    virtual ~Warrior() {}
};


// Производные классы различных родов войск
class Infantryman: public Warrior
{
    friend class PrototypeFactory;
  public:
    Warrior* clone() {
      return new Infantryman( *this);
    }
    void info() {
      cout << "Infantryman" << endl;
    }
  private:
    Infantryman() {}
};

class Archer: public Warrior
{
    friend class PrototypeFactory;
  public:
    Warrior* clone() {
      return new Archer( *this);
    }
    void info() {
      cout << "Archer" << endl;
    }
  private:
    Archer() {}
};

class Horseman: public Warrior
{
    friend class PrototypeFactory;
  public:
    Warrior* clone() {
      return new Horseman( *this);
    }
    void info() {
      cout << "Horseman" << endl;
    }
  private:
    Horseman() {}
};


// Фабрика для создания боевых единиц всех родов войск
class PrototypeFactory
{
  public:
    Warrior* createInfantrman() {
      static Infantryman prototype;
      return prototype.clone();
    }
    Warrior* createArcher() {
      static Archer prototype;
      return prototype.clone();
    }
    Warrior* createHorseman() {
      static Horseman prototype;
      return prototype.clone();
    }
};

#endif // PROTOTYPE_H
