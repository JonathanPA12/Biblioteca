#include "Interfaz.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    Interfaz *i = new Interfaz;
    i->menu();

    /*ifstream entrada;
	ofstream salida;
        string* nombre = new string ();
        *nombre = "Jonh";
        string* cedula = new string();
        *cedula = "ksndla";
        string* correo = new string();
        *correo = "alshas";
        int* celular = new int;
        *celular = 123;
        string* direccion = new string();
        *direccion = "alksdlahsd";
        string* Ntarjeta = new string();
        *Ntarjeta = "patitos123";
        bool* estado = new bool;
        *estado = true;

    Cliente* prueba = new Cliente(estado,nombre,cedula,correo,celular,direccion,Ntarjeta);

    salida.open("clientes.txt", ios::app);
    prueba->autoGuardar(salida);
    salida.close();
    delete prueba;*/

    return 0;
}
