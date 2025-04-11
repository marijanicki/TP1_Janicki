#pragma once
#include "Ipersonajes.hpp"
#include "Iarmas.hpp"
#include "itemsMagicos.hpp"
#include <memory>
#include <string>
#include <vector>

using namespace std; 
 
class magos:public personajes{
    public:
        magos(string name, string type, int mana);
        virtual string getName()override;
        virtual string getType()override;
        virtual int getHp()override; 
        virtual void setHp(int new_hp)override;
        virtual void afinidad_arma(shared_ptr<armas> arma)override;
        //virtual void afinidad_enemy(shared_ptr<personajes> enemy)override;
        virtual int ataque(string tipo_ataque, shared_ptr<armas> arma)override;
        virtual void appendArma(shared_ptr<armas> arma)override;
        virtual int recibirdaño(int daño)override;
        virtual  ~magos();
    private:
        string name;
        string type;
        int hp;
        int mana;
        int status; //cuanto lo atacaron 
        vector<shared_ptr<armas>> armas_pj;

};

class hechicero: public magos{
    public:
        hechicero(string name);
    private:
        string name;
        int mana;
};

class conjurador: public magos{
    public:
        conjurador(string name);
    private:
        string name;
        int mana;
};

class brujo: public magos{
    public:
        brujo(string name);
    private:
        string name;
        int mana;
};

class nigromante: public magos{
    public:
        nigromante(string name);
    private:
        string name;
        int mana;
};