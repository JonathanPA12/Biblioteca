#include "Lista.h"

Lista::Lista()
{
     cabeza=actual=cola=NULL;
}

Lista::~Lista()
{
    while(cabeza!=NULL){
            this->actual=cabeza;
            cabeza=cabeza->getSigNodo();
            delete actual;
    }
}


//-------------------------------------Agregar datos-----------------------------------------------------//
void Lista::AgregarCliente(Cliente *Cdato){// lo agrega en inicio ///ver si funciona

    actual=cabeza;
    if(cabeza==NULL){
            cabeza= new Nodo(Cdato, NULL);

    }
    else{
        cabeza=new Nodo(Cdato, actual);

    }
}
//---------------------------------------------------------------------------------------------------------//
void Lista::AgregarRestaurante(Restaurante * ResDato){
    actual = cabeza;
	if (cabeza == NULL) {   //La lista vacia, no hay datos, registre el primero
		cabeza = new Nodo(ResDato,cabeza);
	}
	else {
		actual = cabeza;
		while (actual->getSigNodo() != NULL) {   // busca el final de la lista y lo inserta
			actual = actual->getSigNodo();
		}
		actual->setSigNodo(new Nodo(ResDato, NULL));
	}

}
//---------------------------------------------------------------------------------------------------------//
void Lista::AgregarRepartidor(Repartidor *RepDato){

    actual=cabeza;
    if(cabeza==NULL){
            cabeza= new Nodo(RepDato, NULL);
    }
    else{
        cabeza=new Nodo(RepDato, actual);
    }

}
//---------------------------------------------------------------------------------------------------------//
void Lista::AgregarPedido(Pedido *PedDato){

    actual=cabeza;
    if(cabeza==NULL){
            cabeza= new Nodo(PedDato, NULL);
    }
    else{
        cabeza=new Nodo(PedDato, actual);
    }

}


//-------------------------------------Listar datos-----------------------------------------------------//
string Lista::ListarClientes(){//quite bool estaddo
    stringstream cliente;
    int cont=1;
	actual = cabeza;
	cliente << "\n \t Clientes de la lista:" << "\n";
	while (actual != NULL) {
            if(actual->getCdato()->getEstado()==true){
                cliente<<"\n \n \t  --> Usuario "<<cont<<" del sistema"<<endl;
                cliente << actual->toStringC() << "\n";
            }
			actual = actual->getSigNodo();
			cont++;
	}
	return cliente.str();
}
//---------------------------------------------------------------------------------------------------------//
//<<<<<<<<<<<<<<<<<<<<<<<<<
string Lista::ListarClientesINACTIVOS(){//quite bool estaddo
    stringstream cliente;
    int cont=1;
	actual = cabeza;

	cliente << "\n \t Clientes de la lista:" << "\n";
	while (actual != NULL) {
            if(actual->getCdato()->getEstado()==false){
                cliente<<"\n \n \t  --> Usuario "<<cont<<" del sistema"<<endl;
                cliente << actual->toStringC() << "\n";
            }
			actual = actual->getSigNodo();
			cont++;
	}


	return cliente.str();
}
//<<<<<<<<<<<<<<<<<<<<<<<<<


string Lista::ListarRepartidores(){

    stringstream s;
	int cont=1;
	actual = cabeza;

	while (actual != NULL){
        if (actual->getRepDato()->getAmonestaciones()==0){
        s<<"\n \n \t  -->Repartidor "<<cont<<" del registro \n";
		s << actual->getRepDato()->toStringRepartidor();
        }
		actual = actual->getSigNodo();
		cont++;
	}
	return s.str();
}
//---------------------------------------------------------------------------------------------------------//
string Lista::ListarRepartidoresQuejas(){

    stringstream s;
	int cont=1;
	actual = cabeza;

	while (actual != NULL){
        s<<"\n \n \t  -->Queja "<<cont<<" del registro \n";
		s << actual->getRepDato()->toStringRepartidorQuejas();
		actual = actual->getSigNodo();
		cont++;
	}
	return s.str();
}
//---------------------------------------------------------------------------------------------------------//
string Lista::ListarRestaurantes(){
    stringstream Restaurante;
	actual = cabeza;

	Restaurante << "\n \t Restaurantes de la lista:" << "\n";
	while (actual != NULL) {
		Restaurante << actual->toStringRes() << "\n";
		actual = actual->getSigNodo();
	}
	return Restaurante.str();

}
//---------------------------------------------------------------------------------------------------------//
string Lista::ListarMenuRestaurante(){ // tipos de comida
    stringstream Res;
	actual = cabeza;

	Res << "\n \t Los restaurantes y sus tipos de comida son:" << "\n";
	while (actual != NULL) {
		Res << actual->toStringMenuRes();
		actual = actual->getSigNodo();
	}
	return Res.str();

}

