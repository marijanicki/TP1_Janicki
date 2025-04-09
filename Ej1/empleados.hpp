#pragma once
#include <string>

using namespace std;


class Empleado{
    public:
        string nombre;
        string puesto;

        Empleado(string nombre, string puesto, int antiguedad =0, float salario =0);

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
        Manager(string nombre, string puesto, int antiguedad =0, float salario =0);
        bool updateBono(float new_bono);
        bool setLevel(string level);
        float getBono();
        
        //agrego
        string getLevel();
};

class GerenteBajo : public Manager{
    public:
        GerenteBajo(string nombre, string puesto, int antiguedad =0, float salario =0);
};

class GerenteMedio : public Manager{
    public:
        GerenteMedio(string nombre, string puesto, int antiguedad =0, float salario =0);
};

class GerenteAlto : public Manager{
    public:
        GerenteAlto(string nombre, string puesto, int antiguedad =0, float salario =0);
};

class LiderEquipo : public Manager{
    public:
        LiderEquipo(string nombre, string puesto, int antiguedad =0, float salario =0);
};