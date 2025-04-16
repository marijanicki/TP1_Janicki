#pragma once
#include "Ipersonajes.hpp"
#include "Iarmas.hpp"
#include "itemsMagicos.hpp"
#include "armasCombate.hpp"
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
        virtual void setEnergia(int new_cant_energ)override; 
        virtual int getEnergia()override;
        virtual void afinidad_arma(unique_ptr<armas> arma)override;
        
        virtual int ataque(armas* arma)override;
        virtual void appendArma(unique_ptr<armas> arma)override;
        virtual void recibirdaño(int daño)override;
        virtual bool isDead()override;
        virtual armas* getArma(size_t pos)override;
        virtual size_t getSizeArma()override;
        virtual  ~magos();
    protected:
        string name;
        string type;
        int hp;
        int mana;
        vector<unique_ptr<armas>> armas_pj;

};

class hechicero: public magos{
    public:
        hechicero();
        hechicero(string name);
        void expelliarmus(); 
        ~hechicero();

    private:
        float nivel_de_hechiceria;
};

class conjurador: public magos{
    public:
        conjurador();
        conjurador(string name);
        void portal_menor();
        ~conjurador();
    private:
        string name;
        int mana;
};

class brujo: public magos{
    public:
        brujo();
        brujo(string name);
        void pacto_oscuro();
        ~brujo();
    private:
};

class nigromante: public magos{
    public:
        nigromante();
        nigromante(string name);
        void robar_vida(unique_ptr<personajes> enemy);
        void resucitar();
        ~nigromante();
    private:
        string name;
        int mana;
};