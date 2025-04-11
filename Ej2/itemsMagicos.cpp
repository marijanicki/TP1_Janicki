#include "Iarmas.hpp"
#include "itemsMagicos.hpp"

#include <string>
using namespace std;
items_magicos::items_magicos(string nombre, string type, int consumo_mana, int poder_magico,  int durabilidad){
    this->nombre = nombre;
    this->type = type;
    this->consumo_mana = consumo_mana;
    this->poder_magico = poder_magico;
    this->durabilidad = durabilidad; //cant de rondas que dura 
}

string items_magicos::getName(){
    return nombre;
}
string items_magicos::get_armaType(){
    return type;
}
int items_magicos::getpower(){
    return poder_magico;
}
int items_magicos::getDesgaste(){
    return consumo_mana;
}
void items_magicos::setPower(int poder_magico){
    this->poder_magico = poder_magico;
}
void items_magicos::setDurabilidad(){
    this->durabilidad = durabilidad-1; //cada vez que ataco mi arma se rompe un poquito
}
int items_magicos::getDurabilidad(){
    return durabilidad;
}

