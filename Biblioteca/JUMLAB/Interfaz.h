#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Lista.h"
#include "Pedido.h"

#include <fstream>
#include <bits/stdc++.h>

class Interfaz
{
    public:
        /** Default constructor */
        Interfaz();
        /** Default destructor */
        virtual ~Interfaz();
        void menu();
        string aleatoreo();
        int ValidacionNum(char num[5]);

    protected:

    private:
};

#endif // INTERFAZ_H
