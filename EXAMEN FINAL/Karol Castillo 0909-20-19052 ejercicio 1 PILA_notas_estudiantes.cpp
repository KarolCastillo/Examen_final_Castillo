/*
* PROGRAMACION I EXAMEN FINAL
* KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052
* PROGRAMA NO.1 PILA, ARRAY QUE ALMACENE LAS NOTAS DE UN ESTUDIANTE
*/

#include <iostream>
using namespace std;

struct nodo {
    int nro;
    struct nodo* sgte;
};

typedef nodo* ptrPila;   // creando nodo tipo puntero( tipo de dato )

/*                        FUNCION PUSH, AGRGAR NOTAS
------------------------------------------------------------------------*/
void push(ptrPila& p, int valor)
{
    ptrPila aux;
    aux = new(struct nodo);  // ALMACENAMOS LA NOTA
    aux->nro = valor;

    aux->sgte = p;
    p = aux;
}

/*                FUINCION POP, ELIMINAMOS LA ULTIMA NOTA INGRESADA
------------------------------------------------------------------------*/
int pop(ptrPila& p)
{
    int num;
    ptrPila aux;

    aux = p;
    num = aux->nro;   // ASIGNAMOS EL PRIMER VALOR DE LA PILA

    p = aux->sgte;
    delete(aux);

    return num;
}

/*  FUNCION IMPRIMIR DATOS O IMOPRIMIR EL ARRAY EN PANTALLA (VER TODAS LAS NOTAS)
------------------------------------------------------------------------*/
void mostrar_pila(ptrPila p)
{
    ptrPila aux;
    aux = p;     // APUNTA AL INICIO DE LA LISTA

    while (aux != NULL)
    {
        cout << "\t" << aux->nro << endl;
        aux = aux->sgte;
    }
}

/*  FUNCION ELIMINAR PILA, ELIMINA TODAS LAS NOTAS INGRESADAS DE LOS ESTUDIANTRES
-------------------------------------------------------------------------------------*/
void destruir_pila(ptrPila& p)
{
    ptrPila aux;

    while (p != NULL)
    {
        aux = p;
        p = aux->sgte;
        delete(aux);




    }



}

/*                       FUNCION MENU DE OPCIONES
* 
* EN LUGAR DE ESTABLECER LAS DIMENCIONES DE UNA VEZ EJ. DEFINIR QUE LA PILA SERA DE 12 NOTAS Y SOLO 12 NOTAS ME DEJE INGRESAR 
* DECIDI DEJARLO LIBRE, DE MANERA QUE NO DEFINA UNA CANTIDAD E INGRESE LAS NOTAS QUE QUIERA, INGRESANDO NUEVAMENTE A LA OPCION 1 Y ASI
* APLICAR LA FUNCION PUSH, COMO PLUS AGREGUE UNA FUNCION NO MENCIONADA EN LAS INSTRUCCIONES, LA CUAL ES ELIMINAR TODA LA PILA (TODAS LAS NOTAS)
* CON LA FINALIDAD DE QUE SI EL USUARIO QUIERE INICIAR NUEVAMENTYED LA PILA SIN TENER QUE ELIMINAR O APLICAR LA FUNCION POP QUE SERIA UNA NOTA POR UNA
* EJ. SI TENGO 12 NOTAS Y QUIERO INICIAR, TENDRE QUE APLICAR 12 VECES LA FUNCION POP, MIENTRAS QUE SI TENGO UNA FUNCION DE ELIMINAR LA PILA SOLO
* APLICO UNA VEZ LA FUNCION ELIMINAR PILA (ES MUCHO MAS FACTIBLE Y RAPIDO)
------------------------------------------------------------------------*/
void menu()

{
    cout << "\n\t  KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052\n\n";

    cout << "\n\t            INGRESO NOTAS DE ESTUDIANTES (PILA)\n\n";
    cout << "      1. ESTABLECER DIMENSION DE ARRAY         (FUNCION PUSH)           " << endl;
    cout << "      2. ELIMINAR ULTIMA NOTA INGRESADA        (FUNCION POP)            " << endl;
    cout << "      3. MOSTRAR TODAS LAS NOTAS               (VISUALIZAR PILA )       " << endl;
    cout << "      4. BORRAR TODAS LAS NOTAS DE ESTUDIANTES (ELIMINAR PILA)          " << endl;
    cout << "      5. FINALIZAR                                                      " << endl;

    cout << "\n INGRESE OPCION: ";
}

/*                        FUNCION PRINCIPAL
------------------------------------------------------------------------*/
int main()



