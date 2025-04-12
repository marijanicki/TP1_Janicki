#include <cstdlib>
#include <ctime>
#include <iostream>
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
    cout << cant_magos <<"\n" <<cant_guerreros<<endl;
    int cant_armas_magos = 0+ rand() % (2-0+1) ;
    int cant_armas_guerreros = 0+ rand() % (2-0+1) ;
    cout << cant_armas_magos <<"\n" <<cant_armas_guerreros<<endl;

      
}