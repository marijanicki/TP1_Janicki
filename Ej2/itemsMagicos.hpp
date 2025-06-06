#pragma once
#include "Iarmas.hpp"

#include <string>
using namespace std;
//clases abstractas
class items_magicos:public armas{
    protected:
        string nombre;
        string type;
        int poder_magico;
        int durabilidad;
        int consumo_mana;
        
    public:
        //constructor
        items_magicos(string nombre, string type, int consumo_mana, int poder_magico,  int durabilidad);
        virtual string getName()override;
        virtual int getpower()override;
        virtual string get_armaType()override;
        virtual void setDurabilidad()override;
        virtual int getDurabilidad()override;
        virtual int getDesgaste()override; //devuelve el consumo de mana
        virtual void setPower(int poder_magico)override;
        virtual  ~items_magicos();
};

class baston : public items_magicos{
    public:
        baston();
        baston(string name);
        void baston_temporal();
        ~baston();
};

class libro : public items_magicos{
    public:
        libro();
        libro(string name);
        void revelacion();
        ~libro();
};
class pocion : public items_magicos{
    public:
        pocion();
        pocion(string name);
        void frost();
        ~pocion();
};
class amuleto : public items_magicos{
    public:
        amuleto();
        amuleto(string name);
        void amuleto_del_vacio();
        ~amuleto();
};
