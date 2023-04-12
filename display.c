#include<stdio.h>
#include<ctype.h>
#include<string.h>

#include "display.h"

//Funcion frame. Imprime por pantalla la caratula del proyecto agenda.
void frame(char caracter, int tam_linea) {
  //Primero imprime los 50 guiones.
  for(int i = 0; i < 1; i++) {
    for(int j = 0; j < tam_linea; j++) {

      //Imprime el caracter que recibe la funcion.
      printf("%c", caracter); 
    }
    
    printf("\n");//Salto de linea.

    //Llamada a la funcion title (que imprime el nombre 'AGENDA PROJECT').
    title("AGENDA PROJECT");	  
  }

  //Vuelve a imprimir los 50 guiones.
  for(int x = 0; x < 50; x++) {
    
    printf("%c", caracter);
  }

  printf("\n");
  
  return;
}

//Funcion title. Imprime el nombre del proyecto.
void title(char nombre[]) {

  printf("%s\n", nombre);

  return;
}

//Funcion verify. Verifica la respuesta del usuario ante la pregunta de si quiere salir del programa.
int verify(char invitacion[]) {

  char respuesta;
  int salida = -1;
  char linea[256], extra[256];
  int x;
  
  do {
    //Primero imprime por pantalla el mensaje.
    printf("%s? (y/n): ", invitacion);

    //Leemos la respuesta del usuario y comprobamos que esta solo tenga un caracter.
    fgets(linea, sizeof(linea), stdin);
    x = sscanf(linea, "%c%s", &respuesta ,extra);

    //Si la respuesta es de un solo caracter la analizamos.
    if(x == 1) {
      //Hacemos que no diferencie entre mayus y minus.
      respuesta = tolower(respuesta);
      
      if(respuesta == 'y') salida = 1;
      
      else if(respuesta == 'n') salida = 0;
    }
  }
  while(salida == -1);
 
  return salida;
}

//Funcion read_string. Lee la cadena introducida por el usuario.
void read_string(const char *mensaje, char *palabra) {
  
  char cadena[100];
  int longitud, x;

  char linea[256], extra[256];
  
  do {
    printf("\n%s (1-24 char): ", mensaje); //Imprime la cadena recibida por la función (El contenido del puntero *mensaje).

    //Nos aseguramos de que el usuario solo introduce una cadena.
    fgets(linea, sizeof(linea), stdin);
    x = sscanf(linea, "%s%s", cadena ,extra);

    if(x == 1) {
      
      //Almacenamos en logitud el numero de caracteres de la cadena introducida.
      longitud = strlen(cadena); //No cuenta los espacios.
      
    } else {
      
      longitud = -1;
    }
  }
  //Validamos la cadena.
  while ((longitud > 24) || (longitud < 1));
 
  strcpy(palabra, cadena); //Copiamos el valor de la cadena introducida por el usuario en palabra (Contenido de *palabra, que apunta a palabra_apuntada).
  //De esta forma podemos usar el valor palabra despues de volver de la funcion.
}

//Funcion read_integer. Lee un entero introducido por el usuario.
int read_integer(const char *mensaje) {
  
  int entero, x;
  char linea[256], extra[256];

  do{
    printf("\n%s [1-100]: \n", mensaje);
    
    fgets(linea, sizeof(linea), stdin);
    x = sscanf(linea, "%d%s", &entero ,extra);

    if(x != 1) {
      entero = -1;
    }
     
  }while (entero < 1 || entero > 100);
  
  return entero;
}

