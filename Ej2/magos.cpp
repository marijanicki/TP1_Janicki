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
}

string magos::getName(){return name;}

string magos::getType(){return type;}

void magos::setHp(int new_hp){this->hp = new_hp;}

int magos::getHp(){return hp;}

void magos::setMana(int new_mana){
    this->mana = new_mana;
} 
int magos::getMana(){
    return mana;
}

void magos::appendArma(shared_ptr<armas> arma){
    armas_pj.push_back(arma);
}

void magos::afinidad_arma(shared_ptr<armas> arma){
    if(type == arma->get_armaType()){
        arma->setPower(arma->getpower()+5); //si sos un tipo de mago junto a objetos de magia se te aumenta un poco el daño 
        //Cada personaje además tiene sus armas especificas con mayor afinidad
    }
}

int magos::ataque(shared_ptr<armas> arma){
    int daño_TT;
    if(arma->getDurabilidad() == 0){
        arma->setPower(0);
        daño_TT = 10; //si mi arma se encuentra rota debido al uso, solo hace el ataque basico, ya no tiene poder
    }
    else{
        daño_TT = arma->getpower()+10;
    }

    if(getMana() < 20){
        daño_TT = daño_TT / 4; //al tener una cantidad muy poca de mana el ataque se vuelve muchisimo menos fuerte
        if(getMana() < 10) {
            setHp(getHp()-1); //al tener poco mano, eso lo agota y le consume un poquito de vida atacar
        }
    }
    else if(getMana() >= 20 && getMana()<= 40){
        daño_TT = daño_TT /2; //se le baja el ataque pero no tanto, en este turno
    }
    
    setMana(getMana()-arma->getDesgaste()); //al mana total le resto el mana que me consume mi arma pero como resultado de atacar, es decir, no me va a afectar en este turno sino en el otro
    arma->setDurabilidad();

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