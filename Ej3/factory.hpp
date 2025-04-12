#include "../Ej2/Iarmas.hpp"
#include "../Ej2/Ipersonajes.hpp"
#include "../Ej2/itemsMagicos.hpp"
#include "../Ej2/armasCombate.hpp"
#include "../Ej2/magos.hpp"
#include "../Ej2/guerreros.hpp"

using namespace std;

enum class PERSONAJES :uint8_t{hechicero, brujo, nigromante, conjurador, caballero, paladin, mercenario, barbaro, gladiador};
enum class ARMAS : uint8_t{baston, libro, pocion, amuleto, hacha_simple, hacha_doble, espada, lanza, garrote};

class PersonajeFactory{
    public:
        static unique_ptr<personajes> make_personaje(PERSONAJES character);
        static unique_ptr<armas> make_arma(ARMAS arma);
        static unique_ptr<personajes> make_personajeArmado(PERSONAJES character, vector<ARMAS> armas_factory);
};

