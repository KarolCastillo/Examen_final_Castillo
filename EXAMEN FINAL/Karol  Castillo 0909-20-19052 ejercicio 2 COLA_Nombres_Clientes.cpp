/*
* PROGRAMACION I EXAMEN FINAL
* KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052
* PROGRAMA NO.2 COLA, ARRAY QUE ALMACENE LOS NOMBRES DE CLIENTES
*/


//DECLARACION LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//DEFINIMOS QUE EN N TENEMOS 50, QUE LO OCUPAREMOS CUANDO HAGAMOS UNA VARIABLE
#define N 100

typedef struct persona {
    //DECLKARAMOS VARIABLE NOMBRE N=50
    char nombre[N];
    
};

/*                DEFINIMOS UNA ESTRUCTURA DE LOS NODOS EN LA COLA
------------------------------------------------------------------------*/
typedef struct nodo {
    struct persona per;
    struct nodo* sgte;
};

/*                      DEFINIMOS ESTRUCTURA DE LA COLA
------------------------------------------------------------------------*/
typedef struct cola {
    struct nodo* delante;
    struct nodo* atras;
};

/*                       FUNCION DE ENCOLAR EL NOMBRE  ENQUEUE
------------------------------------------------------------------------*/
void encolar(struct cola* q, struct persona valor) 
{
    struct nodo* aux = new(struct nodo);

    aux->per = valor;
    aux ->sgte = NULL;

    if (q->delante == NULL)
        q->delante = aux;   // ENCOLA EL PRIMER NOMBRE
    else
        (q->atras)->sgte = aux;

    q->atras = aux;        // PUNTERO QUE SIEMPRE APUNTA AL ULTIMO ELEMNTO (NOMBRE)

}

/*                        FUNCION DESENCOLAR EL NOMBRE DEQUEUE
------------------------------------------------------------------------*/
struct persona desencolar(struct cola &q) {

    struct persona nom;
    struct nodo* aux;

    aux = q.delante; // aux APUNTA AL INICIO DE LA COLA
    nom = aux->per;
    q.delante = (q.delante)->sgte;

    free(aux); //LIBERA MEMORIA DONDE APUNTA aux

    return nom;
}

/*            FUNCION MOSTRAR COLA O VISUALIZAR TODOS LOS NOMBRES
------------------------------------------------------------------------*/
void muestraCola(struct cola q) {

    struct nodo* aux;

    aux = q.delante;

    while (aux != NULL) {
        printf("%s -> ", aux->per.nombre);
        aux = aux->sgte;
    }
    printf("Fin de la cola\n");
}

/*              ELIMINAR TODOS LOS NOMBRES DE LA COLA 
------------------------------------------------------------------------*/
void vaciaCola(struct cola* q) {

    struct nodo* aux;

    while (q->delante != NULL) {
        aux = q->delante;
        q->delante = aux->sgte;

        free(aux);
    }
    q->delante = NULL;
    q->atras = NULL;
}

/*                        FUNCION MENU DE OPCIONES 
*
* EN LUGAR DE ESTABLECER LAS DIMENCIONES DE UNA VEZ EJ. DEFINIR QUE LA COLA SEADE 12 NOMBRES DE CLIENTES Y SOLO 12 NOMBRES ME DEJE INGRESAR
* DECIDI DEJARLO LIBRE, DE MANERA QUE NO DEFINA UNA CANTIDAD E INGRESE LOS NOMBRES QUE QUIERA, INGRESANDO NUEVAMENTE A LA OPCION 1 Y ASI
* APLICAR LA FUNCION QUEUE, COMO PLUS AGREGUE UNA FUNCION NO MENCIONADA EN LAS INSTRUCCIONES, LA CUAL ES ELIMINAR TODA LA COLA (TODOS LOS NOMBRES)
* CON LA FINALIDAD DE QUE SI EL USUARIO QUIERE INICIAR NUEVAMENTYED LA COLA SIN TENER QUE ELIMINAR O APLICAR LA FUNCION ENQUEUE QUE SERIA 
* QUITAR UN NOMBRE A LA VEZ.
* EJ. SI TENGO 12 NOMBRES Y QUIERO INICIAR, TENDRE QUE APLICAR 12 VECES LA FUNCION ENQUEUE, MIENTRAS QUE SI TENGO UNA FUNCION DE ELIMINAR LA COLA SOLO
* APLICO UNA VEZ LA FUNCION ELIMINAR COLA (ES MUCHO MAS FACTIBLE Y RAPIDO)
------------------------------------------------------------------------*/
void menu() {

    cout << "\n\t  KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052\n\n";
    
    printf("\n\t INGRESO DE NOMBRES DE CLIENTES (COLA)\n\n");

    printf(" 1. ESTABLECER DIMENCION DE ARRAY            (FUNCION QUEUE) \n");
    printf(" 2. ELIMINAR PRIMER NOMBRE INGRESADO         (FUNCION ENQUEUE)\n");
    printf(" 3. MOSTRAR TODOS LOS NOMBRES                (VISUALIZAR COLA) \n");
    printf(" 4. BORRAR TODOS LOS NOMBRES DE LOS CLIENTES (ELIMINAR COLA)  \n");
    printf(" 5. FINALIZAR                    \n");
    printf("\n INGRESE OPCION: ");

}


