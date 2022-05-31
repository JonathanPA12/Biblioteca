#include "Interfaz.h"
#include <locale.h>
#include<stdio.h>

Interfaz::Interfaz(){}
Interfaz::~Interfaz(){}

string Interfaz::aleatoreo(){
    stringstream ss;
    int alea= rand()% 1818181818;
    ss<<alea;
    return ss.str();
}


int Interfaz::ValidacionNum(char num[5]){
    int i=0, v=0, largo;
    largo = strlen(num);
    while(v==0&&i<largo){
        if(isdigit(num[i])!=0){
            i++;
        }
        else{
            v=1;
        }
    }
    return v;
}

void Interfaz::menu(){

       //inicializo variables
       string opcMenu="", validacion="";

       //persona
        string nombre="";
        string cedula="";
        string correo="";
        int celular=0;                              //posible fallo
        string direccion="";
        string Ntarjeta="";

        //repartidor
        float distancia=0.0;
        float KM=0.0;
        float costo=0.0;
        int amonestaciones=0;
        bool estado;

        //restaurante
        string nombre_res="";                                                        // es el Id
        string cedula_juridica="";                                              //cedula juridica
        string direccion_res="";
        string TipoDeComida="";

        //pedido
        string IdPedido="";
        string clienteP="";
        string repartidorP="";
        string restauranteP="";
        int horaPedido=0;
        int minPedido=0;
        int horaEntrega=0;
        int minEntrega=0;
        float costoTotalPedido=0.0;
        bool queja;
        float distanciaP=0.0;


        ///Instancia de los objetos de archivos
        ifstream entrada; //expulsa datos el archivo
        ofstream salida; //recibe datos


        setlocale(LC_ALL,"spanish");

        //Instancia de objetos
        Restaurante*restaurante = new Restaurante();
        Repartidor *repartidor = new Repartidor();
        Repartidor *repartidorQueja= new Repartidor();
        Cliente *cliente=new Cliente();
        Pedido *pedido=new Pedido();
        Lista *listaPedido=new Lista();
        Lista *listaRepartidor=new Lista();
        Lista *listaRepartidorQuejas=new Lista();
        Lista *listaClientes=new Lista();
        Lista *listaRestaurante=new Lista();

   do{
		try{

        INTENTO:

            //<<<<<<<<<<<<Cargar archvios clientes<<<<<<<<<<<<<<<<<<<<<<<<<<<
		    cliente = NULL;
		    entrada.open("Cliente.txt");
		    while (entrada.good()){
            cliente = Cliente::autoLeer(entrada);
            if(entrada.good()&&cliente != NULL){
                    listaClientes->AgregarCliente(cliente);
                    }
                };
            entrada.close();

            //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        //---------------------------------------------------------------------------------------------------

                //listaRepartidor=new Lista();

                repartidor = NULL;
                entrada.open("Repartidores.txt");
                while (entrada.good()){
                repartidor = Repartidor::autoLeer(entrada);
                if (entrada.good()&&repartidor != NULL) {
                        listaRepartidor->AgregarRepartidor(repartidor);
                   }
               }
                entrada.close();

		    //---------------------------------------------------------------------------------------------------//

                            ///Metodo que carga los datos del archivo en la lista de pedidos
		   // ---------------------------------------------------------------------------------------------------//

                //listaPedido=new Lista();

                pedido = NULL;
                entrada.open("Pedidos.txt");
                while (entrada.good()){
                pedido = Pedido::autoLeer(entrada);
                if (entrada.good()&&pedido != NULL) {
                        listaPedido->AgregarPedido(pedido);

                   }
               }
                entrada.close();

		    //---------------------------------------------------------------------------------------------------//

		    ///Metodo que carga los datos del archivo en la lista de quejas
		   // ---------------------------------------------------------------------------------------------------//

               // listaRepartidorQuejas=new Lista();

                repartidorQueja = NULL;
                entrada.open("Quejas.txt");
                while (entrada.good()){
                repartidorQueja = Repartidor::autoLeerQueja(entrada);
                if (entrada.good()&&repartidorQueja != NULL) {
                        listaRepartidorQuejas->AgregarRepartidor(repartidorQueja);
                   }
               }

                entrada.close();

		    //---------------------------------------------------------------------------------------------------//


			system("cls"); //limpia la pantalla
			cout<<"\n \n \t >>>>>>>>>  Bienvenido a Cleta Eats <<<<<<<<<\n"
                <<"\t Menú: \n"
				<<" \t \t1. Repartidores\n"
				<<" \t \t2. Clientes\n"
				<<" \t \t3. Restaurantes\n"
				<<" \t \t4. Pedidos\n"
				<<" \t \t5. Salir\n";
				cout<<"\n \t Digite Opcion: ";
			getline(cin,opcMenu); //No CIN para string
            if(opcMenu!="1"&&opcMenu!="2"&&opcMenu!="3"&&opcMenu!="4"&&opcMenu!="5"){
				throw opcMenu;
			} //fin del if

			switch(stoi(opcMenu)){ //stoi me convierte de string a int
            ///--------------------------------------------------------------------------------------------------------------------------------//
			case 1:{
				system("cls");
				string oprep;
				do{
                        try{
                            system("cls");
                            cout<<"\n \t Digite la opcion que desea\n"

                                <<" \t \t1. Verificar si el repartidor esta inscrito\n" ///punto m)
			                	<<" \t \t2. Listar repartidores sin amonestaciones\n" ///punto g)
			                	<<" \t \t3. Listar quejas por repartidor\n"         ///punto m)
			                	<<" \t \t4. Modificar el estado del repartidor\n"
			                	<<" \t \t5. Salir\n";
			                	cout<<"\tDigite Opcion: ";
				                getline(cin,oprep); //No CIN para string
				                if(oprep!="1"&&oprep!="2"&&oprep!="3"&&oprep!="4"&&oprep!="5"){
				                throw oprep;}
				                switch(stoi(oprep)){
				                    //--------------------------------------------------------------------------------------------------------------------------//
				                    case 1:{ // verificar si esta inscrito


                                            cout<<"\t \t ----------Proceso de consulta de la inscripcion de un repartidor----------\n";
                                            cout << "\t \t Digite la cedula del repartidor a consultar: ";
                                            getline(cin,cedula);


                                            if(listaRepartidor->IsEmpty()){
                                            cout <<" \n \t \t -----------No hay datos en el registro-----------\n \n \t \t";
                                            cout<<"Desea inscribir al repartidor? \n \t \t \t 1. Si \n \t \t \t 2. No";
                                            string x="";
                                            cout<<"\n \t \t Digite Opcion: ";
                                            cin>>x;
                                            while(x!="1"&&x!="2"){
                                                cout<<"\n \t Opcion no valida \n \t Digite opcion: ";
                                                cin>>x;
                                            }
                                            if(x=="1"){
                                                    cout<<"\t \t ----------Proceso de inscripción de repartidores----------\n";
                                                    cout<<"\t \t Digite la cedula : ";
                                                    cin.get();
                                                    getline(cin,cedula);
                                                    validacion=listaRepartidor->consultarDatoEspecificoRepartidor(cedula);
                                                    while(validacion!="2"&&validacion!="0"){
                                                         cout << "\n \t \t Ya existe un registro con dicha cedula \n";
                                                         cout<<"\t \t Por favor digite una cedula nueva: ";
                                                         getline(cin,cedula);
                                                         validacion=listaRepartidor->consultarDatoEspecificoRepartidor(cedula);
                                                    }

                                                cout<<"\t \t Digite la nombre: ";
                                                getline(cin,nombre);
                                                cout<<"\t \t Digite la correo: ";
                                                getline(cin,correo);
                                                cout<<"\t \t Digite celular: ";
                                                cin>>celular;
                                                cin.get();
                                                cout<<"\t \t Digite la direccion: ";
                                                getline(cin,direccion);
                                                //cin.get();
                                                cout<<"\t \t Digite numero de tarjeta : ";
                                                getline(cin,Ntarjeta);
                                                cout<<"\t \t Estado del repartidor: Activo";
                                                estado=true;
                                                distancia =0.0;
                                                KM  =0.0;
                                                costo  =0.0;
                                                amonestaciones = 0;

                                                repartidor= new Repartidor(nombre,cedula,correo,celular,direccion,Ntarjeta,distancia,KM,costo,amonestaciones,estado);

                                                ///metodos de archivos
                                                salida.open("Repartidores.txt", ios::app);
                                                repartidor->autoGuardar(salida);
                                                salida.close();
                                                delete repartidor;
                                                    ///

                                                cout<<"\n \t \t ---------Los datos han sido registrados! ---------\n";
                                                system("pause");

                                                break;
                                                }else{
                                                    cout<<" volviendo al menu de repartidor";
                                                    break;}
                                            }
                                            else{
                                                    validacion=listaRepartidor->consultarDatoEspecificoRepartidor(cedula);

                                                    if(validacion=="2"){
                                                    cout << "\n \t \t No hay un repartidor con dicha cedula en el registro \n \n \t \t";
                                                    cout<<"Desea inscribir al repartidor? \n \t \t \t 1. Si \n \t \t \t 2. No";
                                                    string x="";
                                                    cout<<"\n \t \t Digite Opcion: ";
                                                    cin>>x;
                                                    while(x!="1"&&x!="2"){
                                                        cout<<"\n \t Opcion no valida \n \t Digite opcion: ";
                                                        cin>>x;
                                                    }
                                                    if(x=="1"){
                                                        cout<<"\t \t ----------Proceso de inscripción de repartidores----------\n";
                                                        cout<<"\t \t Digite la cedula : ";
                                                        cin.get();
                                                        getline(cin,cedula);
                                                        validacion=listaRepartidor->consultarDatoEspecificoRepartidor(cedula);
                                                        while(validacion!="2"&&validacion!="0"){
                                                             cout << "\n \t \t Ya existe un registro con dicha cedula \n";
                                                             cout<<"\t \t Por favor digite una cedula nueva: ";
                                                             getline(cin,cedula);
                                                             validacion=listaRepartidor->consultarDatoEspecificoRepartidor(cedula);
                                                        }// revisar si funciona o se debe agregar una varible extra

                                                    cout<<"\t \t Digite la nombre: ";
                                                    getline(cin,nombre);
                                                    cout<<"\t \t Digite la correo: ";
                                                    getline(cin,correo);
                                                    cout<<"\t \t Digite celular: ";
                                                    cin>>celular;
                                                    cin.get();
                                                    cout<<"\t \t Digite la direccion: ";
                                                    getline(cin,direccion);
                                                    cout<<"\t \t Digite numero de tarjeta : ";
                                                    getline(cin,Ntarjeta);
                                                    cout<<"\t \t Estado del repartidor: Activo";
                                                    estado=true;
                                                    distancia =0.0;
                                                    KM  =0.0;
                                                    costo  =0.0;
                                                    amonestaciones = 0;

                                                    repartidor= new Repartidor(nombre,cedula,correo,celular,direccion,Ntarjeta,distancia,KM,costo,amonestaciones,estado);


                                                    ///metodos de archivos
                                                    salida.open("Repartidores.txt", ios::app);
                                                    repartidor->autoGuardar(salida);
                                                    salida.close();
                                                    delete repartidor;
                                                    ///

                                                    cout<<"\n \t \t ---------Los datos han sido registrados! ---------\n";
                                                    system("pause");

                                                    break;
                                                    }else{
                                                        cout<<"\n \t \t Volviendo al menu principal... ";
                                                        goto INTENTO;
                                                        break;}
                                                }
                                                else{
                                                    cout<<"\n \t \t ---------El repartidor ya esta inscrito en el registrado! ---------\n";
                                                    cout<< "\n \t  -->Sus datos se muestran a continuacion: \n";
                                                    cout << validacion << "\n";
                                                }
                                            }

                                      //  cin.get();
                                        system("pause");

				                        break;
                                    }
                                     //--------------------------------------------------------------------------------------------------------------------------//
                                    case 2:{ // listar repartidores con 0 amonestaciones

                                        if(listaRepartidor->IsEmpty()==true){
                                           cout <<" \n \t \t -----------No hay datos en el registro-----------\n \n \t \t";

                                       }else{
                                            cout<<"\n \t \t Los datos de los repartidores con 0 amonestaciones son los siguientes: \n";
                                            cout << listaRepartidor->ListarRepartidores()<<endl;
                                        }

                                        system("pause");
				                        break;
                                    }// final del case 2
                                     //--------------------------------------------------------------------------------------------------------------------------//
   /** Falta */                     case 3:{ // listar quejas por repartidor


                                        if(listaRepartidorQuejas->IsEmpty()==true){
                                           cout <<" \n \t \t -----------No hay datos en el registro-----------\n \n \t \t";

                                       }else{
                                            cout<<"\n \t \t Los datos de las quejas obtenidas son: \n";
                                            cout << listaRepartidorQuejas->ListarRepartidoresQuejas()<<endl;
                                        }

                                        system("pause");

				                        break;
                                    }
                                     //--------------------------------------------------------------------------------------------------------------------------//
                                    case 4:{ // modificar el estado del repartidor

                                        if(listaRepartidor->IsEmpty()==true){
                                            cout <<" \n \t \t -----------No hay datos en el registro-----------\n \n \t \t";

                                        }else{
                                            cout<<"\t \t ----------Proceso de modificacion de datos del registro de repartidores----------\n";
                                            cout << "\t \t Digite la cedula del repartidor a cambiar estado: ";

                                            getline(cin,cedula);

                                            ///metodos de archivos
                                            ofstream prueba;
                                            entrada.open("Repartidores.txt"); // abro el archivo para leer
                                            prueba.open("RepartidoresTemporal.txt"); // abro el archivo para escribir
                                            repartidor = NULL;

                                            while (entrada.good()){
                                                    repartidor = Repartidor::autoLeer(entrada); // leo el archivo hasta completar un objeto cliente y lo guardo en nuevo_dato
                                                    if (repartidor != NULL&&repartidor->getCedula()!=cedula) { // si la identificacion es diferente entonces
                                                        repartidor->autoGuardar(prueba); //guardo los demas objetos en el archivo de prueba
                                                    }
                                                    if (repartidor != NULL&&repartidor->getCedula()==cedula){
                                                            if(repartidor->getEstado()==true){
                                                            estado=false;
                                                            repartidor->setEstado(estado);
                                                            repartidor->autoGuardar(prueba);
                                                        } else{
                                                            estado=true;
                                                            repartidor->setEstado(estado);
                                                            repartidor->autoGuardar(prueba);
                                                        }
                                                    }
                                            }
                                            entrada.close(); // cierro los archivos
                                            prueba.close();
                                            remove("Repartidores.txt"); // borro el archivo contactos
                                            rename("RepartidoresTemporal.txt", "Repartidores.txt"); //renonbro el temporal
                                            ///
                                            cout<<"\n \t \t ---------El estado ha sido modificados! ---------\n";
                                        }
                                        system("pause");
                                        break;

                                    }// fin del case 4
                                     //--------------------------------------------------------------------------------------------------------------------------//
                                    case 5:{
                                        cout<<"\n \t \t Volviendo al menu principal... ";
                                        goto INTENTO;
                                        system("pause");
                                        break;

                                    } // fin del case 5
				                }//break; //fin del switch
                        }catch(string oprep){ //fin del catch
									system("cls");
									cout<<"Error, digite una opción correcta\n";
									system("pause");
								}
							}while(true); //fin del do
							break;
                } //fin del case 1
            ///--------------------------------------------------------------------------------------------------------------------------------//
			Clientes:

                case 2:{
				system("cls");
				string op;
				do{
                        try{
                            system("cls");
                            cout<<"Digite la opcion que desea\n"
                                <<"1. Verificar si el cliente esta inscrito\n"
                                <<"2. Cancelar suscripción\n" // pasar de activo a inactivo
			                	<<"3. Listar clientes activos\n"
			                	<<"4. Listar clientes inactivos\n"
			                	<<"5. Cliente con mayor numero de pedidos\n"
				                <<"6. Salir\n";
				                getline(cin,op); //No CIN para string
				                if(op!="1"&&op!="2"&&op!="3"&&op!="4"&&op!="5"&&op!="6"){
				                throw op;}
				                switch(stoi(op)){//volver un string a int
                                          //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
				                    case 1:{
                                            system("cls");
				                          cout<<"\t \t ----------Proceso de consulta de la inscripcion del cliente----------"<<endl;
                                            cout << "\t \t Digite la identificacion a consultar: ";
                                            getline(cin,cedula);


                                            if(listaClientes->IsEmpty()){
                                            system("cls");
                                            cout <<" \n \t \t -----------No hay usuarios en el sistema-----------\n \n \t \t";
                                            system("pause");
                                             system("cls");
                                             int x=0;

                                            cout<<"¿Desea Registrarse? \n \t \t \t 1. Si \n \t \t \t 2. No";
                                            cout<<"\n \t \t Digite Opción: ";
                                            cin>>x;

                                                while(x!=1&&x!=2){
                                                cout<<"\n \t Opción inválida \n \t Digite opción: ";
                                                cin>>x;}
                                            //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

                                            if(x==1){                                                                                   //Si la opcion es uno, procede a suscribirse
                                                    cout<<"\t \t ----------Proceso de suscripción en CletaEats----------\n";
                                                    cout<<"\t \t Digite su identificación : ";
                                                    cin.get();
                                                    getline(cin,cedula);
                                                    validacion=listaClientes->consultarDatoEspecificoCliente(cedula);

                                                         while(validacion!="2"&&validacion!="0"){                                     //0-> esta vacia la lista y 2-> si no hay ninguna id dentro del sistema
                                                         cout << "\n \t \t Ya existe un usuario con esta identificación o no hay ningun usuario registrado con el ID "<<cedula<<"\n";
                                                         cout<<"\t \t Por favor, digite una identificación válida: ";
                                                         getline(cin,cedula);                                                   //ingresa la cedula de nuevo la cedula
                                                         validacion=listaClientes->consultarDatoEspecificoCliente(cedula);      //Estoy reutilizando la varianble (VALIDACION)
                                                    }
                                                  //Datos de suscripcion

                                                cout<<"\t \t Digite el nombre de usuario: ";
                                                getline(cin,nombre);
                                                cout<<"\t \t Digite su correo: ";
                                                getline(cin,correo);
                                                cout<<"\t \t Digite el número de celular: ";
                                                cin>>celular;
                                                cin.get();
                                                cout<<"\t \t Digite la direccion exacta: ";
                                                cin.get();
                                                getline(cin,direccion);
                                                cout<<"\t \t Digite numero de tarjeta: ";
                                                getline(cin,Ntarjeta);
                                                cout<<"\t \t Estado del usuario:##&?#$!! Activo";
                                                estado=true;
                                                cliente= new Cliente(estado,nombre,cedula,correo,celular,direccion,Ntarjeta);                           //Se registra el cliente

                                                ///metodos de archivos para cliente
                                                system("cls");
                                                salida.open("Cliente.txt", ios::app);                                                                   //ios::app-> introducir al final de cada linea y no sobreescribibir datos
                                                cliente->autoGuardar(salida);
                                                salida.close();
                                                delete cliente;

                                                cout<<"\n \t \t ---------Gracias por registrarse en nuestra app!---------\n";
                                                system("pause");

                                                 //<<<<<<<<<<<<Cargar archvios clientes<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                                cliente = NULL;
                                                entrada.open("Cliente.txt");
                                                while (entrada.good()){
                                                cliente = Cliente::autoLeer(entrada);
                                                if(entrada.good()&&cliente != NULL){
                                                        listaClientes->AgregarCliente(cliente);
                                                        }
                                                    };
                                                entrada.close();
                                                //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                                break;

                                                }else{                                  //uso variable entera
                                                    cout<<" Regresando a Menu Cliente"<<endl;

                                                    system("pause");
                                                    break;
                                                }

                                            }else{
                                              //  bool estado=true;                                                                            //if ISNTEMPTY()
                                                    validacion=listaClientes->consultarDatoEspecificoCliente(cedula);

                                                    if(validacion=="2"){
                                                    cout << "\n \t \t No hay ningún cliente registrado con el ID "<<cedula<<" \n \n \t \t";
                                                    system("pause");

                                                    string x="";
                                                    cout<<"Desea suscribirse? \n \t \t \t 1. Si \n \t \t \t 2. No";
                                                    cout<<"\n \t \t Digite Opción: ";
                                                    cin>>x;
                                                    while(x!="1"&&x!="2"){
                                                        cout<<"\n \t Opcion no válida \n \t Digite opción: ";
                                                        cin>>x;
                                                    }

                                                    if(x=="1"){
                                                        cout<<"\t \t ----------Proceso de suscripcion en CletaEats----------\n";
                                                        cout<<"\t \t Digite su identificación: ";
                                                        cin.get();
                                                        getline(cin,cedula);
                                                        validacion=listaClientes->consultarDatoEspecificoCliente(cedula);

                                                        while(validacion!="2"&&validacion!="0"){//Le cambie el &&
                                                        cout << "\n \t \t Ya existe un usuario con esta identificación o no hay ningun usuario registrado con el ID "<<cedula<<"\n";
                                                        cout<<"\t \t Por favor, digite una identificación válida: ";
                                                             getline(cin,cedula);
                                                             validacion=listaRepartidor->consultarDatoEspecificoRepartidor(cedula);
                                                        }

                                                //Datos de suscripcion
                                                cout<<"\t \t Digite el nombre de usuario: ";
                                                getline(cin,nombre);
                                                cout<<"\t \t Digite su correo: ";
                                                getline(cin,correo);
                                                cout<<"\t \t Digite el número de celular: ";
                                                cin.get();
                                                cin>>celular;
                                                cout<<"\t \t Digite la direccion exacta: ";
                                                cin.get();
                                                getline(cin,direccion);
                                                cout<<"\t \t Digite numero de tarjeta: ";
                                                getline(cin,Ntarjeta);
                                                cout<<"\t \t Estado del usuario: Activo";
                                                estado=true;
                                                cliente= new Cliente(estado,nombre,cedula,correo,celular,direccion,Ntarjeta);

                                                    ///metodos de archivos para cliente
                                                salida.open("Cliente.txt", ios::app);                                                                   //ios::app-> introducir al final de cada linea y no sobreescribibir datos
                                                cliente->autoGuardar(salida);
                                                salida.close();
                                                delete cliente;
                                                cout<<"\n \t \t ---------Gracias por registrarse en nuestra app!---------\n";
                                                system("pause");



                                                 //<<<<<<<<<<<<Cargar archvios clientes<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                                    cliente = NULL;
                                                    entrada.open("Cliente.txt");
                                                    while (entrada.good()){
                                                    cliente = Cliente::autoLeer(entrada);
                                                    if(entrada.good()&&cliente != NULL){
                                                            listaClientes->AgregarCliente(cliente);
                                                            }
                                                        };
                                                    entrada.close();

                                                    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

                                                    break;

                                                    }else{ //->x=2
                                                        cout<<" volviendo al menú..."<<endl;
                                                        goto INTENTO;
                                                        break;}
                                                }else{
                                                    cout<<"\n \t \t ---------Hola, Bienvenido de nuevo a CletaEats! ---------\n";
                                                    cout<< "\n \t  Sus datos actuales son: \n";
                                                    cout << validacion << "\n";
                                                    system("pause");

                                                  }//fin del else si (validacion ! de 2)

                                            }// fin del else (X->2)




				                        break;
                                    }//Fin del main subcase 1

                                    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

				                    case 2:{
				                        /*se reutiliza parte del codigo de modificar estado del usuario */

                                        if(listaClientes->IsEmpty()){
                                            cout <<" \n \t \t -----------No hay usuarios en el registro-----------\n \n \t \t";
                                            system("pause");

                                        }else{
                                            cout<<"\t \t ----------Cancelar suscripción----------\n";
                                            cout << "\t \t Digite la identificacón del usuario para cambiar su estado: ";
                                            getline(cin,cedula);

                                            ///metodos de archivos
                                            ofstream prueba;                                                                       //auxiliar
                                            entrada.open("Cliente.txt");                                                            // abro el archivo para leer
                                            prueba.open("ClienteTemporal.txt");                                                     // abro el archivo para escribir
                                            cliente = NULL;
                                            while (entrada.good()){
                                                    cliente =Cliente::autoLeer(entrada);                                            // leo el archivo hasta completar un objeto cliente y lo guardo en nuevo_dato

                                                    if (cliente != NULL&&cliente->getCedula()!=cedula) {                              // si la identificacion es diferente entonces
                                                        cliente->autoGuardar(prueba);                                               //guardo los demas objetos en el archivo de prueba
                                                    }
                                                    if (cliente != NULL&&cliente->getCedula()==cedula){
                                                                                                                                     //se tiene que crear una variable
                                                            if(cliente->getEstado()==true){//instead true -> cedula
                                                            estado=false;                                                         //declaro estado en false
                                                            cliente->setEstado(estado);
                                                            cliente->autoGuardar(prueba);
                                                                        }else{
                                                            estado=true;
                                                            cliente->setEstado(estado);                                           //seteo el estado
                                                            cliente->autoGuardar(prueba);                                          //se envia para guardarlo en el archivo
                                                        }
                                                    }
                                            }

                                            entrada.close();                                                                    // cierro los archivos
                                            prueba.close();
                                            remove("Cliente.txt");                                                              // borro el archivo
                                            rename("ClienteTemporal.txt", "Cliente.txt");                                         //renonbro Cliente temporal por cliente
                                            cout<<"\n \t \t ---------El estado ha sido modificados! ---------\n";
                                            system("pause");
                                            }                                                                            //fin del else-> osea si encontró a alguien con el ID


                                                 //<<<<<<<<<<<<Cargar archvios clientes<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                                cliente = NULL;
                                                entrada.open("Cliente.txt");
                                                while (entrada.good()){
                                                cliente = Cliente::autoLeer(entrada);
                                                if(entrada.good()&&cliente != NULL){
                                                        listaClientes->AgregarCliente(cliente);
                                                        }
                                                    };
                                                entrada.close();

                                                //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                                     break;
				                    }// fin del subcase 2

                                    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

                                    case 3:{
                                        system("cls");

                                        if(listaClientes->IsEmpty()==true){

                                           cout <<" \n \t \t -----------EL registro se encuentra vacío-----------\n \n \t \t";
                                           system("pause");

                                            }else{

                                                cout<<"\n \t \t Usuarios activos en la aplicación:"<<endl;
                                                cout<<listaClientes->ListarClientes()<<endl;//Aqui pasa algo
                                                system("pause");
                                                }
                                            break;
                                        }//subcase 3(LISTAR CLIENTE ACTIVOS)

                                    case 4:{
                                         system("cls");

                                        if(listaClientes->IsEmpty()==true){

                                           cout <<" \n \t \t -----------EL registro se encuentra vacío-----------\n \n \t \t";
                                           system("pause");

                                            }else{

                                                cout<<"\n \t \t Usuarios Inactivos en la aplicación:"<<endl;
                                                cout<<listaClientes->ListarClientesINACTIVOS()<<endl;//Aqui pasa algo
                                                system("pause");
                                                }
                                            break;



				                        break;
                                    }//submain case 4
                                    case 5:{
				                        break;
                                    }
                                    case 6:{
                                        cout<<"Regresando al menu principal..."<<endl;
                                        system("pause");
                                        goto INTENTO;

                                    break;
                                    }
				                }

                         }catch(string op){ //fin del catch
									system("cls");
									cout<<"Error, digite una opción correcta\n";
									system("pause");
                         }
							}while(true); //fin del do
							break;
                } //fin del case 2
			///--------------------------------------------------------------------------------------------------------------------------------//
			case 3:{
				system("cls");
				string op;
				do{
                        try{
                            system("cls");
                            cout<<"Digite la opcion que desea\n"
                                <<"1. Registrar restaurante\n"
			                	<<"2. Listar restaurantes\n"
			                	<<"3. Mostrar restaurante con mayor numero de pedidos\n"
			                	<<"4. Mostrar restaurante con menor numero de pedidos\n"
			                	<<"5. Monto vendido por restaurante\n"
			                	<<"6. Monto vendido por todos los restaurantes\n"
				                <<"7. Salir\n";
				                getline(cin,op); //No CIN para string
				                if(op!="1"&&op!="2"&&op!="3"&&op!="4"&&op!="5"&&op!="6"&&op!="7"){
				                throw op;}
				                switch(stoi(op)){
				                    case 1:{
				                        break;
				                    }
				                    case 2:{
				                        break;
                                    }
                                    case 3:{
				                        break;
                                    }
                                    case 4:{
				                        break;
                                    }
                                     case 5:{
				                        break;
                                    }
                                     case 6:{
				                        break;
                                    }
                                     case 7:{
				                        break;
                                    }
				                } //fin del switch
                        }catch(string op){ //fin del catch
									system("cls");
									cout<<"Error, digite una opción correcta\n";
									system("pause");
								}
							}while(true); //fin del do
							break;
                } //fin del case 3
        ///--------------------------------------------------------------------------------------------------------------------------------//
                case 4:{
				system("cls");
				string op;
				do{
                        try{
                            system("cls");
                            cout<<" \n \tMenu de pedidos\n"
                                <<" \t \t1. Hacer pedido\n"
			                	<<" \t \t2. Listar pedido por cliente\n"
			                	<<" \t \t3. Hora con mas pedidos\n"
				                <<" \t \t4. Salir\n";
				                cout<<"\tDigite Opcion: ";
				                getline(cin,op); //No CIN para string
				                if(op!="1"&&op!="2"&&op!="3"&&op!="4"){
				                throw op;}
				                switch(stoi(op)){
				                     //--------------------------------------------------------------------------------------------------------------------------//
				                    case 1:{

				                        cout<<"\t \t ----------Para hacer un pedido debe estar inscrita(o)----------\n";
                                            cout << "\t \t Digite su cedula: ";
                                            string cedulaC;
                                            getline(cin,cedulaC);
                                            if(listaClientes->IsEmpty()){
                                                cout <<" \n \t \t -----------No hay datos en el registro-----------\n ";
                                                cout<<"\n \t \t Inscribase en la seccion de clientes para poder pedir\n \n \t \t";
                                                system("pause");
                                                goto Clientes;
                                            }
                                            else{
                                                    validacion=listaClientes->consultarDatoEspecificoCliente(cedulaC);
                                                if(validacion=="2"){
                                                    cout << "\n \t \t No hay un cliente con dicha cedula en el registro \n ";
                                                    cout<<"\n \t \t Inscribase en la seccion de clientes para poder pedir\n \n \t \t";
                                                    system("pause");
                                                    goto Clientes;
                                                    }
                                                else{
                                                    clienteP= listaClientes->consultarNombredelCliente(cedulaC);
                                                    srand(time(NULL));

                                                    IdPedido = "A"+aleatoreo();
                                                    validacion=listaPedido->consultarDatoEspecificoPedido(IdPedido);
                                                    while(validacion!="2"&&validacion!="0"){
                                                        IdPedido = "A"+aleatoreo();
                                                        validacion=listaPedido->consultarDatoEspecificoPedido(IdPedido);
                                                    }
                                                    cout<<listaRestaurante->ListarMenuRestaurante();
                                                    string identificador, horap;
                                                    int vali=3;
                                                    char minp[5];
                                                    cout<<"\n \tDigite el identificador del restaurante que desea: ";
                                                    getline(cin,identificador);
                                                    validacion=listaRestaurante->consultarDatoEspecificoRestaurante(identificador);
                                                            if(validacion=="2"){
                                                            cout << "\n \t \t No hay un restaurante con dicho identificador en el registro \n ";
                                                            }
                                                            else{
                                                                restauranteP = identificador;
                                                                cout<<"\n \tDigite la hora del pedido:  ";
                                                                cin>>horap;
                                                                while(horap!="1"&&horap!="2"&&horap!="3"&&horap!="4"&&horap!="5"&&horap!="6"&&horap!="7"&&horap!="8"&&horap!="9"&&horap!="10"&&horap!="11"&&horap!="12"){
                                                                    cout<<"\n \tOpcion no valida \n \tSistema horario de 12 horas"
                                                                        <<"\n \tDigite la hora del pedido:  ";
                                                                    cin>>horap;
                                                                } horaPedido=stoi(horap);

                                                                cout<<"\n \tDigite los minutos:  ";
                                                                cin>>minp;
                                                                vali = ValidacionNum(minp);
                                                                while(vali!=0||(vali==0&&(stoi(minp)>59||stoi(minp)<0))){
                                                                    cout<<"\n \tOpcion no valida ";
                                                                    cout<<"\n \tDigite los minutos:  ";
                                                                    cin>>minp;
                                                                    vali = ValidacionNum(minp);
                                                                } minPedido=stoi(minp);

                                                                string opM=" " , combo=" ";
                                                                system("cls");

                                                                do{
                                                                    system("cls");
                                                                    try{
                                                                        cout<<"\n Hora del pedido  "<<horaPedido<<" : "<<minPedido<<endl;
                                                                        Pedido *p1=new Pedido();
                                                                        cout<<p1->Lista_Precios();
                                                                        cout<<"\n \tDesea agrega un combo al pedido\n"
                                                                            <<"\t \t1. Si \n"
                                                                            <<"\t \t2. No\n"
                                                                            <<"\tDigite Opcion: ";
                                                                        getline(cin,opM);

                                                                        if(opM!="1"&&opM!="2"){
                                                                            throw opM;
                                                                        }

                                                                        if(opM=="1"){
                                                                            cout<<"\n \tDigite el numero del combo que desea: ";
                                                                            getline(cin, combo);

                                                                            while(combo!="1"&&combo!="2"&&combo!="3"&&combo!="4"&&combo!="5"&&combo!="6"&&combo!="7"&&combo!="8"&&combo!="9"){
                                                                                cout<<"\n \t Opcion no valida"
                                                                                    <<"\n \tDigite el numero del combo que desea: ";
                                                                                getline(cin, combo);
                                                                            }
                                                                            costoTotalPedido+=p1->generarCostoDelPedido(stoi(combo)-1);
                                                                            cout<<costoTotalPedido<<endl;
                                                                            system("pause");
                                                                        }else{
                                                                            if(opM=="2"){
                                                                                break;
                                                                            }else{
                                                                                throw opM;
                                                                            }
                                                                        }

                                                                    }catch(string opM){
                                                                        system("cls");
                                                                        cout<<"Error, digite una opción correcta\n";
                                                                       // system("pause");
                                                                    }
                                                                }while(true); // cierre del generar costo



                                                                if(listaRepartidor->IsEmpty()){
                                                                    cout<<"\n \t No hay repartidores en el registro\n \t Intente el pedido en otro momento \n \n \t ";
                                                                    system("pause");
                                                                    break;
                                                                }else{
                                                                    validacion= listaRepartidor->EleccionRepartidor();
                                                                    if (validacion=="2"){
                                                                        cout<<"\n \t No hay repartidores disponibles\n \t Intente el pedido en otro momento \n \n \t ";
                                                                        system("pause");
                                                                        break;
                                                                    }
                                                                    else{
                                                                        repartidorP=validacion;
                                                                        horaEntrega=horaPedido+1;
                                                                        minEntrega=minPedido+40;
                                                                        while(minEntrega>59){
                                                                            minEntrega-=60;
                                                                            horaEntrega++;
                                                                        }
                                                                        if(horaEntrega>12){
                                                                            horaEntrega-=12;
                                                                        }
                                                                    }
                                                                } // cierre de la validacion del repartidor
                                                                system("cls");
                                                                string opqueja;
                                                                int amonestacionesRep=0;
                                                                cout<<"\n \tDesea agrega una queja asociada al repartidor\n"
                                                                            <<"\t \t1. Si \n"
                                                                            <<"\t \t2. No\n"
                                                                            <<"\tDigite Opcion: ";
                                                                            cin>>opqueja;
                                                                while(opqueja!="1"&&opqueja!="2"){
                                                                                cout<<"\n \t Opcion no valida";
                                                                                cout<<"\n \tDesea agregar una queja asociada al repartidor\n"
                                                                                    <<"\t \t1. Si \n"
                                                                                    <<"\t \t2. No\n"
                                                                                    <<"\tDigite Opcion: ";
                                                                                cin>>opqueja;
                                                                }
                                                                if (opqueja=="1"){

                                                                    amonestacionesRep=1;
                                                                    queja=true;
                                                                    string seleccion, xyz;
                                                                    cout<<"\n \t Seleccione cual es la opcion que se apega mas a su situacion: \n"
                                                                        <<"\t \t1. Llega tarde, por ende la comida esta fria \n"
                                                                        <<"\t \t2. Es grosero(a)\n"
                                                                        <<"\t \t3. Se encuentra mal vestido \n"
                                                                        <<"\t \t4. No llego \n"
                                                                        <<"\tDigite Opcion: ";
                                                                         cin>>seleccion;
                                                                         while(seleccion!="1"&&seleccion!="2"&&seleccion!="3"&&seleccion!="4"){
                                                                                cout<<"\n \t Seleccione cual es la opcion que se apega mas a su situacion: \n"
                                                                                    <<"\t \t1. Llega tarde, por ende la comida esta fria \n"
                                                                                    <<"\t \t2. Es grosero(a)\n"
                                                                                    <<"\t \t3. Se encuentra mal vestido \n"
                                                                                    <<"\t \t4. No llego \n"
                                                                                    <<"\tDigite Opcion: ";
                                                                                cin>>seleccion;
                                                                        }
                                                                         if(seleccion=="1"){
                                                                            xyz = "Llega tarde, por ende la comida esta fria";
                                                                         }
                                                                         if(seleccion=="2"){
                                                                            xyz = "Es grosero(a)";
                                                                         }
                                                                         if(seleccion=="3"){
                                                                            xyz = "Se encuentra mal vestido";
                                                                         }
                                                                         if(seleccion=="4"){
                                                                            xyz="No llego";
                                                                         }
                                                                        repartidorQueja= new Repartidor(repartidorP, xyz);

                                                                         ///metodos de archivos
                                                                        salida.open("Quejas.txt", ios::app);
                                                                        repartidorQueja->autoGuardarQueja(salida);
                                                                        salida.close();
                                                                        delete repartidorQueja;
                                                                        ///

                                                                }else{
                                                                    queja=false;
                                                                    amonestacionesRep=0;
                                                                }// cierre de queja


                                                                //^^^^^^^^^^^^^^^^^^^^^^^^ // suma las amonestaciones
                                                                        ///metodos de archivos
                                                                        float cos, kilom, dis;
                                                                        ofstream prueba;
                                                                        entrada.open("Repartidores.txt"); // abro el archivo para leer
                                                                        prueba.open("RepartidoresTemporal.txt"); // abro el archivo para escribir
                                                                        repartidor = NULL;
                                                                        while (entrada.good()){
                                                                                repartidor = Repartidor::autoLeer(entrada); // leo el archivo hasta completar un objeto cliente y lo guardo en nuevo_dato
                                                                                if (repartidor != NULL&&repartidor->getCedula()!=repartidorP) { // si la identificacion es diferente entonces
                                                                                    repartidor->autoGuardar(prueba); //guardo los demas objetos en el archivo de prueba
                                                                                }
                                                                                if (repartidor != NULL&&repartidor->getCedula()==repartidorP){
                                                                                        if(repartidor->getEstado()==true){
                                                                                            estado=false;
                                                                                            repartidor->setEstado(estado);
                                                                                        } else{
                                                                                            estado=true;
                                                                                            repartidor->setEstado(estado);

                                                                                        }

                                                                                        cout<<"\n \tDigite la distancia del pedido: ";
                                                                                        cin>>distanciaP;
                                                                                        KM = repartidor->getKM();
                                                                                        KM+=distanciaP;
                                                                                        repartidor->setKM(KM);
                                                                                        amonestacionesRep+= repartidor->getAmonestaciones();
                                                                                        cos = 1000*KM;
                                                                                        repartidor->setCosto(cos);
                                                                                        repartidor->setAmonestaciones(amonestacionesRep);
                                                                                        repartidor->autoGuardar(prueba);
                                                                                }
                                                                        }
                                                                        entrada.close(); // cierro los archivos
                                                                        prueba.close();
                                                                        remove("Repartidores.txt"); // borro el archivo contactos
                                                                        rename("RepartidoresTemporal.txt", "Repartidores.txt"); //renonbro el temporal
                                                                        ///
                                                                        //^^^^^^^^^^^^^^^^^^^^^^^^

                                                                pedido= new Pedido(IdPedido,  clienteP,  repartidorP,  restauranteP,  horaPedido,  minPedido,  horaEntrega,  minEntrega,  costoTotalPedido, queja, distanciaP);
                                                                ///metodos de archivos
                                                                salida.open("Pedidos.txt", ios::app);
                                                                pedido->autoGuardar(salida);
                                                                salida.close();
                                                                cout<<endl<<pedido->toStringFactura();
                                                                delete pedido;
                                                                ///


                                                            }// cierre de la validacion del restaurante
                                                            }
                                                }// cierre de la validacion del cliente

                                        system("pause");

				                        break;
				                    }
				                     //--------------------------------------------------------------------------------------------------------------------------//
				                    case 2:{// listar pedido por cliente
				                        if(listaPedido->IsEmpty()==true){
                                           cout <<" \n \t \t -----------No hay datos en el registro-----------\n \n \t \t";

                                       }else{
                                            cout<<"\n Los datos referentes a los pedidos son: \n";
                                            cout << listaPedido->ListarPedidos()<<endl;
                                        }

                                        system("pause");
				                        break;
                                    }
                                     //--------------------------------------------------------------------------------------------------------------------------//
                                    case 3:{
				                        break;
                                    }
                                     //--------------------------------------------------------------------------------------------------------------------------//
                                    case 4:{
                                        goto INTENTO;
				                        break;
                                    }

				                } //fin del switch
                        }catch(string op){ //fin del catch
									system("cls");
									cout<<"Error, digite una opción correcta\n";
									system("pause");
								}
							}while(true); //fin del do
							break;
                } //fin del case 4
                ///---------------------------------------------------SALIR----------------------------------------------------------------------//
                case 5:{
							string option="";
							system("cls");

							do{
								system("cls");
								try{
									cout<<"Esta Seguro Que quiere salir\n"
										<<"1. Si \n"
										<<"2. No\n";
									getline(cin,option);

									if(option!="1"&&option!="2"){
										throw option;
									}

									if(option=="1"){
										cout<<"Saliendo........ ";
										system("pause");
										exit(0);
									}else{
										if(option=="2"){
											break;
										}else{
											throw option;
										}

									}

								}catch(string option){
									system("cls");
									cout<<"Error, digite una opción correcta\n";
									system("pause");
								}
							}while(true);
							break;
						}// fin del case 5



    }//fin del switch principal
        }//fin del try
        catch(string opcMenu){
			system("cls");
			cout<<"Error, Opción no válida\n";
			system("pause");
		    }//fin del catch principal

} while(true); //fin del do principal





} //fin de menu



















