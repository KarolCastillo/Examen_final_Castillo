/*
* PROGRAMACION I EXAMEN FINAL
* KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052
* PROGRAMA NO.3 ARBOL ABB, ALMACENE NUMEROS E IMPRIME ARBOL
*/

//DEFINIMOS LIBRERIAS
#include <iostream>
#include <stdlib.h>

using namespace std;

// ESTRUCTURA DEL ARBOL
typedef struct nodo {
    int nro;
    struct nodo* izq, * der;
}*ABB;

int numNodos = 0; // NUMERO DE NODOS DEL ARBOL ABB



//ESTRUCTURA DE LA COLA
struct nodoCola {
    ABB ptr;
    struct nodoCola* sgte;
};
struct cola {
    struct nodoCola* delante;
    struct nodoCola* atras;
};

//FUNCION PARA INICIALIZAR COLA
void inicializaCola(struct cola& q)
{
    q.delante = NULL;
    q.atras = NULL;
}

//FUNCION ENQUEUE
void encola(struct cola& q, ABB n)
{
    struct nodoCola* p;
    p = new(struct nodoCola);
    p->ptr = n;
    p->sgte = NULL;
    if (q.delante == NULL)
        q.delante = p;
    else
        (q.atras)->sgte = p;
    q.atras = p;
}
//  FUNCION DESENCOLAR EL NODO DEQUEUE
ABB desencola(struct cola& q)
{
    struct nodoCola* p;
    p = q.delante;
    ABB n = p->ptr;
    q.delante = (q.delante)->sgte;
    delete(p);
    return n;
}

//FUNCION CREAR NODO TIPO ENTERO
ABB crearNodo(int x)
{
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

//FUNCION PARA INSERTAR O CREAR NODO
void insertar(ABB& arbol, int x)
{
    if (arbol == NULL)
    {
        arbol = crearNodo(x);

        //MENSAJE DE ASVISO
        cout << "\n\t  Insertado..!" << endl << endl;
    }
    else if (x < arbol->nro)
        insertar(arbol->izq, x);
    else if (x > arbol->nro)
        insertar(arbol->der, x);
}

//FUNCIONES PARA RECORRER EL ARBOL

//FUNCION PRE ORDEN
void preOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        cout << arbol->nro << " ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

//FUNCION IN ORDEN O EN ORDEN
void enOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        enOrden(arbol->izq);
        cout << arbol->nro << " ";
        enOrden(arbol->der);
    }
}

//FUNCION POST ORDEN
void postOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        enOrden(arbol->izq);
        enOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}


//FUNCION VISUALIZAR EL ARBOL
void verArbol(ABB arbol, int n)
{
    //ESTRUCTURA CONDICIONAL SI ESTO... DE LO CONTRARIO ESTO.
    if (arbol == NULL)
        return;
    verArbol(arbol->der, n + 1);

    for (int i = 0; i < n; i++)
        cout << "   ";

    numNodos++;
    cout << arbol->nro << endl;

    verArbol(arbol->izq, n + 1);
}

//FUNCION BUSCAR NODO, SI LO ENCUENTRA NOS DICE QUE SE ENCONTRO OSEA QUE EXISTE Y SI NO EXISTE, NOS MANDA MENSAJE
bool busquedaRec(ABB arbol, int dato)
{
    int r = 0;   // EL 0 NOS INDICA QUE LO ENCONTRE

    if (arbol == NULL)
        return r;

    if (dato < arbol->nro)
        r = busquedaRec(arbol->izq, dato);

    else if (dato > arbol->nro)
        r = busquedaRec(arbol->der, dato);

    else
        r = 1;   // DE LO CONTRARIO SON IGUALES, LO ENCONTRE

    return r;
}