//---------------------------------------------------------------------------------------------------------//
string Lista::ListarPedidos(){
    stringstream Pedido;
	actual = cabeza;
    int cont=1;

	while (actual != NULL) {
        Pedido<<"\n \n \t  -->Pedido "<<cont<<" del registro "<<"\n";
		Pedido << actual->toStringPed() << "\n";
		actual = actual->getSigNodo();
        cont++;
	}
	return Pedido.str();

}


//-------------------------------------consultar datos-----------------------------------------------------//
string Lista::consultarDatoEspecificoCliente(string Id_a_buscar){
    actual=cabeza;// igualo actual a cabeza

    if(cabeza==NULL){ // EL REGISTRO ESTA VACIO
        return "0";
    }
    else{ // si hay algo en el registro

        bool n=true;

        while(actual != NULL && n==true){
                if(actual->getCdato()->getCedula()== Id_a_buscar){
                   n=false;
                   return actual->getCdato()->toStringCliente();
                }
                actual = actual->getSigNodo();
        }

        if(actual== NULL){// en caso de que no haya auto con dicha placa retorne 2
            return "2";
        }
    }
    return 0;
}
//---------------------------------------------------------------------------------------------------------//
string Lista::consultarDatoEspecificoRestaurante(string Id_a_buscar)  {
    actual=cabeza;// igualo actual a cabeza

    if(cabeza==NULL){ // EL REGISTRO ESTA VACIO
        return "0";
    }
    else{ // si hay algo en el registro
        bool n=true;
        while(actual != NULL && n==true){
                if(actual->getResDato()->getCedula_juridica()== Id_a_buscar){
                   n=false;
                   return actual->getResDato()->toStringRestaurante();
                }
                actual = actual->getSigNodo();
        }

        if(actual== NULL){// en caso de que no haya auto con dicha placa retorne 2
            return "2";
        }
    }
    return 0;
}
//---------------------------------------------------------------------------------------------------------//
string Lista::consultarDatoEspecificoRepartidor(string Id_a_buscar){

    actual=cabeza;// igualo actual a cabeza
    if(cabeza==NULL){ // EL REGISTRO ESTA VACIO
        return "0";
    }
    else{ // si hay algo en el registro
        bool n=true;
        while(actual != NULL && n==true){

                if(actual->getRepDato()->getCedula()== Id_a_buscar){
                   n=false;
                   return actual->getRepDato()->toStringRepartidor();
                }
                actual = actual->getSigNodo();
        }

        if(actual== NULL){// en caso de que no haya auto con dicha placa retorne 2
            return "2";
        }
    }
    return 0;
}
//---------------------------------------------------------------------------------------------------------//
string Lista::consultarDatoEspecificoPedido(string Id_a_buscar){

    actual=cabeza;// igualo actual a cabeza
    if(cabeza==NULL){ // EL REGISTRO ESTA VACIO
        return "0";
    }
    else{ // si hay algo en el registro
        bool n=true;
        while(actual != NULL && n==true){

                if(actual->getPedDato()->getIdPedido()== Id_a_buscar){
                   n=false;
                   return actual->getPedDato()->toStringFactura();
                }
                actual = actual->getSigNodo();
        }

        if(actual== NULL){// en caso de que no haya auto con dicha placa retorne 2
            return "2";
        }
    }
    return 0;
}


        //-------------------------------------contar datos-----------------------------------------------------//
int Lista::contar() {
    actual = cabeza;
    int cont=0;
    while(actual !=NULL){
        actual=actual->getSigNodo();
        cont++;
    }
    return cont;
}


//------------------------------------verifica si esta vacio----------------------------------------------------//
bool Lista::IsEmpty(){ // Iguala cabeza a null
    bool x;
    cabeza==NULL? x=true: x=false;
    return x;
}

/////////////////////////////////////////////////
//---------------------------------------------------------------------------------------------------------//
string Lista::EleccionRepartidor(){

    actual=cabeza;// igualo actual a cabeza
    // si hay algo en el registro
    bool n=true;
    while(actual != NULL && n==true){
            if(actual->getRepDato()->getEstado()== true&&actual->getRepDato()->getAmonestaciones()<5){
                n=false;
                return actual->getRepDato()->getCedula();
            }
            actual = actual->getSigNodo();
    }
    if(actual== NULL){// en caso de que no haya un repartidor que cumpla con las condiciones
        return "2";
    }
    return 0;
}
/////////////////////////////////////////////////
//---------------------------------------------------------------------------------------------------------//
string Lista::consultarNombredelCliente(string Id_a_buscar){
    actual=cabeza;// igualo actual a cabeza
    if(cabeza==NULL){ // EL REGISTRO ESTA VACIO
        return "0";
    }
    else{ // si hay algo en el registro

        bool n=true;
        while(actual != NULL && n==true){
                if(actual->getCdato()->getCedula()== Id_a_buscar){
                   n=false;
                   return actual->getCdato()->getNombre();
                }
                actual = actual->getSigNodo();
        }

        if(actual== NULL){// en caso de que no haya auto con dicha placa retorne 2
            return "2";
        }
    }
    return 0;



}
