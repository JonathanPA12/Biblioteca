#include "Pedido.h"

Pedido::Pedido()
{
     IdPedido =" ";
     clienteP =" ";
     repartidorP =" ";
     restauranteP =" ";
     horaPedido = 0;
     minPedido = 0;
     horaEntrega = 0;
     minEntrega = 0;
     costoTotalPedido = 0;
     queja = false;
     distanciaP=0.0;
     combos= new float[9];
     for(int i =0; i<9;i++){ // como los precios son estaticos, podrian llenarse en el constructor
        combos[i]=3000.0+((i+1)*1000);
    }


}

Pedido::~Pedido()
{
    //dtor
}
Pedido::Pedido(string IdPedido, string clienteP, string repartidorP,
               string restauranteP, int horaPedido, int minPedido, int horaEntrega, int minEntrega, float costoTotalPedido, bool queja, float distanciaP ){
    this->IdPedido=IdPedido;
    this->clienteP=clienteP;
    this->repartidorP=repartidorP;
    this->restauranteP=restauranteP;
    this->horaPedido=horaPedido;
    this->minPedido=minPedido;
    this->horaEntrega=horaEntrega;
    this->minEntrega=minEntrega;
    this->costoTotalPedido=costoTotalPedido;
    this->queja=queja;
    this->distanciaP=distanciaP;
    combos= new float[9];
     for(int i =0; i<9;i++){ // como los precios son estaticos, podrian llenarse en el constructor
        combos[i]=3000.0+((i+1)*1000);
    }


}
void Pedido::setIdPedido (string IdPedido){
    this->IdPedido=IdPedido;

}
string Pedido::getIdPedido(){
    return IdPedido;
}
void Pedido::setClienteP (string clienteP){
    this->clienteP=clienteP;

}
string Pedido::getClienteP(){
    return clienteP;
}
void Pedido::setRepartidorP (string repartidorP){
    this->repartidorP=repartidorP;

}
string Pedido::getRepartidorP(){
    return repartidorP;
}
void Pedido::setRestauranteP (string restauranteP){
    this->restauranteP=restauranteP;

}
string Pedido::getRestauranteP(){
    return restauranteP;
}
void Pedido::setHoraPedido (int horaPedido){
    this->horaPedido=horaPedido;

}
int Pedido::getHoraPedido(){
    return horaPedido;
}
void Pedido::setMinPedido (int minPedido){
    this->minPedido=minPedido;

}
int Pedido::getMinPedido(){
    return minPedido;
}
void Pedido::setHoraEntrega (int horaEntrega){
    this->horaEntrega=horaEntrega;

}
int Pedido::getHoraEntrega(){
    return horaEntrega;
}
void Pedido::setMinEntrega (int minEntrega){
    this->minEntrega=minEntrega;

}
int Pedido::getMinEntrega(){
    return minEntrega;
}
void Pedido::setCostoTotalPedido (float costoTotalPedido){
    this->costoTotalPedido=costoTotalPedido;
}
float Pedido::getCostoTotalPedido(){
    return costoTotalPedido;
}
void Pedido::setQueja (bool queja){
    this->queja=queja;
}
bool Pedido::getQueja(){
    return queja;
}
void Pedido::setDistanciaP (float distanciaP){
    this->distanciaP=distanciaP;
}
float Pedido::getDistanciaP(){
    return distanciaP;
}
string Pedido::toStringFactura(){
    stringstream s;
   // system("color 02");
    s<<"\n  \t \t \t CLETAEAT'S\n \t Comida a domicilio en pro del ambiente \n"
     <<"\t -----------------------------------------\n "
     <<" \t  Factura No.\t"<<IdPedido<<endl
     <<" \t  Hora del pedido:  "<<horaPedido<<" horas con "<<minPedido<<" minutos"<<endl
     <<" \t  Restaurante:\t"<<restauranteP<<endl
     <<" \t  Repartidor a cargo:\t"<<repartidorP<<endl
     <<"\t -----------------------------------------\n "
     <<" \t  SR(a). \t"<<clienteP<<endl
     <<"\t -----------------------------------------\n "                                      //  FALTA EL METODO DE COSTO
     <<" \t  COMBO(s):"<<endl<<endl
     <<" \t  \tSubtotal:\t"<<costoTotalPedido<<" colones"<<endl
     <<" \t  \tIVA:\t \t"<<costoTotalPedido*0.13<<" colones"<<endl
     <<" \t  \tTOTAL NETO:\t"<<costoTotalPedido*0.13+costoTotalPedido<<" colones"<<endl
     <<"\n \t -----------------------------------------\n"
     <<" \t  hora de entrega:  "<<horaEntrega<<" horas con "<<minEntrega<<" minutos"<<endl
     <<" \t  Distancia del pedido:\t"<<distanciaP<<endl
     <<" \t  Quejas:\t"<<queja<<endl
     <<" \n \t  \t Gracias por su compra \n ";
    return s.str();

}
float Pedido::generarCostoDelPedido(int valor){

    return combos[valor];
}
string Pedido::Lista_Precios(){ // Lista los precios de los combos de cualquier restaurante
    stringstream s;
    s<<"\n \t \t Lista de combos:\n";
    for(int i=0; i<9;i++){
        s<<"\t \t \t Combo "<<i+1<<": "<<combos[i]<<" colones \n";
    }
    return s.str();
}

