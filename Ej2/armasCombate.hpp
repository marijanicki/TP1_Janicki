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
        virtual float getPeso(); 
        virtual void setPeso(float peso);
        virtual  ~armasCombate();
};

class hacha_simple : public armasCombate{
    public:
        hacha_simple(); 
        hacha_simple(string name);
        void desmembrar();
        ~hacha_simple();
};

class hacha_doble : public armasCombate{
    public: 
        hacha_doble();
        hacha_doble(string name);
        void ataque_doble();
        ~hacha_doble();
};
class espada : public armasCombate{
    public: 
        espada();
        espada(string name);
        void filo_divino();
        ~espada();
};
class lanza : public armasCombate{
    public: 
        lanza();
        lanza(string name);
        void duplicar_tamaño();
        void setTamaño(float tamaño);
        float getTamaño();
        ~lanza();
    private:
        float tamaño;
};
class garrote : public armasCombate{
    public: 
        garrote();
        garrote(string name);
        void demoledor();
        ~garrote();
};
