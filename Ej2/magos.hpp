#pragma once
#include "Ipersonajes.hpp"
#include <string>
#include <vector>
#include <memory>

using namespace std; 

class magos:public personajes{
    public:
    virtual string getName() = 0;
    virtual string getType() = 0;
    virtual int getHp() = 0; 
    virtual int afinidad_arma() = 0;
    virtual int afinidad_enemy() = 0;
    virtual void ataque() =0;

    private:
        string name;
        string type;
        int hp;
        int mana;
        int status; //cuanto lo atacaron 
        vector<shared_ptr<armas>> armas;

}