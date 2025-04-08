#include "empleados.hpp"
#include <string>
#include <vector>

using namespace std;

//clase base empleado
//constructor
Empleado::Empleado(string nombre, string puesto, int antiguedad, float salario){
    this->nombre = nombre;
    this->puesto = puesto;
    this->salario = salario;
    this->antiguedad = antiguedad;
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
Manager::Manager(string nombre, string puesto, int antiguedad, float salario): Empleado(nombre,puesto, antiguedad, salario){}

bool Manager::updateBono(float new_bono){
    this->bono = new_bono;
    return true;
}

bool Manager::setLevel(string level){
    this->level = level;
    return true;
}

float Manager::getBono(){
    return bono;
}

//agregue
string Manager::getLevel(){
    return level;
}

//GERENTES 
GerenteBajo::GerenteBajo(string nombre, string puesto, int antiguedad, float salario):Manager(nombre,puesto, antiguedad, salario){}
GerenteMedio::GerenteMedio(string nombre, string puesto, int antiguedad, float salario):Manager(nombre,puesto, antiguedad, salario){}
GerenteAlto::GerenteAlto(string nombre, string puesto, int antiguedad, float salario):Manager(nombre,puesto, antiguedad, salario){}
LiderEquipo::LiderEquipo(string nombre, string puesto, int antiguedad, float salario):Manager(nombre,puesto, antiguedad, salario){}
