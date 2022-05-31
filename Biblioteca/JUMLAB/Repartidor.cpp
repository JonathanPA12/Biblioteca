#include "Repartidor.h"

Repartidor::Repartidor(){

    this->amonestaciones= 0;
    this->distancia = 0.0;
    this->KM = 0.0;
    this->costo= 0.0;
    this->estado = true;
    this->quejaR=quejaR;
    Persona();
}

Repartidor::~Repartidor(){

}

Repartidor::Repartidor(string cedula, string quejaR){
     this->setCedula(cedula);
     this->quejaR=quejaR;
}

Repartidor::Repartidor(string nombre,string cedula,string correo,int celular,string direccion,string Ntarjeta,
                       float distancia,float KM,float costo,int amonestaciones, bool estado){


    //clase: Repartidor
    this->distancia=distancia;
    this->KM=KM;
    this->costo=costo;
    this->amonestaciones=amonestaciones;
    this->estado =estado;

    //Clase persona
    this->setNombre(nombre);
    this->setCedula(cedula);
    this->setCorreo(correo);
    this->setCelular(celular);
    this->setDireccion(direccion);
    this->setNtarjeta(Ntarjeta);
}

void Repartidor::setDistancia(float distancia){
    this->distancia=distancia;
}
void Repartidor::setKM(float KM){
    this->KM=KM;
}
void Repartidor::setCosto(float costo){
    this->costo=costo;
}
void Repartidor::setAmonestaciones(int amonestaciones){
    this->amonestaciones=amonestaciones;
}
void Repartidor::setEstado(bool estado){
    this->estado =estado;
}
void Repartidor::setQuejaR(string quejaR){
    this->quejaR =quejaR;
}
float Repartidor::getDistancia(){
    return distancia;
}
float Repartidor::getKM(){
    return KM;
}
float Repartidor::getCosto(){
    return costo;
}
int Repartidor::getAmonestaciones(){
    return amonestaciones;
}
bool Repartidor::getEstado(){
    return estado;
}
string Repartidor::getQuejaR(){
    return quejaR;
}

string Repartidor::toStringRepartidor(){

    stringstream repartidor;
   // system("color 0E");
    repartidor<<"\t -----------------------------------------\n ";
    repartidor<<toStringPersona();                                      //reciclamos el tostring de la clase persona
    repartidor<<" \t  Distancia recorrida:\t"<<distancia<<endl;
    repartidor<<" \t  KM diarios:\t"<<KM<<endl;
    repartidor<<" \t  Costo por KM:\t"<<costo<<endl;                                        //  FALTA EL METODO DE COSTO
    repartidor<<" \t  Cantidad de amonestaciones:\t"<<amonestaciones<<endl;
    if(estado==true){                                                      //se verifica el estado del repartidor
        repartidor<<" \t  Estado del repartidor: \tDisponible";
    }else{
        repartidor<<" \t  Estado del repartidor: \tOcupado";
    }
    repartidor<<"\n \t -----------------------------------------";
    return repartidor.str();
}
string Repartidor::toStringRepartidorQuejas(){

    stringstream repartidor;
    repartidor<<"\t -----------------------------------------\n ";
    repartidor<<" \t  Cedula:\t"<<getCedula()<<endl;
    repartidor<<" \t  Queja:\t"<<getQuejaR()<<endl;
    repartidor<<"\n \t -----------------------------------------";
    return repartidor.str();
}

void Repartidor::autoGuardar(ofstream& dato) {
	//cout << "    <<Guardando>>" << endl;
	//cout << toStringRepartidor() << endl;
	dato<< getNombre()<< endl
		<< getCedula()<< endl
		<< getCorreo()<< endl
		<< getCelular()<< endl
		<< getDireccion()<<endl
		<< getNtarjeta()<<endl
		<< getDistancia()<<endl
		<< getKM()<<endl
		<< getCosto()<<endl
		<< getAmonestaciones()<<endl
		<< estado<<endl;
}

Repartidor*  Repartidor::autoLeer(ifstream& dato) {

        char variable_aux[30];
        string nombre, cedula, correo, direccion, Ntarjeta;
        // se crean variables auxiliares para despues convertirlas a float y a int
        string dis, kiloMetros, costos, amone, est, cel;
        float distancia, KM, costo;
        int amonestaciones, celular;
        bool estado;

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
                                    (dato.getline(variable_aux, sizeof(variable_aux)));
                                if(dato.good()) {// si se pudo leer
                                        dis = variable_aux;
                                        distancia = stof(dis);
                                        if(dato.eof()){exit(1);}
                                        (dato.getline(variable_aux, sizeof(variable_aux)));
                                    if(dato.good()) {// si se pudo leer
                                            kiloMetros = variable_aux;
                                            KM = stof(kiloMetros);
                                            if(dato.eof()){exit(1);}
                                            (dato.getline(variable_aux, sizeof(variable_aux)));
                                        if(dato.good()) {// si se pudo leer
                                                costos = variable_aux;
                                                costo = stof(costos);
                                                if(dato.eof()){exit(1);}
                                                (dato.getline(variable_aux, sizeof(variable_aux)));
                                            if(dato.good()) {// si se pudo leer
                                                    amone = variable_aux;
                                                    amonestaciones = stoi(amone);
                                                    if(dato.eof()){exit(1);}
                                                    (dato.getline(variable_aux, sizeof(variable_aux)));
                                                 if(dato.good()) {// si se pudo leer
                                                        est = variable_aux;
                                                        estado = stoi(est);
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

    if (nombre!=""||cedula!=""){
            //cout << "\n \t  -- Se estan cargando los registro" << endl;
            return new Repartidor(nombre,cedula,correo,celular,direccion,Ntarjeta,
                                  distancia,KM,costo,amonestaciones,estado);
    }else{
        return NULL;}


}
void Repartidor::autoGuardarQueja(ofstream& dato) {
	//cout << "    <<Guardando>>" << endl;
	//cout << toStringRepartidor() << endl;
	dato<< getCedula()<< endl
		<< getQuejaR()<<endl;
}

Repartidor*  Repartidor::autoLeerQueja(ifstream& dato) {
        char variable_aux[70];
        string cedula, quejaR;
        (dato.getline(variable_aux, sizeof(variable_aux)));
        if(dato.good()) {// si se pudo leer
                cedula = variable_aux;

                if(dato.eof()){exit(1);}
                (dato.getline(variable_aux, sizeof(variable_aux)));
            if(dato.good()) {// si se pudo leer
                    quejaR = variable_aux;

                    if(dato.eof()){exit(1);}
                                }
        }
    if (cedula!=""||quejaR!=""){
            //cout << "\n \t  -- Se estan cargando los registro" << endl;
            return new Repartidor(cedula, quejaR);
    }else{
        return NULL;
        }
}
