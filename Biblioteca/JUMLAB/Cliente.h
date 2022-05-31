#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"


class Cliente: public Persona
{
    public:
        Cliente();
        Cliente(bool estado,string nombre,string cedula,string correo,int celular,string direccion,string Ntarjeta);
        virtual ~Cliente();

        //get's y set's
        void setEstado(bool estado);
        bool getEstado();

        //metodos
        string toStringCliente(); // imprime de acuerdo al estado

        //ARCHIVOS
        void autoGuardar(ofstream&);
        static Cliente* autoLeer(ifstream&);

    private:
        bool estado;
};

#endif // CLIENTE_H
