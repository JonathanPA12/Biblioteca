#ifndef PEDIDO_H
#define PEDIDO_H
#include "Restaurante.h"
#include "Repartidor.h"
#include "Cliente.h"

class Pedido
{
    public:
        Pedido();
        virtual ~Pedido();
        Pedido(string IdPedido, string clienteP, string repartidorP,
               string restauranteP, int horaPedido, int minPedido,
               int horaEntrega, int minEntrega, float costoTotal, bool queja, float distanciaP );

         void setIdPedido (string IdPedido);
         string getIdPedido();
         void setClienteP (string clienteP);
         string getClienteP();
         void setRepartidorP (string repartidorP);
         string getRepartidorP();
         void setRestauranteP (string restauranteP);
         string getRestauranteP();
         void setHoraPedido (int horaPedido);
         int getHoraPedido();
         void setMinPedido (int minPedido);
         int getMinPedido();
         void setHoraEntrega (int horaEntrega);
         int getHoraEntrega();
         void setMinEntrega (int minEntrega);
         int getMinEntrega();
         void setCostoTotalPedido (float costoTotalPedido);
         float getCostoTotalPedido();
         void setQueja (bool queja);
         bool getQueja();
         void setDistanciaP (float distanciaP);
         float getDistanciaP();

         string toStringFactura();
         float generarCostoDelPedido(int valor);
         string Lista_Precios();

         //ARCHIVOS
        void autoGuardar(ofstream&);
        static Pedido* autoLeer(ifstream&);


    private:

        string IdPedido;
        string clienteP;
        string repartidorP;
        string restauranteP;
        int horaPedido;
        int minPedido;
        int horaEntrega;
        int minEntrega;
        float costoTotalPedido;
        bool queja;
        float *combos;
        float distanciaP;
                                                           // vector de precio de los combos

};

#endif // PEDIDO_H
