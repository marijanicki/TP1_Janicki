#include "Iarmas.hpp"
#include <string>

using namespace std;

class personajes{
    virtual string getName() = 0;
    virtual string getType() = 0;
    virtual int getHp() = 0; 
    virtual int afinidad_arma() = 0;
    virtual int afinidad_enemy() = 0;
    virtual void ataque() =0;
};