#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Ej3/factory.hpp"
#include "../Ej2/Iarmas.hpp"
#include "../Ej2/Ipersonajes.hpp"
#include "../Ej2/itemsMagicos.hpp"
#include "../Ej2/armasCombate.hpp"
#include "../Ej2/magos.hpp"
#include "../Ej2/guerreros.hpp"

using namespace std;

PERSONAJES make_enum_pj(int op_personaje){
    switch (op_personaje)
    {
    case 1:
        return PERSONAJES::hechicero;
        break;
    case 2:
        return PERSONAJES::brujo;
        break;
    case 3: 
        return PERSONAJES::nigromante;
        break;
    case 4:
        return PERSONAJES::conjurador;
        break;
    case 5:
        return PERSONAJES::caballero;
        break;
    case 6:
        return PERSONAJES::paladin;
        break;
    case 7:
        return PERSONAJES::mercenario;
        break;
    case 8:
        return PERSONAJES::barbaro;
        break;
    case 9:
        return PERSONAJES::gladiador;
        break;
    default:
        return PERSONAJES::INVALID;
    }
}

ARMAS make_enum_arma(int op_arma){
    switch (op_arma)
    {
    case 1:
        return ARMAS::baston;
        break;
    case 2:
        return ARMAS::libro;
        break;
    case 3:
        return ARMAS::pocion;
        break;
    case 4:
        return ARMAS::amuleto;
        break;
    case 5:
        return ARMAS::hacha_simple;
        break;
    case 6:
        return ARMAS::hacha_doble;
        break;
    case 7:
        return ARMAS::espada;
        break;
    case 8: 
        return ARMAS::lanza;
        break;
    case 9:
        return ARMAS::garrote;
        break;
    default:
        return ARMAS::INVALID;
    }
}

int main(){
    int op_personaje;
    int op_arma;
    cout<< "Elija el personaje para el jugador 1:"
        << "\n(1) Hechicero"
        << "\n(2) Brujo"
        << "\n(3) Nigromante"
        << "\n(4) Conjurador"
        << "\n(5) Caballero"
        << "\n(6) Paladin"
        << "\n(7) Mercenario"
        << "\n(8) Barbaro"
        << "\n(9) Gladiador"<<endl;
    cin>>op_personaje;

    cout << "Elija el arma que desea usar:"
         << "\n(1) Baston"
         << "\n(2) Libro de hechizos"
         << "\n(3) Pocion"
         << "\n(4) Amuleto"
         << "\n(5) Hacha Simple"
         << "\n(6) Hacha Doble"
         << "\n(7) Espada"
         << "\n(8)Lanza"
         << "\n(9)Garrote"<<endl; 
    cin>>op_arma;
    PERSONAJES enum_personaje = make_enum_pj(op_personaje);
    ARMAS enum_arma = make_enum_arma(op_arma);
    vector<ARMAS> arma_factory;
    arma_factory.push_back(enum_arma);
    unique_ptr<personajes> Jugador1 = PersonajeFactory::make_personajeArmado(enum_personaje,arma_factory);
    
    //jugador2
    float daño_tt;
    int personaje2 = 0 + rand() % (8-0+1);
    int arma2 = 0 + rand() % (8-0+1);
    arma_factory.erase(arma_factory.begin());
    arma_factory.push_back(static_cast<ARMAS>(arma2));
    unique_ptr<personajes> Jugador2 = PersonajeFactory::make_personajeArmado(static_cast<PERSONAJES>(personaje2), arma_factory);
    int rand_attack;
    int op_ataque;
    while(!Jugador1->isDead() && !Jugador2->isDead()){
        cout<<"El" <<Jugador1->getName() <<" tiene " << Jugador1->getHp()<<"HP y el" <<Jugador2->getName() <<"tiene "<< Jugador2->getHp()<<"HP"<<endl;
        cout<<"Elija su ataque: (1) Golpe Fuerte, (2) Golpe Rápido, (3)Defensa y Golpe: ";
        cin>>op_ataque;
        rand_attack = 1 + rand() % (3-1+1);
        cout<<"ataque"<<rand_attack<<endl;
        if(op_ataque == rand_attack){
            continue;
        }
        //si es ataque fuerte
        if(op_ataque ==1){
            if(rand_attack == 2){
                daño_tt = Jugador1->ataque(Jugador1->getArma(0));
                Jugador2->recibirdaño(daño_tt);
            }
        }
    }
}
