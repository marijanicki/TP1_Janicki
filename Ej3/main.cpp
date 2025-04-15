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

void crear_personajes(int cant_pj, vector<ARMAS> armas_factory, vector<unique_ptr<personajes>>& tipo_personaje){
    for(int i = 0; i<cant_pj; i++){
        int rand_mago = 0 + rand() % (3-0+1);
        cout <<"tipo mago: "<<rand_mago<<endl;
        int cant_armas =  0+ rand() % (2-0+1);
        //creo la cant de armas que tocó de manera aleatoria
        for(int j = 0; j<cant_armas;j++){
            int rand_arma = 0 + rand() % (8-0+1);
            cout << "El arma N°"<<j<<" es: "<<rand_arma<<endl;
            armas_factory.push_back(static_cast<ARMAS>(rand_arma)); 
        }
        tipo_personaje.push_back(PersonajeFactory::make_personajeArmado(static_cast<PERSONAJES>(rand_mago), armas_factory));
        armas_factory.clear(); //borro las armas de este mago del vector así uso el mismo vector para el siguiente mago que cree
    }
}


int main(){
    //PRUEBO LOS FACTORY SOLO PERSONAJE Y SOLO ARMA
    //Elijo al azzar que personaje y que arma voy a hacer

    srand(time(NULL));
    int rand_pj = 0 + rand() % (8-0+1);
    cout << "El personaje al azar que salio es: " <<rand_pj<<endl; //agrego esto así verifico que el valor del enum y del que hace es el correcto
    PERSONAJES enum_pj = static_cast<PERSONAJES>(rand_pj);
    unique_ptr<personajes> my_new_pj = PersonajeFactory::make_personaje(enum_pj);
    cout<<"Mi personaje es un " << my_new_pj->getName()<<endl;

    //Pruebo el arma 
    int rand_arma = 0 + rand() % (8-0+1);
    cout<<"\n\nEl arma al azar que salio es: "<<rand_arma<<endl;
    ARMAS enum_arma = static_cast<ARMAS>(rand_arma);
    unique_ptr<armas> my_new_arma = PersonajeFactory::make_arma(enum_arma);
    cout<<"Mi arma es un " << my_new_arma->getName()<<endl;
    

    //Pruebo con una cantidad aleatoria de personajes de cada tipo y con cant aleatoria de armas
    
    vector<unique_ptr<personajes>> magos;
    vector<unique_ptr<personajes>> guerreros_fact;
    vector<ARMAS> armas_factory;

    int cant_magos = 3 + rand() % (7-3+1) ;
    int cant_guerreros = 3 + rand() % (7-3+1) ;
    cout <<"cant_magos" << cant_magos <<"\ncant guerreros" <<cant_guerreros <<endl;

    crear_personajes(cant_magos, armas_factory, magos);
    /*
    for(int i = 0; i<cant_magos; i++){
        int rand_mago = 0 + rand() % (3-0+1);
        cout <<"tipo mago: "<<rand_mago<<endl;
        int cant_armas =  0+ rand() % (2-0+1);
        //creo la cant de armas que tocó de manera aleatoria
        for(int j = 0; j<cant_armas;j++){
            rand_arma = 0 + rand() % (8-0+1);
            cout << "El arma N°"<<j<<" es: "<<rand_arma<<endl;
            armas_factory.push_back(static_cast<ARMAS>(rand_arma)); 
        }
        magos.push_back(PersonajeFactory::make_personajeArmado(static_cast<PERSONAJES>(rand_mago), armas_factory));
        armas_factory.clear(); //borro las armas de este mago del vector así uso el mismo vector para el siguiente mago que cree
    }

    //hago lo mismo para los 

    int cant_armas_guerreros = 0+ rand() % (2-0+1) ;
    cout << cant_armas_magos <<"\n" <<cant_armas_guerreros<<endl;



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
    }*/
    /*
    cout << PersonajeFactory::make_personaje(PERSONAJES::hechicero)->getName()<<endl;
    
    vector<ARMAS> armasP = {ARMAS::baston, ARMAS::garrote};
    cout << PersonajeFactory::make_personajeArmado(PERSONAJES::nigromante, armasP)->getArma(0)->getName()<<endl;
*/
}