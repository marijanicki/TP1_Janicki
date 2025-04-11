#include "Iarmas.hpp"
#include "Ipersonajes.hpp"
#include "itemsMagicos.hpp"
#include "magos.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(){
    baston baston("baston1");
    hechicero hechicero("Hechicero1");
    cout << hechicero.getType()<<endl;
    cout <<baston.getpower()<<endl;
    cout <<baston.getDesgaste()<<endl;
}