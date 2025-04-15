#pragma once
#include <string>

using namespace std;

class armas{
    public:
        virtual string getName() = 0;
        virtual int getpower() = 0;
        virtual string get_armaType()=0;
        virtual void setDurabilidad() =0;
        virtual int getDurabilidad() = 0;
        virtual int getDesgaste()=0;
        virtual void setPower(int poder_magico)=0; 
        //virtual float getPeso()=0;    
        virtual ~armas(){};
};