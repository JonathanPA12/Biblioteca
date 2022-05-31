#include "Cliente.h"

Cliente::Cliente(){
    this->estado=true;
    Persona();
}

Cliente::~Cliente(){

}

Cliente::Cliente(bool estado,string nombre,string cedula,string correo,int celular,string direccion,string Ntarjeta){

    //clase: Cliente
    this->estado=estado;

    //clase: Persona
    this->setNombre(nombre);
    this->setCedula(cedula);
    this->setCorreo(correo);
    this->setCelular(celular);
    this->setDireccion(direccion);
    this->setNtarjeta(Ntarjeta);
}

void Cliente::setEstado(bool estado){
    this->estado=estado;
}
bool Cliente::getEstado(){
    return estado;
}

string Cliente::toStringCliente(){
    stringstream cliente;

    cliente<<toStringPersona()<<endl;

    if(estado==false){
        cliente<<"Estado de subscripción: Inactivo\t"<<endl;
    }else{
        cliente<<"Estado de subscripción: Activo\t"<<endl;
    }

    return cliente.str();
}

void Cliente::autoGuardar(ofstream& dato) {
	//cout << "    <<Guardando>>" << endl;
	//cout << toStringCliente() << endl;
	dato<< estado<< endl
        << getNombre()  << endl
		<< getCedula() << endl
		<< getCorreo() << endl
		<< getCelular() << endl
		<< getDireccion() <<endl
		<< getNtarjeta() <<endl;

}

Cliente*  Cliente::autoLeer(ifstream& dato) {

        char variable_aux[30];
        string nombre, cedula, correo, cel, direccion, Ntarjeta;

        string AuxEstado;//Sirve para hacer un cambio de bool a string

        int celular;
        bool estado;

        (dato.getline(variable_aux, sizeof(variable_aux)));
        if(dato.good()) { // si se pudo leer

                AuxEstado = variable_aux;           //<- Cambio
                estado = stoi(AuxEstado);           //<- Cambio

                if(dato.eof()) {return NULL;}
                (dato.getline(variable_aux, sizeof(variable_aux)));
            if(dato.good()) {// si se pudo leer
                    nombre = variable_aux;
                    if(dato.eof()){exit(1);}
                    (dato.getline(variable_aux, sizeof(variable_aux)));
                if(dato.good()) {// si se pudo leer
                        cedula = variable_aux;
                        if(dato.eof()){exit(1);}
                        (dato.getline(variable_aux, sizeof(variable_aux)));
                    if(dato.good()) {// si se pudo leer
                            correo = variable_aux;
                            if(dato.eof()){exit(1);}
                            (dato.getline(variable_aux, sizeof(variable_aux)));
                         if(dato.good()) {// si se pudo leer
                                cel = variable_aux;
                                celular = stoi(cel);
                                if(dato.eof()){exit(1);}
                                (dato.getline(variable_aux, sizeof(variable_aux)));
                            if(dato.good()) {// si se pudo leer
                                    direccion = variable_aux;
                                    if(dato.eof()){exit(1);}
                                    (dato.getline(variable_aux, sizeof(variable_aux)));
                                if(dato.good()) {// si se pudo leer
                                    Ntarjeta = variable_aux;
                                    if(dato.eof()){exit(1);}

                                }
                            }
                        }
                    }
                }
            }
        }


    if (nombre!=""||cedula!=""){
            //cout << "\n \t  -- Se estan cargando los registro" << endl;
            return new Cliente(estado,nombre,cedula,correo,celular, direccion,Ntarjeta);
    }else{
        return NULL;}


}

