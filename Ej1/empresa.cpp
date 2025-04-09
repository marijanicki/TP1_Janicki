#include "empleados.hpp"
#include "empresa.hpp"

//Clase abstracta
EntidadOrganizativa::EntidadOrganizativa(){}

EntidadOrganizativa::EntidadOrganizativa(string nombre){
    this->nombre;
}

void EntidadOrganizativa::agregarSubentidad(shared_ptr<Empresa> data_subentidad){
    subentidades.push_back(*data_subentidad); //lo desreferencio porq estoy pasando un ptr y yo quiero el obj
}

int EntidadOrganizativa::contarSubentidades(){
    return subentidades.size();
}

//DEPARTAMENTO----------------------------------------
Departamento::Departamento(string nombre, string ubicacion){
    this->nombre = nombre;
    this->ubicacion = ubicacion;
}

bool Departamento::contratarEmpleado(Empleado obj_empleado){
    empleados.push_back(obj_empleado);
    return true;
}//considerar caso q ya este contratado entonces ahi seria false

bool Departamento::despedirEmpleado(Empleado obj_empleado){
    for(size_t i; i < empleados.size(); i++){
        if(empleados[i].nombre == obj_empleado.nombre && empleados[i].puesto == obj_empleado.puesto){ //chequeo tambien el puesto por si hay otro empleado con el mismo nombre
            empleados.erase(empleados.begin()+i);
            return true;
        }
    }
    return false; //no encontró al empleado entonces no lo pudo despedir
}

vector<Empleado> Departamento::getEmployees(){
    return empleados;
}

//EMPRESA -------------------------------------------------------
Empresa::Empresa(string nombre) : EntidadOrganizativa(nombre){}

Departamento Empresa::getDepByName(string name){
    for(size_t i = 0; i< departamentos.size(); i++){
        if(departamentos[i].nombre == name){
            return departamentos[i];
        }
    }
}

void Empresa::setDepartamentos(Departamento new_departamento){
    departamentos.push_back(new_departamento);
}
//-----------------------------------------------------------
CentralRegional::CentralRegional(){
    cant
}