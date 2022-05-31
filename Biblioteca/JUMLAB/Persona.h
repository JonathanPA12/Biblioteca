#ifndef PERSONA_H
#define PERSONA_H
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Persona
{
    public:
        Persona();
        Persona(string nombre,string cedula,string correo,int celular,string direccion,string Ntarjeta);
        virtual ~Persona();

        //set's
        void setNombre(string nombre);
        void setCedula(string cedula);
        void setCorreo(string correo);
        void setCelular(int celular);
        void setDireccion(string direccion);
        void setNtarjeta(string Ntarjeat);
        //get's
        string getNombre();
        string getCedula();
        string getCorreo();
        int getCelular();
        string getDireccion();
        string getNtarjeta();

        string toStringPersona(); // tostring de la clase persona


    private:
        string nombre;
        string cedula;
        string correo;
        int celular;
        string direccion;
        string Ntarjeta;
};

#endif // PERSONA_H
