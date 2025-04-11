#pragma once
#include "Iarmas.hpp"

#include <string>
using namespace std;

class armasCombate : public armas{
    protected:
        string nombre;
        string type;
        int daño;
        int durabilidad;
        float peso;
    public:
        armasCombate(string name, string type, int daño, float peso, int durabilidad);
        virtual string getName()override;
        virtual int getpower()override;
        virtual string get_armaType()override;
        virtual void setDurabilidad()override;
        virtual int getDurabilidad()override;
        virtual int getDesgaste()override;
        virtual void setPower(int poder_magico)override;
        virtual float getPeso()override; 
        virtual  ~armasCombate();
};

class hacha_simple : public armasCombate{
    public: 
        hacha_simple(string name);
};

class hacha_doble : public armasCombate{
    public: 
        hacha_doble(string name);
};
class espada : public armasCombate{
    public: 
        espada(string name);
};
class lanza : public armasCombate{
    public: 
        lanza(string name);
};
class garrote : public armasCombate{
    public: 
        garrote(string name);
};
