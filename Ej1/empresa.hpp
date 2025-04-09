#pragma once
#include "empleados.hpp"
#include <string>
#include <memory>
#include <vector>
#include <array>
#include <set>

using namespace std;

//es una clase abstracta -> lleva constructor y tiene metodos virtuales puros y no puros
class EntidadOrganizativa{
    public: 
        string nombre;
        EntidadOrganizativa();
        EntidadOrganizativa(string nombre); //constructor

        virtual void agregarSubentidad(shared_ptr<Empresa> data_subentidad); //<EntidadesOrganizativas> le crei a Mariano y use empresa nomas
        virtual int contarSubentidades();
    
        private:
            vector<Empresa> subentidades;
        
};

class Empresa : public EntidadOrganizativa{
    public:
        string nombre; //agregue yo
        string direccion;
        Empresa(string direccion);
        
        Departamento getDepByName(string name);
        vector<Departamento> getDepNames();

        //agrego
        void setDepartamentos(Departamento new_departamento);
    private:
        vector<Departamento> departamentos;
};


class CentralRegional: public EntidadOrganizativa{
    public:
        CentralRegional(); //constructor

        set<string> paises;
        int getCantEmpleados();
        vector<string> getEmpNames();
        array<GerenteAlto,5> getGerentesAlto();
        array<GerenteMedio, 20> getGerentesMedio();

        //agrego
        void appendPais(string pais);
        void setCantEmpleados(int cantEmpleados);

        //IDEA: HACER VARIABLES QUE CUENTEN LA CANT DE GERENTES DE CADA TIPO
        //HASTA EL MOMENTO ASI VERIFICO CUANDO LLEGO AL LIMITE, SI TENGO MAS 
        //DE LO QUE PUEDO ME TIRA ERROR
    private:
        int cantEmpleados;
        array<GerenteAlto,5> gerentesAlto();
        array<GerenteMedio,20> gerentesMedio();
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
        //Empleado Empleado; la composicion es por pasar el objeto y tenerlo 
        //en el vector
};
