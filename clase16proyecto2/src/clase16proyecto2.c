/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef int (*tPFuncSaludar)(char*,int);

int saludarEsp(char* mensaje, int numero)
{
	printf("Hola %s - %d\n",mensaje,numero);
	return 0;
}

int saludarIng(char* mensaje, int numero)
{
	printf("Hello %s - %d",mensaje,numero);
	return 0;
}

void saludo(char* mensaje, int numero, tPFuncSaludar pFuncSaludar) // int (*pFuncSaludar)(char*,int))
{
	pFuncSaludar(mensaje,numero);
}

int main(void)
{
	saludo("AAA",222,saludarEsp);
	saludo("AAA",222,saludarIng);

	return 0;
}
