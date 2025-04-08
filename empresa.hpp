/*

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

class Empresa : public EntidadOrganizativa{
    public:
        string direccion;
        Departamento getDepByName(string name);
        vector<Departamento> getDepNames();
};
*/
/*
class Departamento{
    public:
        string nombre;
        string ubicacion;

        Departamento();
        
        vector<Empleado> getEmployees();
        bool contratarEmpleado(Empleado);
        bool despedirEmpleado(Empleado);
        static int contarEmpleados();
    private:
        vector<Empleado> empleados;
        static int cantEmpleadosDepts;
};
*/