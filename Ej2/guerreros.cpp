#include "Ipersonajes.hpp"
#include "Iarmas.hpp"

#include "guerreros.hpp"

using namespace std;
class armas;

guerreros::guerreros(string name, string type, int agilidad){
    this->name = name;
    this->type = type;
    this->agilidad = agilidad;
    hp = 100;
}

string guerreros::getName(){return name;}

string guerreros::getType(){return type;}

void guerreros::setHp(int new_hp){this->hp = new_hp;}

int guerreros::getHp(){return hp;}

void guerreros::setEnergia(int new_cant_energ){
    this->agilidad = new_cant_energ;
} 
int guerreros::getEnergia(){
    return agilidad;
}

void guerreros::appendArma(unique_ptr<armas> arma){
    armas_pj.push_back(move(arma));
}

void guerreros::afinidad_arma(unique_ptr<armas> arma){
    if(type == arma->get_armaType()){
        arma->setPower(arma->getpower()+5); //si sos un tipo de mago junto a objetos de magia se te aumenta un poco el daño 
        //Cada personaje además tiene sus armas especificas con mayor afinidad
    }
}

int guerreros::ataque(armas* arma){
    float daño_TT =0;
    if(arma->getDurabilidad() == 0){
        daño_TT = 10; //si mi arma se encuentra rota debido al uso, solo hace el ataque basico, ya no tiene poder
    }
    else{
        //si el arma es de combate le sumo el peso del arma
        if(arma->get_armaType() == "Combate"){
            armasCombate* arma_combate = dynamic_cast<armasCombate*>(arma);
            daño_TT = 10+ arma->getpower() + (arma_combate->getPeso()*0.5); 
        }
        else{
            //seria un item magico
            daño_TT = 10+ arma->getpower()*(1/3); //al no ser un arma de la especialidad de los guerreros no son tan efectivas, no pueden aprovecharlas por no tener mana
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

void guerreros::recibirdaño(int daño){
    setHp(getHp()-daño);
}

bool guerreros::isDead(){
    if(getHp()<=0){
        return true;
    }
    return false;
}

armas* guerreros::getArma(size_t pos){
    return armas_pj[pos].get();
}

size_t guerreros::getSizeArma(){
    return armas_pj.size();
}

guerreros::~guerreros(){}

//-----------------------guerreros
barbaro::barbaro() : guerreros("Barbaro", "Guerrero", 100){}
barbaro::barbaro(string nombre) : guerreros(nombre, "Guerrero", 100){}
void barbaro::derriba_montañas(){
    setEnergia(getEnergia()*2); //duplica tu energia
}
barbaro::~barbaro(){}

paladin::paladin() : guerreros("Paladin", "Guerrero", 70){}
paladin::paladin(string nombre) : guerreros(nombre, "Guerrero", 70){}
void paladin::curacion_divina(){
    setHp(getHp()*(1/4)); //te cura un poco tu vida
}
paladin::~paladin(){}

caballero::caballero() : guerreros("Caballero", "Guerreros", 60){}
caballero::caballero(string nombre) : guerreros(nombre, "Guerreros", 60){}
void caballero::oscuridad_total(){
    cout<<"La oscuridad te envuelve apuestas todo o nada. Triplicas tus habilidades pero con el riesgo de que si fallas mueres"<<endl;
    setEnergia(getEnergia()*3);
}
caballero::~caballero(){}

mercenario::mercenario() : guerreros("Mercenario", "Guerrero", 90){}
mercenario::mercenario(string nombre) : guerreros(nombre, "Guerrero", 90){}
void mercenario::setMonedas(float monedas){
    this->monedas = monedas;
}
float mercenario::getMonedas(){
    return monedas;
}
void mercenario::intercambio(int cant_cambio){
    cout<<"Sacrificas una parte de tu poder adquisito para sobrevivir y buscar más riquezas"<<endl;
    setHp(getHp()+cant_cambio);
    setMonedas(getMonedas()-cant_cambio);
}
mercenario::~mercenario(){}

gladiador::gladiador() : guerreros("Gladiador", "Guerrero", 110){}
gladiador::gladiador(string nombre) : guerreros(nombre, "Guerrero", 110){}
gladiador::~gladiador(){}