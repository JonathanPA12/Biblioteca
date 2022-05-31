#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include <bits/stdc++.h> // sirve para utilizar casi todas las librerias
using namespace std;

class Restaurante
{
    public:

        Restaurante(string nombre_res, string cedula_juridica, string direccion_res, string TipoDeComida);
        Restaurante();
        virtual ~Restaurante();

        //set's
        void setNombre_Res(string nombre_res);
        void setCedula_juridica(string cedula);
        void setDireccion_Res(string direccion_res);
        void setTipoDeComida(string TipoDeComida);

        //get's
        string getNombre_Res();
        string getCedula_juridica();
        string getDireccion_Res();
        string getTipoDeComida();

        //Metodos
        string toStringRestaurante();                                              // lista de todos los restaurantes "PUNTO H"
        string Lista_TipoComida();                                              // lista solo el restaurante y el tipo de comida "PARA EL MENU inicial"

        double Ganancia();  //falta desarrollar
                                                    // Lista los precios de los combos de cualquier restaurante "Para el menu secundario"

         //ARCHIVOS
        void autoGuardar(ofstream&);
        static Restaurante* autoLeer(ifstream&);


    private:
        string nombre_res;                                                        // es el Id
        string cedula_juridica;                                              //cedula juridica
        string direccion_res;
        string TipoDeComida;



};

#endif // RESTAURANTE_H
