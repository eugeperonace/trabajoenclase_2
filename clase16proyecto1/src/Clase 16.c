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

void sumar(int parametroA, int parametroB, int* pResultado)
{
	*pResultado = parametroA + parametroB;
}

void restar(int parametroA, int parametroB, int* pResultado)
{
	*pResultado = parametroA - parametroB;
}

int calcular(int parametroA, int parametroB, void(*pFuncion)(int,int,int*))
{
	int auxResultado;
	pFuncion(parametroA,parametroB,&auxResultado);
	return auxResultado;
}


int main(void)
{
	int auxiliar;

	auxiliar = calcular(10,5,restar);
	printf("El resultado de la resta es: %d\n", auxiliar);

	auxiliar = calcular(10,5,sumar);
	printf("El resultado de la suma es: %d\n", auxiliar);

	return 0;
}
