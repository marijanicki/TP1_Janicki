#pragma once
#include <string>
#include <memory>
#include <vector>

using namespace std;

//es una clase abstracta -> lleva constructor y tiene metodos virtuales puros y no puros
class EntidadOrganizativa{
    public: 
        string nombre;
        EntidadOrganizativa(); //constructor

        void agregarSubentidad(shared_ptr<EntidadOrganizativa> data_subentidad);
        int contarSubentidades();
    
        private:
            vector<EntidadOrganizativa> subentidades;
        
};

class CentralRegional: public EntidadOrganizativa{
    public:
        //preg paises es un set
        CentralRegional(); //constructor
        int getCantEmpleados();
        vector<string> getEmpNames();
        vector<GerenteAlto> getGerentesAlto();//preg como definir el size del vector
        //completar con gerente medio

    private:
        int cantEmpleados;
        
}