#pragma once
#include "Iarmas.hpp"
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class personajes{
    public:
        virtual string getName() = 0;
        virtual string getType() = 0;
        virtual void setHp(int new_hp) =0;
        virtual int getHp() = 0;
        virtual armas* getArma(size_t pos)=0;
        virtual size_t getSizeArma()=0;
        virtual void setEnergia(int new_cant_energ)=0; 
        virtual int getEnergia() = 0;
        virtual void afinidad_arma(unique_ptr<armas> arma) = 0;
        //virtual void afinidad_enemy(shared_ptr<personajes> enemy) = 0;
        virtual int ataque(armas* arma) =0;
        virtual void appendArma(unique_ptr<armas> arma) = 0;
        virtual void recibirdaño(int daño) = 0;
        virtual bool isDead()=0;
        virtual ~personajes() {};
};