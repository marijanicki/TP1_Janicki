#include "interfaz.hpp"

#include <string>
//clases abstractas
class items_magicos:public armas{
    private:
        int poder_magico;
        int durabilidad;
        string nombre;
        string type;
        int desgaste_mana;
    public:
        //constructor
        items_magicos(string nombre, string type, int poder_magico, int desgasteMana, int durabilidad);

        virtual string getName()override;
        virtual int getpower()override;
        virtual string get_armaType()override;
        virtual void efectividad(int turno)override;
        virtual int getDesgaste()override;
        virtual void decreasePower()override;
        virtual  ~items_magicos(){};
};