{
    ptrPila p = NULL;  // CREAMOS PILA
    int dato;
    int op;
    int x; // NUMERO QUE DEVUELVE LA FUNCION POP

    system("color 74"); //LE DAMOS COLOR DE FONDO Y FUENTE A NUESTRO PROGRAMA

    // INICIAMOS UNA ESTRUCTURA DO WHILE, PARA CREAR UN BUCLE
    do
    {
        //LLAMAMOS NUSTRA FUNCION MENU 
        menu();  
        // OP ES LA VARIABLE DONDE SE ALAMACENA LA OPCION INGRESADA POR EL USUARIO 
        cin >> op;

        //CREAMOS UNA ESTRUCTRUCTURA SWITCH, DONDE TENEMOS TODAS LAS OPCIONES DEL MENU.

        //SEGUN OP QUE ES LA VARIABLE CON LA OPCION DEL USUARIO, REALIZARA ALGUNA DE ESTAS OPCIONES QUE SON LOS CASE
        switch (op)
        {
            // SI LA OPCION ES 1 HACE ESTO
        case 1:
            
            //IMPRIMIMOS UN MENSAJE DONDE PEDIMOS LA NOTA Y LA ALMACENAMOS EN LA VARIABLE DATO
            cout << "\n INGRESE NOTA DEL ESTUDIANTE: "; cin >> dato;

            //MANDAMOS A LLAMAR LA FUNCION PUSH
            push(p, dato);

            // LUEGO DE HABERCE APLICADO LA FUNCION, IMPRIMIMOS UN MENSAJE EN PANTALLA QUE DICE LA NOTA FUE REGISTRADA
            cout << "\n\n\t\tNOTA " << dato << " REGISTRADA CON EXITO...\n\n";
            cout << "\n\n\t\t DESEA INGRESAR OTRA NOTA VUELVA A OPCION 1...\n\n";

            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;


            // SI LA OPCION ES 2 HACE ESTO
        case 2:

            //MANDAMOS A LLAMAR LA FUNCION POP
            x = pop(p);

            // LUEGO DE HABER APLICADO LA FUNCION, IMPRIMIMOS UN MENSAJE EN PANTALLA QUE DICE LA NOTA FUE ELIMINADA 
            cout << "\n\n\t\tNOTA " << x << " ELIMINADA CON EXITO...\n\n";

            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;


            // SI LA OPCION ES 3 HACE ESTO
        case 3:

            //IMPRIMIMOS TITULO DE LA OPCION 3 O CESE 3
            cout << "\n\n MOSTRANDO NOTAS DE LOS ESTUDIANTES (MOSTRAR PILA) \n\n";
            
            
            /*UTILIZAMOS UNA EXPRECION CONDICIONAL QUE EN RESUMEN DECIMOS QUE SI HAY NOTAS REGISTRADAS (DATOS EN LA PILA) LOS IMPRIME EN LA PANTALLA 
            * DE LO CONTARIO MANDA UN MENSAJE DE AVISO */

            if (p != NULL)

                //LLAMAMOS LA FUNCION PARA VISUALIZAR LA PILA
                mostrar_pila(p);
            else

                // SI NO HAY NOTAS EN LA PILA NOS TIRA UN MENSJAE DE AVISO
                cout << "\n\n\tPILA VACIA... SIN NOTAS INGRESADAS..!" << endl;

            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;


            // SI LA OPCION ES 4 HACE ESTO
        case 4:

            //LLAMAMOS LA FUNCION DESTRUIR O ELIMINAR LA PILA (TODAS LAS NOTAS INGRESADAS)
            destruir_pila(p);

            //IMPRIMIMOS MENSAJE EN PANTALLA
            cout << "\n\n\t\tPILA ELIMINADA CON EXITO..!\n\n";

            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;

        }

        cout << endl << endl;
        system("pause");// HACEMOS UNA PAUSA EN EL PROGRAMA
        system("cls"); //LIMPIAMOS PANTALLA

        // SI LA OPCION ES 5 FINALIZA EL CICLO DO WHILE, OSEA QUE SALIMOS DEL RPOGRAMA
    } while (op != 5); 

   
    
    // AANDONAMOS LA FUNCION MAIN, OSEA TERMINAMOS EL PROGRAMA EN EJECUCION 
    return 0;
    
}
/*
* PROGRAMACION I EXAMEN FINAL
* KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052
* PROGRAMA NO.1 PILA, ARRAY QUE ALMACENE LAS NOTAS DE UN ESTUDIANTE
*/