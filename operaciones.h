#ifndef OPERACIONES_H
#define OPERACIONES_H


void init();

// Calcula el costo de sustituir el caracter 'a' por 'b'.
// Parametros: 
// - a: Caracter original
// - b: Caracter con el que se sustituye
// Return: Costo de sustituir 'a' por 'b'
int costo_sub(char a, char b);

// Calcula el costo de insertar el caracter 'b'.
// Parametros: 
// - b: Caracter a insertar
// Return: Costo de insertar 'b'
int costo_ins(char b);

// Calcula el costo de eliminar el caracter 'a'.
// Parametros: 
// - a: Caracter a eliminar
// Return: Costo de eliminar 'a'
int costo_del(char a);

// Calcula el costo de transponer los caracteres 'a' y 'b'.
// Parametros: 
// - a: Primer caracter a transponer
// - b: Segundo caracter a transponer
// Return: Costo de transponer 'a' y 'b'
int costo_trans(char a, char b);

#endif