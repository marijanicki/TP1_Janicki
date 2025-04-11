#pragma once
#include "Ipersonajes.hpp"
#include "Iarmas.hpp"
#include "itemsMagicos.hpp"
#include "armasCombate.hpp"
#include <memory>
#include <string>
#include <vector>

using namespace std; 
 
class guerreros:public personajes{
    public:
        guerreros(string name, string type, int agilidad);
        virtual string getName()override;
        virtual string getType()override;
        virtual int getHp()override; 
        virtual void setHp(int new_hp)override;
        virtual void setEnergia(int new_cant_energ)override; 
        virtual int getEnergia()override;
        virtual void afinidad_arma(shared_ptr<armas> arma)override;
        //virtual void afinidad_enemy(shared_ptr<personajes> enemy)override;
        virtual int ataque(shared_ptr<armas> arma)override;
        virtual void appendArma(shared_ptr<armas> arma)override;
        virtual void recibirdaño(int daño)override;
        virtual  ~guerreros();
    protected:
        string name;
        string type;
        int hp;
        int agilidad;
        vector<shared_ptr<armas>> armas_pj;
};

class barbaro : public guerreros{
    public: 
        barbaro(string nombre);
};

class paladin : public guerreros{
    public: 
        paladin(string nombre);
};
class caballero : public guerreros{
    public: 
        caballero(string nombre);
};
class merceneario : public guerreros{
    public: 
        merceneario(string nombre);
};
class gladiador : public guerreros{
    public: 
        gladiador(string nombre);
};