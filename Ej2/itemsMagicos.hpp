#include "Iarmas.hpp"

#include <string>
using namespace std;
//clases abstractas
class items_magicos:public armas{
    private:
        int poder_magico;
        int durabilidad;
        string nombre;
        string type;
        int consumo_mana;
    public:
        //constructor
        items_magicos(string nombre, string type, int consumo_mana, int poder_magico,  int durabilidad);

        virtual string getName()override;
        virtual int getpower()override;
        virtual string get_armaType()override;
        virtual void efectividad(int turno)override;
        virtual int getDesgaste()override;
        virtual void setPower(int poder_magico)override;
        virtual  ~items_magicos(){};
};