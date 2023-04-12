#include<stdio.h>
#include<ctype.h>
#include<string.h>

#include "display.h"
#include "data.h"

//Funcion inicial en la que se introducen datos.
int p_init(struct Contacto *tabla, int *numero) { //tabla es un puntero al struct Contactos y *numero es dir. del entero que recibe la funcion.

  char cadena[256];
  char nombre[256];
  int edad;
  
  FILE *fichero_entrada;

  fichero_entrada = fopen("contacts.txt", "r");

  //Inicialmente la tabla de contactos esta a 0.
  *numero = 0;
  
  //Si el fichero esta vacio salimos de la funcion.
  if(fichero_entrada == NULL) {
    
    return 0;
  }

  //Leemos linea a linea el contenido del fichero.
  while((fgets(cadena, sizeof(cadena), fichero_entrada)) != NULL) {

    //Analizamos la linea (que esta en cadena), sscanf sabe que primero hay un array con nombre, despues un espacio y despues un entero.
    sscanf(cadena,"%s %d", nombre, &edad);

    //Asignamos al campo edad de la tabla la edad que nos da la linea del fichero. El valor leido por sscanf.
    tabla[*numero].edad = edad;

    //Para copiar el nombre tenemos que hacer strcpy. Asginamos al campo nombre de la tabla el nombre leido por sscanf.
    strcpy((tabla[*numero].nombre), nombre);

    //Aumentamos el contador que indica el numero de contactos que tiene la tabla.
    (*numero)++;
  }
  fclose(fichero_entrada);
  
  return 0;
}


//Funcion que añade un contacto a la agenda.
int p_add(struct Contacto *tabla, int *numero) {

  printf("\nAdd\n");
  
  int salida = 0;
  int edad_retornada; //Entero que devuelve la funcion read_integer.
  char palabra_apuntada[100]; //Variable a a la que apunta *palabra.
  
  read_string("Name", palabra_apuntada); //read_string no devuelve nada, pero el nombre se guarda en palabra_apuntada (ver strcpy en la definicion de la funcion).
  edad_retornada = read_integer("Age");
  
  printf("New contact\n");

  //Asignamos a los campos edad y nombre los datos del contacto introducido por el usuario.
  tabla[*numero].edad = edad_retornada;
  strcpy((tabla[*numero].nombre), palabra_apuntada);

  //Aumentamos el numero de contactos en la tabla.
  (*numero)++;

  return salida;
}

//Funcion que elimina a un contacto de la agenda.
int p_delete(struct Contacto *tabla, int *numero) {

  printf("\nDelete\n");
  
  int salida = 0;
  char palabra_apuntada[100];
  int res = -1;

  //Llamamos a read_string para que lea la cadena introducida por el usuario (el nombre de la lista de contactos que se desea eliminar).
  read_string("Name", palabra_apuntada);

  //Recorremos la tabla comparando los nombres de los contactos con el introducido por el usuario.
  for(int i = 0; i < (*numero); i++) {
    
    res = strcmp((tabla[i].nombre), palabra_apuntada);//strcmp devuelve 0 si los dos elementos son iguales.
    
    if(res == 0){

      //Recorremos otra vez la tabla pero ahora desplazando todos los contactos desde el que se quiere eliminar una posicion hacia atras en la tabla, de tal forma que la posicion en la que se encontraba el contacto a eliminar pasa a estar ocupada por el contacto que estaba despues de este.
      for(int k = (i+1); k < (*numero); k++){
	
	tabla[k-1] = tabla[k];
      }
    
      printf("\nDeleted contact\n");

      //Decrementamos el numero de contactos de la tabla.
      (*numero)--;

      break;
    }
  }

  if(res != 0) {

    printf("\nUnknown contact\n");
  }
  
  return salida;
}

//Funcion que saca por pantalla los datos almacenados en la tabla.
int p_list(struct Contacto *tabla, int numero) {

  printf("\nList\n");
  
  int salida = 0;
  int i;
  
  printf("\nContacts table:\n");

  //Recorremos la tabla de contactos.
  for(i = 0; i < numero; i++) {
    printf("%s:%d\n", tabla[i].nombre, tabla[i].edad ); //tabla[i].nombre -> Hace referencia al campo nombre de la posicion i de la tabla.
  }
  
  return salida;
}

//Funcion que actualiza el fichero de salida antes de terminar la ejecucion del programa.
void p_fin(struct Contacto *tabla, int numero) {
  
  FILE *fichero_salida;

  fichero_salida = fopen("contacts.txt", "w");

  //Recorremos los campos nombre y edad de la tabla de contactos.
  for(int i = 0; i < numero; i++) {
    //Copiamos los elementos de la tabla en el fichero de salida.
    fprintf(fichero_salida, "%s %d\n", tabla[i].nombre, tabla[i].edad);
  }
  
  fclose(fichero_salida);
}


//Otra forma de copiar los campos de la tabla en el fichero de salida (mas liosa).
/*
  fputs((tabla[i].nombre), fichero_salida);
  fputc(' ', fichero_salida);
  char edadComoCadena[256];
  sprintf(edadComoCadena, "%d", (tabla[i].edad)); //Combertimos edad a int para poder copiarlo en el fichero.
  fputs(edadComoCadena, fichero_salida);
  fputc('\n', fichero_salida);
*/
