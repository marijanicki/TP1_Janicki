#include "Iarmas.hpp"
#include "Ipersonajes.hpp"
#include "itemsMagicos.hpp"
#include "magos.hpp"
#include "armasCombate.hpp"
#include "guerreros.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(){
    unique_ptr baston1 = make_unique<baston>("baston1");
    //baston baston("baston1");
    hechicero hechicero("Hechicero1");
    cout << hechicero.getType()<<endl;
   /*
    cout <<baston.getpower()<<endl;
    cout <<baston.getDesgaste()<<endl;*/
    barbaro barbaro("Luca");
    cout <<barbaro.getName()<<endl;
    barbaro.appendArma(move(baston1));
    cout << barbaro.getArma(0)->getpower()<<endl;
    nigromante nigromante("Bombi");
    cout << nigromante.getName()<<endl;

    unique_ptr garrote_b = make_unique<garrote>("Mati P");
    nigromante.appendArma(move(garrote_b));
    cout<< nigromante.getArma(0)->getName()<<endl;
    cout<< nigromante.getArma(0)->getpower()<<endl;
    cout<< barbaro.getEnergia()<<endl;
    cout<< nigromante.getEnergia()<<endl;

}