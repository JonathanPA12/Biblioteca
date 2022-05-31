#ifndef REPARTIDOR_H
#define REPARTIDOR_H
#include "Persona.h"


class Repartidor:public Persona
{
    public:
        Repartidor(string nombre,string cedula,string correo,int celular,string direccion,string Ntarjeta,
                       float distancia,float KM,float costo,int amonestaciones, bool estado);
        Repartidor(string cedula, string quejaR);
        Repartidor();
        virtual ~Repartidor();

        //set's
        void setDistancia(float distancia);
        void setKM(float distancia);
        void setCosto(float costo);
        void setAmonestaciones(int amonestaciones);
        void setEstado(bool estado);
        void setQuejaR(string quejaR);

        //get's
        float getDistancia();
        float getKM();
        float getCosto();
        int getAmonestaciones();
        bool getEstado();
        string getQuejaR();

        // metodos
        string toStringRepartidor();
        string toStringRepartidorQuejas();


        //ARCHIVOS
        void autoGuardar(ofstream&);
        static Repartidor* autoLeer(ifstream&);

        void autoGuardarQueja(ofstream&);
        static Repartidor* autoLeerQueja(ifstream&);


    private:
        float distancia;
        float KM;
        float costo;
        int amonestaciones;
        bool estado;
        string quejaR;
};

#endif // REPARTIDOR_H
