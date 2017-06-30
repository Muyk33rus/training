#include "abstractfactory.h"
int main ()
{
    Game game;
    RomanArmyFactory ra_factory;
    CarthaginianArmyFactory ca_factory;

    Army * ra = game.createArmy( ra_factory);
    Army * ca = game.createArmy( ca_factory);
    cout << "Roman army:" << endl;
    ra->info();
    cout << "\nCarthaginian army:" << endl;
    ca->info();
}
