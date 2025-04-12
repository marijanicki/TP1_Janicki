#include <cstdlib>
#include <ctime>
#include <iostream>
#include "factory.hpp"
#include "../Ej2/Iarmas.hpp"
#include "../Ej2/Ipersonajes.hpp"
#include "../Ej2/itemsMagicos.hpp"
#include "../Ej2/armasCombate.hpp"
#include "../Ej2/magos.hpp"
#include "../Ej2/guerreros.hpp"

using namespace std;



int main(){
    srand(time(NULL));
    int cant_magos = 3 + rand() % (7-3+1) ;
    int cant_guerreros = 3 + rand() % (7-3+1) ;
    cout <<"cant_magos" << cant_magos <<"\ncant guerreros" <<cant_guerreros <<endl;
    int cant_armas_magos = 0+ rand() % (2-0+1) ;
    int cant_armas_guerreros = 0+ rand() % (2-0+1) ;
    cout << cant_armas_magos <<"\n" <<cant_armas_guerreros<<endl;

    vector<PERSONAJES> magos;
    vector<PERSONAJES> guerreros;
    vector<unique_ptr<personajes>> magos_fact;
    vector<unique_ptr<personajes>> guerreros_fact;
    //voy a elegir de manera aleatoria que personajes de magos y guerreros creo segun la cantidad y los añado en el vector
    for(int i = 0; i < cant_magos; i++){
        int rand_mago = 0 + rand() % (3-0+1);
        cout <<"tipo magos"<<rand_mago<<endl;
        magos.push_back(static_cast<PERSONAJES>(rand_mago)); //obtengo los magos q quiero crear
    }
    for(int i = 0; i < cant_magos; i++){
        magos_fact.push_back(PersonajeFactory::make_personaje(magos[i]));
    }
    for(int i = 0; i < cant_magos; i++){
       cout<< magos_fact[i]->getName()<<endl;
       //cout << magos_fact[i]->getArma(0)->getName(); no tiene arma 
    }
    /*
    cout << PersonajeFactory::make_personaje(PERSONAJES::hechicero)->getName()<<endl;
    
    vector<ARMAS> armasP = {ARMAS::baston, ARMAS::garrote};
    cout << PersonajeFactory::make_personajeArmado(PERSONAJES::nigromante, armasP)->getArma(0)->getName()<<endl;
*/
}