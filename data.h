#ifndef DATA_H
#define DATA_H

//Definicion del struct.
struct Contacto {
  char nombre[25];
  int edad;
}; //OJO AL ;


int p_add(struct Contacto *tabla, int *numero);
int p_delete(struct Contacto *tabla, int *numero);
int p_list(struct Contacto *tabla, int numero);
int p_init(struct Contacto *tabla, int *numero);
void p_fin(struct Contacto *tabla, int numero);

#endif
