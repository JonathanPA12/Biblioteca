#include "Persona.h"

Persona::Persona(){
    this->nombre = " ";
    this->cedula  = " ";
    this->correo = " ";
    this->celular = 0;
    this->direccion = " ";
    this->Ntarjeta  = " ";
}

Persona::~Persona(){

}
Persona::Persona( string nombre,string cedula,string correo,int celular,string direccion,string Ntarjeta){

    this->nombre=nombre;
    this->cedula=cedula;
    this->correo=correo;
    this->celular=celular;
    this->direccion=direccion;
    this->Ntarjeta=Ntarjeta;
}

 void Persona::setNombre(string nombre){
     this->nombre=nombre;
}
 void Persona::setCedula(string cedula){
     this->cedula=cedula;
}
void Persona::setCorreo(string correo){
    this->correo=correo;
}
void Persona::setCelular(int celular){
    this->celular=celular;
}
void Persona::setDireccion(string direccion){
    this->direccion=direccion;
}
void Persona::setNtarjeta(string Ntarjeta){
    this->Ntarjeta=Ntarjeta;
}
string Persona::getNombre(){
    return nombre;
}
string Persona::getCedula(){
    return cedula;
}
string Persona::getCorreo(){
    return correo;
}
 int Persona::getCelular(){
     return celular;
 }
string Persona::getDireccion(){
    return direccion;
}
string Persona::getNtarjeta(){
    return Ntarjeta;
}


string Persona::toStringPersona(){
    stringstream persona;
    persona<<endl;
    persona<<" \t  Nombre:\t"<<nombre<<endl;
    persona<<" \t  Cédula:\t"<<cedula<<endl;
    persona<<" \t  Correo:\t"<<correo<<endl;
    persona<<" \t  Celular:\t"<<celular<<endl;
    persona<<" \t  Dirección:\t"<<direccion<<endl;
    persona<<" \t  Número de tarjeta:\t"<<Ntarjeta<<endl;
    return persona.str();


}
