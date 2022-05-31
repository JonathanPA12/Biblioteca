#ifndef NODO_H
#define NODO_H
#include "Cliente.h"
#include "Repartidor.h"
#include "Restaurante.h"
#include "Pedido.h"

class Nodo
{
    public:

        //Destructor
        virtual ~Nodo();

        //Objetos Puntero "son publicos"
        Persona *Pdato;
        Cliente *Cdato;
        Repartidor *RepDato;
        Restaurante *ResDato;
        Pedido *PedDato;
        Nodo *sigNodo;


        //Constructores
        Nodo(Persona*, Nodo*);
        Nodo(Cliente*, Nodo*);
        Nodo(Repartidor*, Nodo*);
        Nodo(Restaurante*, Nodo*);
        Nodo(Pedido*, Nodo*);

        //set's
        void  setPdato (Persona *Pdato);
        void  setCDato(Cliente *Cdato);
        void  setRepDato(Repartidor *RepDato);
        void  setResDato(Restaurante *ResDato);
        void  setPedDato(Pedido *PedDato);
        void  setSigNodo(Nodo *sigNodo);


        //get's
        Persona *getPdato();
        Cliente *getCdato();
        Repartidor *getRepDato();
        Restaurante *getResDato();
        Pedido *getPedDato();
        Nodo * getSigNodo();

        //Metodos to string
        string toStringC();// cliente
        string toStringRep();//
        string toStringRepQuejas();
        string toStringRes();
        string toStringPed();
        string toStringMenuRes();

    private:
    //No hay

};

#endif // NODO_H
