#include "Iarmas.hpp"
#include "itemsMagicos.hpp"
#include <iostream>
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
baston::baston() : items_magicos("Baston", "Items magicos", 5, 7, 7){}
baston::baston(string name) : items_magicos(name, "Items magicos", 5, 7, 7){}
void baston::baston_temporal(){
    cout<<"Tienes la oportunidad de reparar lo roto. Vuelve a intentar tu último ataque"<<endl;
}
baston::~baston(){};


libro::libro() : items_magicos("Libro de hechizos", "Items magicos", 15, 15, 4){}
libro::libro(string name) : items_magicos(name, "Items magicos", 15, 15, 4){} //revisar numeros
//tienen poca durabilidad porq su ataque es muy alto, en caso tiene ventaja al principio pero si se cansa y pierde su mana es muy debil
void libro::revelacion(){
    cout<<"Se aparece frente a ti una revelación de como seran los prozimos 3 ataques de tu enemigo. Utiliza la sabiduria brindadá por el libro audazmente."<<endl;
}
libro::~libro(){}

pocion::pocion() : items_magicos("Pocion", "Items magicos", 20, 10, 5){}
pocion::pocion(string name) : items_magicos(name, "Items magicos", 20, 10, 5){} //cansa mucho al q la usa
void pocion::frost(){
    cout<<"La poción congelada hizo que se congele tu enemigo. Aprovecha y ataca sin posibilidad de que tu enemigo se defienda"<<endl;
}
pocion::~pocion(){}

amuleto::amuleto() : items_magicos("Amuleto", "Items magicos", 8, 10, 8){}
amuleto::amuleto(string name) : items_magicos(name, "Items magicos", 8, 10, 8){}
void amuleto::amuleto_del_vacio(){
    cout<<"Tu amuleto te volió por esta ronda inmune a los hechizos. Te encuentras a salvo de ataque mágicos"<<endl;

}
amuleto::~amuleto(){}
