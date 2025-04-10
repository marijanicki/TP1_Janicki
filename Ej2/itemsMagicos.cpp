#include "interfaz.hpp"
#include "itemsMagicos.hpp"

#include <string>

items_magicos::items_magicos(string nombre, string type, int poder_magico, int desgasteMana, int durabilidad){
    this->nombre = nombre;
    this->type = type;
    this->desgaste_mana = desgaste_mana;
    this->poder_magico = poder_magico;
    this->durabilidad = durabilidad;
}

string items_magicos::getName(){
    return nombre;
}
string items_magicos::get_armaType(){
    return type;
}