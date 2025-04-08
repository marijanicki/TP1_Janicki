#pragma once
#include "empleados.hpp"
#include <string>
#include <memory>
#include <vector>
#include <set>

using namespace std;

//es una clase abstracta -> lleva constructor y tiene metodos virtuales puros y no puros
class EntidadOrganizativa{
    public: 
        string nombre;
        EntidadOrganizativa();
        EntidadOrganizativa(string nombre); //constructor

        virtual void agregarSubentidad(shared_ptr<EntidadOrganizativa> data_subentidad);
        virtual int contarSubentidades();
    
        private:
            vector<EntidadOrganizativa> subentidades;
        
};

class Empresa : public EntidadOrganizativa{
    public:
        string direccion;
        Departamento getDepByName(string name);
        vector<Departamento> getDepNames();
};


class CentralRegional: public EntidadOrganizativa{
    public:
        CentralRegional(); //constructor

        set<string> paises;
        int getCantEmpleados();
        vector<string> getEmpNames();
        vector<GerenteAlto> getGerentesAlto();//preg como definir el size del vector
        vector<GerenteMedio> getGerentesMedio();

    private:
        int cantEmpleados;
        vector<GerenteAlto> gerentesAlto();//preg
        vector<GerenteMedio> gerentesMedio();
        set<Empresa> empresas;
};


class Departamento{
    public:
        string nombre;
        string ubicacion;

        Departamento();
        Departamento(string nombre, string ubicacion);

        vector<Empleado> getEmployees();
        bool contratarEmpleado(Empleado obj_empleado);
        bool despedirEmpleado(Empleado obj_empleado);
        static int contarEmpleados();
        
    private:
        vector<Empleado> empleados;
        static int cantEmpleadosDepts;
        Empleado Empleado;
};
