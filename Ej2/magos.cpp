#include "Ipersonajes.hpp"
#include "Iarmas.hpp"

#include "magos.hpp"

using namespace std;
class armas;
//preguntar armas como hacer, vector<shared_ptr<armas>> armas
magos::magos(string name, string type, int mana){
    this->name = name;
    this->type = type;
    this->mana = mana;
    hp = 100;
    status = 0;
}

string magos::getName(){return name;}

string magos::getType(){return type;}

void magos::setHp(int new_hp){this->hp = new_hp;}

int magos::getHp(){return hp;}

void magos::appendArma(shared_ptr<armas> arma){
    armas_pj.push_back(arma);
}

void magos::afinidad_arma(shared_ptr<armas> arma){
    if(type == arma->get_armaType()){
        arma->setPower(arma->getpower()+5); //si sos un tipo de mago junto a objetos de magia se te aumenta un poco el daño 
        //Cada personaje además tiene sus armas especificas con mayor afinidad
    }
}

int magos::ataque(string tipo_ataque, shared_ptr<armas> arma){

    int daño_TT = arma->getpower()+10;
    return daño_TT;
}
/*
void magos::afinidad_enemy(shared_ptr<personajes> enemy){
    if(enemy->getType() == type){

    }
}*/

int magos::recibirdaño(int daño){
    setHp(getHp()-daño);
}
hechicero::hechicero(string name) : magos(name, "magos", 100){};

conjurador::conjurador(string name) : magos(name, "magos", 80){};

brujo::brujo(string name) : magos(name, "magos", 60){};

nigromante::nigromante(string name) : magos(name, "magos", 120){};