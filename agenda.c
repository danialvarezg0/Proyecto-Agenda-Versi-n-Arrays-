#include<stdio.h>
#include<ctype.h>
#include<string.h>

#include "display.h"
#include "data.h"


//Funcion principal.
int main() {

  //Array de contactos.
  struct Contacto contactos[100];
  
  int numContactos;

  char linea[256], extra[256];

  //Primero llamamos a la funcion p_init.
  p_init(contactos, &numContactos);
  
  char opcion, validacion;
  int resultado;
  
  //Presentamos por pantalla la caratula.
  frame('-', 50);
  
  //Inicio del bucle.
  do {
  
    //Mostramos el menu por pantalla.
    printf("\n");
    printf("A) Add\n");
    printf("D) Delete\n");
    printf("L) List\n");
    printf("X) Exit\n");
    printf("\n");

    printf("Choose an option: ");

    //Leemos la opcion introducida por el usuario para asegurarnos de que solo introduce un caracter.
    fgets(linea, sizeof(linea), stdin);
    
    int x = sscanf(linea, "%c%s", &opcion ,extra);

    //Si x es distinto de uno significa que el usuario ha introducido mas de un caracter.
    if(x!=1) {

      printf("\nInvalid option\n\n");
      
    }else {

      //Hacemos que el programa no diferencie entre mayusculas y minisculas haciendo uso de la instruccion tolower.
      opcion=tolower(opcion);
  
      //Definimos las diferentes opciones entre las que puede elegir el usuario.
      switch(opcion) {

      case('a'):
	p_add(contactos, &numContactos); 

	break;
      case('d'):
	p_delete(contactos, &numContactos);

	break;
      case('l'):
	p_list(contactos, numContactos);

	break;
      case('x'):
	//Creamos un bucle do-while dentro del case 'x' para que pueda repetirse la pregunta si el usuario introduce una respuesta invalida.
	do {

	  resultado = verify("\n\n\nAre you sure you want to exit the program"); //Almacenamos el valor que devuelve la funcion en la variable 'resultado'.
	
	  if(resultado == 1) {
	    
	    validacion = 'y';
	  
	    break; 
	  }else {
	    
	    validacion = 'n';
	  }
	  
	  if(validacion == 'n') opcion = validacion;
	
	  break;
	}
	while (validacion != 'y' || validacion != 'n'); //El bucle se repite siempre que no se cumplan estas condiciones.

	break;
      
      default:
	printf("\nInvalid option\n\n");

	break;
      }
    }
  } while (opcion != 'x'); //Funcionamiento del bucle: Se repetira siempre que la opcion elegida sea distinta de 'x'


  //Llamada a la funcion p_fin que guarda la lista de contactos actualizada en un fichero de salida.
  p_fin(contactos, numContactos);

  return 0;
}


/*
  NOTAS:

  - Para compilar usando la libreria math hasy que añadir a la linea de compilacion '-lm' -> gcc -Wall ej7.c -lm -o ej7
  - Copiar un .c de un directorio a otro en otro .c -> cp ../"carpeta origen"/.c que queremos copiar .c en el que lo queremos copiar (aunque no este creado)
*/

//mv ej3.c ej1.c -> Para renombrar el fichero
