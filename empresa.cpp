#include "empleados.hpp"
#include "empresa.hpp"

/*
#include "clases.hpp"

EntidadOrganizativa::EntidadOrganizativa(){}

EntidadOrganizativa::EntidadOrganizativa(string nombre){
    this->nombre;
}

void EntidadOrganizativa::agregarSubentidad(shared_ptr<EntidadOrganizativa> data_subentidad){
    subentidades.push_back(*data_subentidad); //lo desreferencio porq estoy pasando un ptr y yo quiero el obj
}

int EntidadOrganizativa::contarSubentidades(){
    return subentidades.size();
}

*/

Departamento::Departamento(string nombre, string ubicacion){
    this->nombre = nombre;
    this->ubicacion = ubicacion;
}

bool Departamento::contratarEmpleado(Empleado obj_empleado){

}
bool contratarEmpleado(Empleado obj_empleado)