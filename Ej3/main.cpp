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
        int cant_armas =  0+ rand() % (2-0+1);
        //creo la cant de armas que tocó de manera aleatoria
        for(int j = 0; j<cant_armas;j++){
            int rand_arma = 0 + rand() % (8-0+1);
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
    cout << "El personaje al azar que salio es: " <<rand_pj<<endl; //agrego esto así verifico que el valor del enum y el resultado son el mismo
    PERSONAJES enum_pj = static_cast<PERSONAJES>(rand_pj);
    unique_ptr<personajes> my_new_pj = PersonajeFactory::make_personaje(enum_pj);
    cout<<"Mi personaje es un " << my_new_pj->getName()<<endl;

    //Pruebo el arma 
    int rand_arma = 0 + rand() % (8-0+1);
    cout<<"\n\nEl arma al azar que salio es: "<<rand_arma<<endl;
    ARMAS enum_arma = static_cast<ARMAS>(rand_arma);
    unique_ptr<armas> my_new_arma = PersonajeFactory::make_arma(enum_arma);
    cout<<"Mi arma es un " << my_new_arma->getName()<<"\n\n"<<endl;
    

    //Pruebo con una cantidad aleatoria de personajes de cada tipo y con cant aleatoria de armas
    
    vector<unique_ptr<personajes>> magos;
    vector<unique_ptr<personajes>> guerreros;
    vector<ARMAS> armas_factory;

    int cant_magos = 3 + rand() % (7-3+1) ;
    int cant_guerreros = 3 + rand() % (7-3+1) ;
    cout <<"Cantidad de magos: " << cant_magos <<"\nCantidad de guerreros: " <<cant_guerreros <<endl;

    crear_personajes(cant_magos, armas_factory, magos);
    crear_personajes(cant_guerreros, armas_factory, guerreros);
    
    //muestro los personajes:
    cout<<"\n\nMagos:"<<endl;
    for(size_t i = 0; i<magos.size();i++){
        cout<<"\nEl mago de tipo "<< magos[i]->getName();
        if(magos[i]->getSizeArma()==0){
             cout<<" no tiene armas. "<<endl;
        }
        else{
            cout<<" tiene de arma: \n";
            for(size_t j = 0; j <magos[i]->getSizeArma();j++){
            cout<<"+ "<<magos[i]->getArma(j)->getName()<<endl;
            }
        }
    }
    cout<<"\nGuerreros:"<<endl;
    for(size_t i = 0; i<guerreros.size();i++){
        cout<<"\nEl guerrero de tipo "<< guerreros[i]->getName();
        if(guerreros[i]->getSizeArma()==0){
             cout<<" no tiene armas. "<<endl;
        }
        else{
            cout<<" tiene de arma: \n";
            for(size_t j = 0; j <guerreros[i]->getSizeArma();j++){
            cout<<"+ "<<guerreros[i]->getArma(j)->getName()<<endl;
            }
        }
    }
}