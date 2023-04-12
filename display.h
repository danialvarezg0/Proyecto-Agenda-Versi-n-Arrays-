#ifndef DISPLAY_H
#define DISPLAY_H

//Cabeceras. 
void frame(char caracter, int tam_linea);
void title(char nombre[]);
int verify(char invitacion[]);
void read_string(const char *mensaje, char *palabra);
int read_integer(const char *mensaje);

#endif
