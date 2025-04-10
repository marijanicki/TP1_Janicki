#pragma once
#include <string>

using namespace std;

class armas{
    virtual string getName() = 0;
    virtual int getpower() = 0;
    virtual string get_armaType()=0;
    virtual void efectividad(int turno)=0;
    virtual int getDesgaste()=0;
    virtual void decreasePower()=0;
}