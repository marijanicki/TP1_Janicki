#include "Iarmas.hpp"
#include "armasCombate.hpp"

#include <string>

using namespace std;

armasCombate::armasCombate(string nombre, string type, int daño, float peso, int durabilidad){
    this->nombre = nombre;
    this->type = type;
    this->daño = daño;
    this->peso = peso;
    this->durabilidad = durabilidad;
}
string armasCombate::getName(){
    return nombre;
}
string armasCombate::get_armaType(){
    return type;
}
int armasCombate::getpower(){
    return daño;
}
int armasCombate::getDesgaste(){
    return peso;
}
void armasCombate::setPower(int daño){
    this->daño = daño;
}
void armasCombate::setDurabilidad(){
    this->durabilidad = durabilidad-1; //cada vez que ataco mi arma se rompe un poquito
}
int armasCombate::getDurabilidad(){
    return durabilidad;
}

float armasCombate::getPeso(){
    return peso;
}

armasCombate::~armasCombate(){}