/*                        FUNCION PRINCIPAL
------------------------------------------------------------------------*/
int main()
{

    struct cola q; //CREAMOS XCOLA
    q.delante = NULL;
    q.atras = NULL;
    struct persona dato;//NOMBRE A ENCOLAR
    struct persona x;//NOMBRE QUE DEVUELVE
    int op; //OPCION DE MENU
    system("color 74"); //LE DAMOS COLOR DE FONDO Y FUENTE A NUESTRO PROGRAMA

    // INICIAMOS UNA ESTRUCTURA DO WHILE, PARA CREAR UN BUCLE
    do
    {   
        //LLAMAMOS NUESTRA FUNCION DE MENU DE OPCIONES
        menu(); 
        cin >> op; //SE ALMACENA LA OPCION ELEGIDA POR EL USUARIO

        //SEGUN LA OPCION HACER TAL CASO
        switch (op)
        {

            // SI LA OPCION ES 1 HACE ESTO
        case 1:
            
            //IMPRIMIMOS UN MENSAJE DONDE PEDIMOS EL NOMBRE Y LO ALMACENAMOS EN LA VARIABLE NOMBRE
            printf("\nINGRESE UN NOMBRE A ENCOLAR: "); cin >> dato.nombre;

            //MANDAMOS A LLAMAR LA FUNCION QUEUE
            encolar(&q, dato);

            // LUEGO DE HABERCE APLICADO LA FUNCION, IMPRIMIMOS UN MENSAJE EN PANTALLA QUE DICE EL NOMBRE FUE REGISTRADO
            printf("\n\tNOMBRE %s REGISTRADO CON EXITO...", dato.nombre);
            printf("\n\tDESEA INGRESAR OTRO NOMBRE VUELVA A OPCION 1...\n");

            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;
           
            // SI LA OPCION ES 2 HACE ESTO
        case 2:
            //MANDAMOS A LLAMAR LA FUNCION ENQUEUE
            x = desencolar(q);

            // LUEGO DE HABER APLICADO LA FUNCION, IMPRIMIMOS UN MENSAJE EN PANTALLA QUE DICE EL NOMBRE FUE DESENCOLADO
            printf("\n\n\t\tNOMBRE %s DESENCOLADO CON EXITO...\n\n", x.nombre);


            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;

            // SI LA OPCION ES 3 HACE ESTO
        case 3:
            
            //LLAMAMOS LA FUNCION PARA VISUALIZAR LA COLA
            printf("\n\n MOSTRANDO COLA\n\n");
            if (q.delante != NULL) muestraCola(q);

            // SI NO HAY NOMBRES DE CLIENTES EN LA COLA NOS TIRA UN MENSJAE DE AVISO
            else  printf("\n\n\tCola vacia...SIN NOMBRES INGRESADOS..!\n");

            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;


            // SI LA OPCION ES 4 HACE ESTO
        case 4:
            //LLAMAMOS LA FUNCION DESTRUIR O ELIMINAR COLA (TODOS LOS NOMBRES INGRESADOS)
            vaciaCola(&q);
            printf("\n\n\t\tCOLA ELIMINADA CON EXITO..!\n\n");

            //INTERRUMPIMOS O DETENEMOS EL CASE
            break;



        } 
        cout << endl << endl;
        system("pause");// HACEMOS UNA PAUSA EN EL PROGRAMA
        system("cls"); //LIMPIAMOS PANTALLA

        // SI LA OPCION ES 5 FINALIZA EL CICLO DO WHILE, OSEA QUE SALIMOS DEL RPOGRAMA
    }while (op != 5);
    

    // AANDONAMOS LA FUNCION MAIN, OSEA TERMINAMOS EL PROGRAMA EN EJECUCION 
   return 0;
}
/*
* PROGRAMACION I EXAMEN FINAL
* KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052
* PROGRAMA NO.2 COLA, ARRAY QUE ALMACENE LOS NOMBRES DE CLIENTES
*/