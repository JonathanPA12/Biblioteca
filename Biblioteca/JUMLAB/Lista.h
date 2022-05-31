#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"


class Lista { //Esta es la de archivos??

    public:
                                            ///////////////Falta agregar la clase pedido//////////////////
        Lista();
        virtual ~Lista();

        //Metodos
        void AgregarCliente(Cliente *); /** PUNTO "a" DEL REPORTE */
        void AgregarRestaurante(Restaurante *);/** PUNTO "b" DEL REPORTE */
        void AgregarRepartidor(Repartidor *);/** PUNTO "c" DEL REPORTE */
        void AgregarPedido(Pedido *);/** PUNTO "d" DEL REPORTE */

        string ListarClientes(); /** PUNTO "e" y "f" DEL REPORTE */
        string ListarClientesINACTIVOS();
        string ListarRepartidores();/** PUNTO "g" DEL REPORTE */
        string ListarRepartidoresQuejas();
        string ListarRestaurantes();/** PUNTO "h" DEL REPORTE */
        string ListarMenuRestaurante();
        string ListarPedidos();/** PUNTO "n" DEL REPORTE */

        string consultarDatoEspecificoCliente(string Id_a_buscar);
        string consultarNombredelCliente(string Id_a_buscar);
        string consultarDatoEspecificoRestaurante(string Id_a_buscar);
        string consultarDatoEspecificoRepartidor(string Id_a_buscar);
        string consultarDatoEspecificoPedido(string Id_a_buscar);

        int contar(); // me da la cantidad de registros que hay
        bool IsEmpty();

        string EleccionRepartidor();


    private:

        Nodo *cabeza;
        Nodo *actual;
        Nodo *cola;


};

#endif
