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

void magos::setEnergia(int new_cant_energ){
    this->mana = new_cant_energ;
} 
int magos::getEnergia(){
    return mana;
}

void magos::appendArma(unique_ptr<armas> arma){
    armas_pj.push_back(move(arma));
}

void magos::afinidad_arma(unique_ptr<armas> arma){
    if(type == arma->get_armaType()){
        arma->setPower(arma->getpower()+5); //si sos un tipo de gu junto a objetos de magia se te aumenta un poco el daño 
        //Cada personaje además tiene sus armas especificas con mayor afinidad
    }
}

int magos::ataque(unique_ptr<armas>& arma){
    float daño_TT =0;
    if(arma->getDurabilidad() == 0){
        daño_TT = 10; //si mi arma se encuentra rota debido al uso, solo hace el ataque basico, ya no tiene poder
    }
    else{
        //si el arma es de combate le sumo el peso del arma
        if(arma->get_armaType() == "Combate"){
            armasCombate* arma_combate = dynamic_cast<armasCombate*>(arma.get());
            //shared_ptr<armasCombate> arma_combate = dynamic_pointer_cast<armasCombate>(arma);
            daño_TT = 10+ arma->getpower()*(1/3) + (arma_combate->getPeso()*0.5); //mi mago no tiene agilidad entonces se le va a dificultar poder usar bien un arma de combate
        }
        else{
            //seria un item magico
            daño_TT = 10+ arma->getpower(); 
        }
    }
   
    if(getEnergia() < 30){
        daño_TT = daño_TT / 2; //al tener una cantidad muy poca de mana el ataque se vuelve muchisimo menos fuerte
        if(getEnergia() <= 20) {
            setHp(getHp()-1); //al tener poco mano, eso lo agota y le consume un poquito de vida atacar
        }
    }

    //consecuencias
    setEnergia(getEnergia()-arma->getDesgaste()); //al mana total le resto el mana que me consume mi arma pero como resultado de atacar, es decir, no me va a afectar en este turno sino en el otro
    arma->setDurabilidad();

    return daño_TT;
}

/*
void magos::afinidad_enemy(shared_ptr<personajes> enemy){
    if(enemy->getType() == type){

    }
}*/

void magos::recibirdaño(int daño){
    setHp(getHp()-daño);
}
bool magos::isDead(){
    if(getHp()<=0){
        return true;
    }
    return false;
}
armas* magos::getArma(size_t pos){
    return armas_pj[pos].get();
}
magos::~magos(){}

hechicero::hechicero() :magos("Hechicero", "magos", 100){};
hechicero::hechicero(string name) : magos(name, "magos", 100){};

conjurador::conjurador() : magos("Conjurador", "magos", 80){};
conjurador::conjurador(string name) : magos(name, "magos", 80){};

brujo::brujo() : magos("Brujo", "magos", 60){};
brujo::brujo(string name) : magos(name, "magos", 60){};

nigromante::nigromante() : magos("Nigromante", "magos", 120){};
nigromante::nigromante(string name) : magos(name, "magos", 120){};