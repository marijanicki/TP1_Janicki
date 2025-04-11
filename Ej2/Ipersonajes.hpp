#include "Iarmas.hpp"
#include <string>
#include <memory>

using namespace std;


class personajes{
    virtual string getName() = 0;
    virtual string getType() = 0;
    virtual void setHp(int new_hp) =0;
    virtual int getHp() = 0;
    virtual void setMana(int new_mana)=0; 
    virtual int getMana() = 0;
    virtual void afinidad_arma(shared_ptr<armas> arma) = 0;
    virtual void afinidad_enemy(shared_ptr<personajes> enemy) = 0;
    virtual int ataque(shared_ptr<armas> arma) =0;
    virtual void appendArma(shared_ptr<armas>) = 0;
    virtual int recibirdaño(int daño) = 0;
};