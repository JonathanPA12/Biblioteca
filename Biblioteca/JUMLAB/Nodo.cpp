#include "Nodo.h"

Nodo::~Nodo()
{
    delete Pdato;
    delete Cdato;
    delete RepDato;
    delete ResDato;
    delete PedDato;
    delete sigNodo;
}

//Constructores
Nodo::Nodo(Persona *Pdato , Nodo *sigNodo){
    this->Pdato=Pdato;
    this->sigNodo=sigNodo;
}
Nodo::Nodo(Cliente *Cdato, Nodo *sigNodo){
    this->Cdato=Cdato;
    this->sigNodo=sigNodo;
}
Nodo::Nodo(Repartidor *RepDato, Nodo *sigNodo){
    this->RepDato=RepDato;
    this->sigNodo=sigNodo;
}
Nodo::Nodo(Restaurante *ResDato, Nodo *sigNodo){
    this->ResDato=ResDato;
    this->sigNodo=sigNodo;
}
Nodo::Nodo(Pedido *PedDato, Nodo *sigNodo){
    this->PedDato=PedDato;
    this->sigNodo=sigNodo;
}

//set's
void  Nodo::setPdato (Persona *Pdato){
    this->Pdato=Pdato;
}
void  Nodo::setCDato(Cliente *Cdato){
    this->Cdato=Cdato;
}
void  Nodo::setRepDato(Repartidor *RepDato){
    this->RepDato=RepDato;
}
void  Nodo::setResDato(Restaurante *ResDato){
    this->ResDato=ResDato;
}
void  Nodo::setPedDato(Pedido *PedDato){
    this->PedDato=PedDato;
}
void  Nodo::setSigNodo(Nodo *sigNodo){
    this->sigNodo=sigNodo;
}


//get's
Persona *Nodo::getPdato(){
    return this->Pdato;
}
Cliente *Nodo::getCdato(){
    return this->Cdato;
}
Repartidor *Nodo::getRepDato(){
    return this->RepDato;
}
Restaurante *Nodo::getResDato(){
    return this->ResDato;
}
Pedido *Nodo::getPedDato(){
    return this->PedDato;
}
Nodo *Nodo::getSigNodo(){
    return this->sigNodo;
}

//Metodos to string
string Nodo::toStringC(){
    stringstream s;
	s << getCdato()->toStringCliente() <<"\n ";
	return s.str();
}
string Nodo::toStringRep(){
    stringstream s;
	s << getRepDato()->toStringRepartidor() <<"\n ";
	return s.str();
}
string Nodo::toStringRepQuejas(){
    stringstream s;
	s << getRepDato()->toStringRepartidorQuejas() <<"\n ";
	return s.str();
}
string Nodo::toStringRes(){
    stringstream s;
	s << getResDato()->toStringRestaurante() <<"\n ";
	return s.str();
}
string Nodo::toStringMenuRes(){
    stringstream s;
	s << getResDato()->Lista_TipoComida();
	return s.str();
}
string Nodo::toStringPed(){
    stringstream s;
	s << getPedDato()->toStringFactura() <<"\n ";
	return s.str();
}
