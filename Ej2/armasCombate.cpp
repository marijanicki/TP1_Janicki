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

void armasCombate::setPeso(float peso){
    this->peso = peso;
}
armasCombate::~armasCombate(){}

//------------------------------------------ armas
hacha_simple::hacha_simple() : armasCombate("Hacha Simple", "Combate", 7,2.5,5){}
hacha_simple::hacha_simple(string nombre) : armasCombate(nombre, "Combate", 7,2.5,5){}
void hacha_simple::desmembrar(){
    cout<<"Realiza una herida de gravedad al enemigo pero no es letal"<<endl;
}
hacha_simple::~hacha_simple(){};

hacha_doble::hacha_doble() : armasCombate("Hacha Doble", "Combate", 10, 4.5, 6){}
hacha_doble::hacha_doble(string nombre) : armasCombate(nombre, "Combate", 10, 4.5, 6){}
void hacha_doble::ataque_doble(){
    cout<<"Realizas dos ataque consecutivos con tu hacha generando el doble de daño"<<endl;
}
hacha_doble::~hacha_doble(){};

espada::espada() : armasCombate("Espada", "Combate", 12,1.5, 8){}
espada::espada(string nombre) : armasCombate(nombre, "Combate", 12,1.5, 8){}
void espada::filo_divino(){
    cout<<"Inviertes una gran cantidad de maná y mejoras tu espada subiendole 4 veces su letalidad gracias a su filo divino."<<endl;
}
espada::~espada(){};

lanza::lanza() : armasCombate("Lanza", "Combate", 7, 8, 4){}
lanza::lanza(string nombre) : armasCombate(nombre, "Combate", 7, 8, 4){}
void lanza::duplicar_tamaño(){
    cout<<"Duplicas el tamaño de tu lanza temporalmente para poder realizar ataque a larga distancia."<<endl;
    setTamaño(getTamaño()*2);
}
void lanza::setTamaño(float tamaño){
    this->tamaño = tamaño;
}
float lanza::getTamaño(){
    return tamaño;
}
lanza::~lanza(){}

garrote::garrote() : armasCombate("Garrote", "Combate", 15, 10,3){}
garrote::garrote(string nombre) : armasCombate(nombre, "Combate", 15, 10,3){}
void garrote::demoledor(){
    cout<<"Aumentas el peso significativamente del garrote marcando una gran diferencia en la pelea de manera temporal."<<endl;
    setPeso(getPeso()*3);
}
garrote::~garrote(){};