ABB unirABB(ABB izq, ABB der)
{
    if (izq == NULL) return der;
    if (der == NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

//FUNCION ELIMINAR UN NODO ELEGIDO POR EL USUARIO
void elimina(ABB& arbol, int x)
{
    if (arbol == NULL) return;

    if (x < arbol->nro)
        elimina(arbol->izq, x);
    else if (x > arbol->nro)
        elimina(arbol->der, x);

    else
    {
        ABB p = arbol;
        arbol = unirABB(arbol->izq, arbol->der);
        delete p;
    }
}

//FUNCION DEL MENU PRINCIPAL
void menu()
{
    system("cls"); //LIMPIAMOS PANTALLA
    //MENSAJES A MOSTRAR COMO OPCIONES
    cout << "\n\t  KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052\n\n";
    cout << "\n\t\t   ARBOL ABB  (---BUSQUEDA---)   \n\n";
    cout << "\t [1]  Insertar elemento                  \n";
    cout << "\t [2]  Mostrar arbol                      \n";
    cout << "\t [3]  buscar nodo especifico          \n";
    cout << "\t [4]  Recorrer el arbol (pre-orden, in-orden, pos-orden)  \n";
    cout << "\t [5]  Eliminar elemento                  \n";
    cout << "\t [6]  FINALIZAR                          \n";

    cout << "\n\t Ingrese opcion : ";
}

//FUNCION DEL MENU PARA RECORRER EL ARBOL
void menu2()
{
    system("cls");   // LIMPIAMOS PANTALLA
    cout << endl;
    cout << "\t [1] En Orden     \n";
    cout << "\t [2] Pre Orden    \n";
    cout << "\t [3] Post Orden   \n";
    cout << "\n\t     Opcion :  ";
}

//FUNCION PRINCIPAL
int main()
{
    system("color 74"); //LE DAMOS COLOR DE FONDO Y FUENTE A NUESTRO PROGRAMA
    ABB arbol = NULL;
    //DECLARACION DE VARIABLE X
    int x;

    //DECLARACION DE LAS VARIABLES DONDE ALMACENAREMOS LA OPCION ELEGIDA POR EL USUIARIO
    int op, op2;


    // INICIAMOS UNA ESTRUCTURA DO WHILE, PARA CREAR UN BUCLE
    do
    {
        //LLAMAMOS LA FUNCION MENU Y ALMACENAMOS LA OPCION DEL USUARIO EN LA VARIABLE OP
        menu();  cin >> op;
        cout << endl;

        //SEGUN LA OPCION DEL USUARIO SE REASALIZARA ALGUNO DE ESTOS CASE O ALGUNA DE ESTAS OPCIONES
        switch (op)
        {
        case 1:
            //MENSAJE A PANTALLA
            cout << " Ingrese valor : ";  cin >> x;
            //LLAMAMOS LA FUNCION
            insertar(arbol, x);
            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;

        case 2:
            //LLAMAMOS LA FDUNCION
            verArbol(arbol, 0);
            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;

        case 3:
              
            bool band;

            //MENSAJE A PANTALLA
            cout << " Valor a buscar: "; cin >> x;

            //LLAMAMOS LA FUNCION
            band = busquedaRec(arbol, x);

            //ESTRUCTURA CONDICIONAL SI ESTO... HACE ESTO... DE LO CONTRARIO... HACE ESTO.
            if (band == 1)
                cout << "\n\tEncontrado...";
            else
                cout << "\n\tNo encontrado...";
            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;

        case 4:
            //LLAMAMOS LA FUNCION DEL SEGUNDO MENU PARA RECORRER LOS NODOS
             menu2();  
             //EN OP2 SE ALMACENA LA OPCION DEL SEGUNDO MENU ELEGIDA POR EL USUSARIO 
             cin >> op2;
             //ESTRUCTURA CONDICIONAL SI ESTO... HACE ESTO... DE LO CONTRARIO... HACE ESTO.
              if (arbol != NULL)
              { 
                  //SEGUN LA OPCION DEL USUARIO HACER UNO DE LOS CASE O DE LAS OPCIONES
                switch (op2)
                {
                case 1:
                    enOrden(arbol); break;//LLAMAMOS FUNCION E INTERRUMPIMOS O DETENEMOS EL CASE
                case 2:
                    preOrden(arbol); break;//LLAMAMOS FUNCION E INTERRUMPIMOS O DETENEMOS EL CASE
                case 3:
                    postOrden(arbol); break;//LLAMAMOS FUNCION E INTERRUMPIMOS O DETENEMOS EL CASE
 
                }
                
              }
                else
                  //MENSAJE A PANTALLA
                cout << "\n\t Arbol vacio..!";
              //INTERRUMPIMOS O DETENEMOS EL CASE
              break;

        case 5:
            //MENSAJE A PANTALLA
            cout << " Valor a eliminar: "; cin >> x;
            //LLAMAMOS LA FUNCION PARA ELIMINAR
            elimina(arbol, x);
            //MENSAJE A PANTALLA DE REALIZADO
            cout << "\n\tEliminado..!";
            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;

    
        }

        cout << endl << endl;
        system("pause");// HACEMOS UNA PAUSA EN EL PROGRAMA
        system("cls"); //LIMPIAMOS PANTALLA

        // SI LA OPCION ES 6 SALIR DEL PROGRAMA
    } while (op != 6);
    return 0;// ABANDONAMOS LA FUNCION MAIN, OSEA TERMINAMOS EL PROGRAMA EN EJECUCION 
}
/*
* PROGRAMACION I EXAMEN FINAL
* KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052
* PROGRAMA NO.3 ARBOL ABB, ALMACENE NUMEROS E IMPRIME ARBOL
*/