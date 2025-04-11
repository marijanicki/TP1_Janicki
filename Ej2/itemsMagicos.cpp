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

items_magicos::~items_magicos(){}
//-------------armas
baston::baston(string name) : items_magicos(name, "Items magicos", 5, 7, 7){}

libro::libro(string name) : items_magicos(name, "Items magicos", 15, 15, 4){} //revisar numeros
//tienen poca durabilidad porq su ataque es muy alto, en caso tiene ventaja al principio pero si se cansa y pierde su mana es muy debil

pocion::pocion(string name) : items_magicos(name, "Items magicos", 20, 10, 5){} //cansa mucho al q la usa

amuleto::amuleto(string name) : items_magicos(name, "Items magicos", 8, 10, 8){}

