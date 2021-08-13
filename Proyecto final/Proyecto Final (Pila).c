/* 
				PROYECTO FINAL: IMPLEMENTACIÓN BÁSICA DE UNA PILA
				   ESTRUCTURA DE DATOS Y ALGORITMOS I 
				                          -- Por: Elisa Daniela Rios Herrera --
				
				FI, UNAM.

*/



#include <stdio.h>   
#include <stdlib.h>  // Esta librería nos permite el uso de free y malloc
#include <stdbool.h> // Esta librería nos permite el uso de booleanos


struct nodo // con struct estamos definiendo a una estructura, en este caso el nodo
{
  int n;
  struct nodo *sig;
};

// Llamamos a las funciones con void
void agregar(int n);  // se aplica la función push para agregar
void eliminar(void); // se aplica la función pop para eliminar
void imprimir(void);
int size(void); // para indicar el tamaño de la pila 
// bool es una variable que solo puede resultar verdadera o falsa
bool vacia(void);  // para indicar si la pila se encuentra vacia
int ultimo(void);  // para mostrar el último elemento agregado; si no hay elementos devuelve 0

struct nodo *sup = NULL; // aplicamos punteros
// NULL hace referencia a un dato válido

int main()
{
  int eleccion;
  int n;
  while (eleccion != 9)
  {
    printf("\n***SISTEMA DE ELEMENTOS EN UNA PILA***\n\nOPCIONES\n\n1.- Agregar elemento\n2.- Eliminar elemento\n3.- Imprimir "
           "la pila\n4.- Imprimir cuanto mide la pila\n5.- Consultar si la pila esta vacia\n6.- "
           "Mostrar el ultimo elemento agregado\n\nPresione 9 si desea salir\n\n\tPor favor elija una opcion: ");
    scanf("%d", &eleccion);
    switch (eleccion)
	{
    case 1:
      printf("Ingrese el numero a agregar: \n"); // el caso 1 llama a la funcion agregar
      scanf("%d", &n);
      agregar(n);
      break;
    case 2: // el caso 2 llama a la funcion eliminar
      eliminar();
      break;
    case 3: // el caso 3 llama a la funcion imprimir
      imprimir();
      break;
    case 4: // el caso 4 llama a la funcion de tamaño 
      printf("La pila mide %d\n elementos", size());
      break;
    case 5: // el caso 5 llama a la funcion para comprobar si la pila está vacía o tiene elementos
      if (vacia())
	  {
        printf("La pila se encuentra vacia\n");
      }
	  else
	  {
        printf("La pila NO se encuentra vacia\n");
      }
      break;
    case 6: // el caso 6 llama a la funcion ultimo
      printf("El ultimo elemento es: %d\n", ultimo());
      break;
    }
  }
}

// FUNCIÓN: Para consultar el tamaño
int size(void)
{
  int contador = 0;
  if (sup == NULL)
    return contador;
  struct nodo *temp = sup;
  while (temp != NULL)
  {
    contador++;
    temp = temp->sig;
  }
  return contador;
}

// FUNCIÓN: Para consultar si la pila tiene o no elementos
bool vacia(void)
{
return sup == NULL;
}

int ultimo()
{
  if (sup == NULL)
    return -1;
  return sup->n;
}

// FUNCIÓN: Para agregar un elemento a la pila (función push)
void agregar(int n)
{
  printf("Se ha agregado correctamente el elemento: %d\n", n);
  struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
  nuevoNodo->n = n;
  nuevoNodo->sig = sup;
  sup = nuevoNodo;
}

// FUNCIÓN: Para imprimir los elementos de nuestra pila
void imprimir(void)
{
  printf("La pila se conforma por los siguientes elementos: \n");
  struct nodo *temp = sup;
  while (temp != NULL)
  {
    printf("%d\n", temp->n);
    temp = temp->sig;
  }
}

// FUNCIÓN: Para eliminar el ultimo elemento agregado (función pop)
void eliminar(void)
{
  printf("Se ha eliminado el ultimo elemento agregado\n");
  if (sup != NULL)
  {
    struct nodo *temp = sup;
    sup = sup->sig;
    free(temp); // se usa free para liberar memoria que se había asignado antes
  }
}
