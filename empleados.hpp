#pragma once
#include <string>
#include <memory>
#include <vector>
#include <set>
using namespace std;


class Empleado{
    public:
        string nombre;
        string puesto;

        Empleado(string nombre, string puesto);

        //agregados setters
        void setAntiguedad(int antiguedad);
        bool updateSalario(float new_salario);
        //void setSalario(float salario);

        //getters
        int getAntiguedad();
        float getSalario();
    
    private:
        int antiguedad;
        float salario;
};

class Manager: public Empleado{
    private:
        float bono;
        string level;
    public:
        Manager(string nombre, string puesto);
        bool updateBono(float update);
        float getBono();
        bool setLevel(string level);
};

class GerenteBajo : public Manager{
    public:
        GerenteBajo();
};

class GerenteMedio : public Manager{
    public:
        GerenteMedio();
};

class GerenteAlto : public Manager{
    public:
        GerenteAlto();
};

class LiderEquipo : public Manager{
    public:
        LiderEquipo();
};