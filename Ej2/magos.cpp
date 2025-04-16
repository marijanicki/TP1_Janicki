#include "Ipersonajes.hpp"
#include "Iarmas.hpp"

#include "magos.hpp"
#include <iostream>
using namespace std;
class armas;

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
    }
}

int magos::ataque(armas* arma){
    float daño_TT =0;
    if(arma->getDurabilidad() == 0){
        daño_TT = 10; //si mi arma se encuentra rota debido al uso, solo hace el ataque basico, ya no tiene poder
    }
    else{
        //si el arma es de combate le sumo el peso del arma
        if(arma->get_armaType() == "Combate"){
            armasCombate* arma_combate = dynamic_cast<armasCombate*>(arma);
            //shared_ptr<armasCombate> arma_combate = dynamic_pointer_cast<armasCombate>(arma);
            daño_TT = 10+ arma->getpower()/3 + (arma_combate->getPeso()*0.5); //mi mago no tiene agilidad entonces se le va a dificultar poder usar bien un arma de combate
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

size_t magos::getSizeArma(){
    return armas_pj.size();
}

magos::~magos(){}

hechicero::hechicero() :magos("Hechicero", "magos", 100){};
hechicero::hechicero(string name) : magos(name, "magos", 100){};
void hechicero::expelliarmus(){
    cout<<"Expelliarmus, desarmaste a tu enemigo por una ronda."<<endl;
}
hechicero::~hechicero(){};

conjurador::conjurador() : magos("Conjurador", "magos", 80){};
conjurador::conjurador(string name) : magos(name, "magos", 80){};
void conjurador::portal_menor(){
    cout<<"Abres un portal menor que te ayuda a escapar del ataque"<<endl;
}
conjurador::~conjurador(){}

brujo::brujo() : magos("Brujo", "magos", 60){};
brujo::brujo(string name) : magos(name, "magos", 60){};
void brujo::pacto_oscuro(){
    setHp(getHp()/2);
    cout<<"Sacrificas la mitad de tu vida pero duplica su daño de manera temporal"<<endl;
}
brujo::~brujo(){}

nigromante::nigromante() : magos("Nigromante", "magos", 120){};
nigromante::nigromante(string name) : magos(name, "magos", 120){};
void nigromante::resucitar(){
    cout<<"Llamas a la pelea por una ronda a todos los enemigos que venciste en tu favor. CUIDADO! Consume muy rápidamente tu maná"<<endl;
}
void nigromante::robar_vida(unique_ptr<personajes> enemy){
    setHp(enemy->getHp()/4); 
    //solo se puede utilizar una vez. Se debería implementar en una dinámica de juego real
    cout<<"Te robas un 1/4 del alma de tu rival.\nAgotaste todas las posibilidades de utilizar esta acción."<<endl;
}
nigromante::~nigromante(){};