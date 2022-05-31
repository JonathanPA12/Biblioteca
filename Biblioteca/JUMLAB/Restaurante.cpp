#include "Restaurante.h"

Restaurante::Restaurante()
{
    this->nombre_res = " ";
    this->cedula_juridica  = " ";
    this->direccion_res = " ";
    this->TipoDeComida  = " ";
}

Restaurante::~Restaurante()
{

}
Restaurante::Restaurante(string nombre_res, string cedula_juridica, string direccion_res, string TipoDeComida){

    this->nombre_res =nombre_res;
    this->cedula_juridica = cedula_juridica;
    this->direccion_res = direccion_res;
    this->TipoDeComida = TipoDeComida;

}

void Restaurante::setNombre_Res(string nombre_res){
    this->nombre_res=nombre_res;
}
void Restaurante::setCedula_juridica(string cedula){
    this->cedula_juridica = cedula_juridica;
}
void Restaurante::setDireccion_Res(string direccion_res){
    this->direccion_res= direccion_res;
}

void Restaurante::setTipoDeComida(string TipoDeComida){
    this->TipoDeComida = TipoDeComida;
}
string Restaurante::getNombre_Res(){
    return nombre_res;
}
string Restaurante::getCedula_juridica(){
    return cedula_juridica;
}
string Restaurante::getDireccion_Res(){
    return direccion_res;
}
string Restaurante::getTipoDeComida(){
    return TipoDeComida;
}
string Restaurante::toStringRestaurante(){
    stringstream restaurante;

    restaurante<<"\t Datos del Restaurante:\n";
    restaurante<<"\n \t \t Nombre:\t"<<getNombre_Res();
    restaurante<<"\n \t \t Cédula jurídica:\t"<<getCedula_juridica();
    restaurante<<"\n \t \t Dirección:\t"<<getDireccion_Res();
    restaurante<<"\n \t \t Tipo de comida:\t"<<getTipoDeComida();

    return restaurante.str();
}

string Restaurante::Lista_TipoComida(){ // lista solo el restaurante y el tipo de comida
    stringstream restaurante;

    restaurante<<"\n \t \t ________________________________________________________ \n";
    restaurante<<"\n \t \t Restaurante:\t \t"<<getNombre_Res();
    restaurante<<"\n \t \t Tipo de comida:\t"<<getTipoDeComida()
               <<"\n \t \t Identificación:\t"<<getCedula_juridica();

    return restaurante.str();
}

double Restaurante::Ganancia(){
    /**falta desarrollar*/
}
void Restaurante::autoGuardar(ofstream& dato) {
	cout << "    <<Guardando>>" << endl;
	cout << toStringRestaurante() << endl;
	dato << getNombre_Res()  << endl
		<< getCedula_juridica() << endl
		<< getDireccion_Res() << endl
		<< getTipoDeComida() << endl;


}

Restaurante*  Restaurante::autoLeer(ifstream& dato) {

        char variable_aux[30];
        string nombre_res, cedula_juridica, direccion_res, TipoDeComida ;

        (dato.getline(variable_aux, sizeof(variable_aux)));
                    if(dato.good()) {// si se pudo leer
                            nombre_res = variable_aux;
                            if(dato.eof()){exit(1);}
                            (dato.getline(variable_aux, sizeof(variable_aux)));
                        if(dato.good()) {// si se pudo leer
                                cedula_juridica = variable_aux;
                                if(dato.eof()){exit(1);}
                                (dato.getline(variable_aux, sizeof(variable_aux)));
                            if(dato.good()) {// si se pudo leer
                                    direccion_res = variable_aux;
                                    if(dato.eof()){exit(1);}
                                    (dato.getline(variable_aux, sizeof(variable_aux)));
                                if(dato.good()) {// si se pudo leer
                                        TipoDeComida = variable_aux;
                                        if(dato.eof()){exit(1);}
                                }
                            }
                        }
                    }

    if (nombre_res!=""||cedula_juridica!=""){
            cout << "\n \t  -- Se estan cargando los registro" << endl;
            return new Restaurante(nombre_res,cedula_juridica,direccion_res,TipoDeComida);
    }else{
        return NULL;}

}