void Pedido::autoGuardar(ofstream& dato) {
	//cout << "    <<Guardando>>" << endl;
	//cout << toStringCliente() << endl;
	dato<< getIdPedido()<< endl
        << getClienteP()  << endl
		<< getRepartidorP() << endl
		<< getRestauranteP() << endl
		<< getHoraPedido() << endl
		<< getMinPedido() <<endl
		<< getHoraEntrega() << endl
		<< getMinEntrega() << endl
		<< getCostoTotalPedido() <<endl
		<< getQueja()<<endl
		<< getDistanciaP()<<endl;

}

Pedido*  Pedido::autoLeer(ifstream& dato) {

        char variable_aux[30];
        string IdPedido, clienteP, repartidorP, restauranteP;
        // se crean variables auxiliares para despues convertirlas a float y a int
        string HPedido, MPedido, HEntrega, MEntrega, costo, quej, dis;
        float costoTotalPedido, distanciaP;
        int horaPedido, minPedido, horaEntrega, minEntrega, queja;


        (dato.getline(variable_aux, sizeof(variable_aux)));
        if(dato.good()) {// si se pudo leer
                IdPedido = variable_aux;
                if(dato.eof()){exit(1);}
                (dato.getline(variable_aux, sizeof(variable_aux)));
            if(dato.good()) {// si se pudo leer
                    clienteP = variable_aux;
                    if(dato.eof()){exit(1);}
                    (dato.getline(variable_aux, sizeof(variable_aux)));
                if(dato.good()) {// si se pudo leer
                        repartidorP = variable_aux;
                        if(dato.eof()){exit(1);}
                        (dato.getline(variable_aux, sizeof(variable_aux)));
                    if(dato.good()) {// si se pudo leer
                            restauranteP = variable_aux;
                            if(dato.eof()){exit(1);}
                            (dato.getline(variable_aux, sizeof(variable_aux)));
                         if(dato.good()) {// si se pudo leer
                                HPedido = variable_aux;
                                horaPedido = stoi(HPedido);
                                if(dato.eof()){exit(1);}
                                (dato.getline(variable_aux, sizeof(variable_aux)));
                            if(dato.good()) {// si se pudo leer
                                    MPedido = variable_aux;
                                    minPedido = stoi(MPedido);
                                    if(dato.eof()){exit(1);}
                                    (dato.getline(variable_aux, sizeof(variable_aux)));
                                if(dato.good()) {// si se pudo leer
                                        HEntrega = variable_aux;
                                        horaEntrega = stoi(HEntrega);
                                        if(dato.eof()){exit(1);}
                                        (dato.getline(variable_aux, sizeof(variable_aux)));
                                    if(dato.good()) {// si se pudo leer
                                            MEntrega = variable_aux;
                                            minEntrega = stoi(MEntrega);
                                            if(dato.eof()){exit(1);}
                                            (dato.getline(variable_aux, sizeof(variable_aux)));
                                        if(dato.good()) {// si se pudo leer
                                                costo = variable_aux;
                                                costoTotalPedido = stof(costo);
                                                if(dato.eof()){exit(1);}
                                                (dato.getline(variable_aux, sizeof(variable_aux)));
                                            if(dato.good()) {// si se pudo leer
                                                    quej = variable_aux;
                                                    queja = stoi(quej);
                                                    if(dato.eof()){exit(1);}
                                                    (dato.getline(variable_aux, sizeof(variable_aux)));
                                                if(dato.good()) {// si se pudo leer
                                                    dis = variable_aux;
                                                    distanciaP = stof(dis);
                                                    if(dato.eof()){exit(1);}
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    if (repartidorP!=""||clienteP!=""){
            //cout << "\n \t  -- Se estan cargando los registro" << endl;
            return new Pedido( IdPedido,  clienteP,  repartidorP,  restauranteP,  horaPedido,  minPedido,  horaEntrega,  minEntrega,  costoTotalPedido, queja, distanciaP );
    }else{
        return NULL;}

}
