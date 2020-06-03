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

int initArray(int* pArray, int limite, int valor)
{
	int retorno=-1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			*(pArray+i) = valor; // pArray[i] = valor;
		}
	}
	return retorno;
}

int imprimirArray(int* pArray, int limite)
{
	int retorno=-1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			printf("%d\n",*(pArray+i));
		}
	}
	return retorno;
}

int resizeArray(int** pArray, int* sizeActual,int sizeNuevo)
{
	int* pArrayTemp = NULL;
	int retorno=-1;
	if(pArray != NULL && sizeActual != NULL && sizeNuevo >= 0)
	{
		pArrayTemp = (int*)realloc(*pArray,sizeof(int) * sizeNuevo);
		if(pArrayTemp != NULL)
		{
			*sizeActual = sizeNuevo;
			*pArray = NULL;
			pArrayTemp = NULL;
			retorno = 0;
		}
	}
	return retorno;
}

int resizeArrayError(int* pArray, int* sizeActual,int sizeNuevo)
{
	int* pArrayTemp = NULL;
	int retorno=-1;
	if(pArray != NULL && sizeActual != NULL && sizeNuevo >= 0)
	{
		pArrayTemp = (int*)realloc(pArray,sizeof(int) * sizeNuevo);
		if(pArrayTemp != NULL)
		{
			*sizeActual = sizeNuevo;
			pArray = NULL;
			pArrayTemp = NULL;
			retorno = 0;
		}
	}
	return retorno;
}

int main(void)
{
	int* pArrayEdades = NULL;
	int sizeArrayEdades = 10;


	pArrayEdades = (int*) malloc(sizeof(int) * sizeArrayEdades);
	if(pArrayEdades != NULL)
	{
		if(!initArray(pArrayEdades,sizeArrayEdades,0))
		{
			printf("INIT OK\n");
			imprimirArray(pArrayEdades,sizeArrayEdades);
		}
		if(!resizeArray(&pArrayEdades,&sizeArrayEdades,25))
		{
			printf("RESIZE OK\n");
			imprimirArray(pArrayEdades,sizeArrayEdades);
		}

	}
	free(pArrayEdades);

	return EXIT_SUCCESS;
}
