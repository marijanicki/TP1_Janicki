#include "factory.hpp"
#include "../Ej2/Iarmas.hpp"
#include "../Ej2/Ipersonajes.hpp"
#include "../Ej2/itemsMagicos.hpp"
#include "../Ej2/armasCombate.hpp"
#include "../Ej2/magos.hpp"
#include "../Ej2/guerreros.hpp"

#include <string>
using namespace std;

unique_ptr<personajes> PersonajeFactory::make_personaje(PERSONAJES personajes){
    switch (personajes)
    {
    case PERSONAJES::hechicero:
        return make_unique<hechicero>();
        break;
    case PERSONAJES::brujo:
        return make_unique<brujo>();
        break;
    case PERSONAJES::nigromante:
        return make_unique<nigromante>();
        break;
    case PERSONAJES::conjurador:
        return make_unique<conjurador>();
        break;
    case PERSONAJES::caballero:
        return make_unique<caballero>();
        break;
    case PERSONAJES::paladin:
        return make_unique<paladin>();
        break;
    case PERSONAJES::mercenario:
        return make_unique<merceneario>();
        break;
    case PERSONAJES::barbaro:
        return make_unique<barbaro>();
        break;
    case PERSONAJES::gladiador:
        return make_unique<gladiador>();
    default:
        return nullptr;
    }
}
unique_ptr<armas> PersonajeFactory::make_arma(ARMAS arma){
    switch(arma){
        case ARMAS::baston:
            return make_unique<baston>();
            break;
        case ARMAS::libro:
            return make_unique<libro>();
            break;
        case ARMAS::pocion:
            return make_unique<pocion>();
            break;
        case ARMAS::amuleto:
            return make_unique<amuleto>();
            break;
        case ARMAS::hacha_simple:
            return make_unique<hacha_simple>();
            break;
        case ARMAS::hacha_doble:
            return make_unique<hacha_doble>();
            break;
        case ARMAS::espada:
            return make_unique<espada>();
            break;
        case ARMAS::lanza:
            return make_unique<lanza>();
            break;
        case ARMAS::garrote:
            return make_unique<garrote>();
            break;
        default:
            return nullptr;
    }
}

unique_ptr<personajes> PersonajeFactory::make_personajeArmado(PERSONAJES personaje, vector<ARMAS> armas_factory){
    unique_ptr<personajes> personaje_fact =  PersonajeFactory::make_personaje(personaje);
    for(size_t i = 0; i<armas_factory.size(); i++){
        personaje_fact->appendArma(PersonajeFactory::make_arma(armas_factory[i]));
    }
    return personaje_fact;
}