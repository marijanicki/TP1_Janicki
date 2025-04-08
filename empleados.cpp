#include "empleados.hpp"
#include <string>
#include <vector>

using namespace std;

//clase base empleado
//constructor
Empleado::Empleado(string nombre, string puesto){
    this->nombre = nombre;
    this->puesto = puesto;
    this->salario = 0.0;
    this->antiguedad = 0;
}

bool Empleado::updateSalario(float new_salario){
    this->salario = new_salario;
    return true;
}

void Empleado::setAntiguedad(int antiguedad){
    this->antiguedad = antiguedad;
}

float Empleado::getSalario(){
    return salario;
}

int Empleado::getAntiguedad(){
    return antiguedad;
}

//MANAGER----------------
Manager::Manager(string nombre, string puesto): Empleado(nombre,puesto){}

