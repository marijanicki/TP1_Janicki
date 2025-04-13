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
        virtual void afinidad_arma(unique_ptr<armas> arma)override;
        //virtual void afinidad_enemy(shared_ptr<personajes> enemy)override;
        virtual int ataque(armas* arma)override;
        virtual void appendArma(unique_ptr<armas> arma)override;
        virtual void recibirdaño(int daño)override;
        virtual bool isDead()override;
        virtual armas* getArma(size_t pos)override;
        virtual  ~guerreros();
    protected:
        string name;
        string type;
        int hp;
        int agilidad;
        vector<unique_ptr<armas>> armas_pj;
};

class barbaro : public guerreros{
    public: 
        barbaro();
        barbaro(string nombre);
};

class paladin : public guerreros{
    public: 
        paladin();
        paladin(string nombre);
};
class caballero : public guerreros{
    public: 
        caballero();
        caballero(string nombre);
};
class merceneario : public guerreros{
    public: 
        merceneario();
        merceneario(string nombre);
};
class gladiador : public guerreros{
    public: 
        gladiador();
        gladiador(string nombre);
};