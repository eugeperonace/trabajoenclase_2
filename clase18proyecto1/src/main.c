#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"

#define QTY_ALUMNOS 100

/**
 * 1 Alta alumno
 * 2 Baja alumno
 * 3 Modificar alumno
 * 4 Ordenar por nombre
 * 5 Imprimir
 * 6 Informe promedio alturas
 * 7 Informe alumno mas alto
 **/


int main(void)
{
	setbuf(stdout,NULL);
	Alumno* arrayPunterosAlumno[QTY_ALUMNOS];
	int opcionMenu;

	if(!alumno_initArray(arrayPunterosAlumno,QTY_ALUMNOS))
	{
			printf("INIT OK.");
	}

	do
	{
		if(!utn_getNumero(	&opcionMenu,
							"\n\nElija una opción:\n"
							"\n1) Alta de alumno."
							"\n2) Baja de alumno."
							"\n3) Modificar alumno."
							"\n4) Ordenar por nombre."
							"\n5) Imprimir."
							"\n6) Informe promedio de alturas."
							"\n7) Informe alumno más alto."

							"\n8)Salir\n\n",

							"\nError opción inválida",1,8,2) )
		{
			switch(opcionMenu)
			{
			case 1:
				if(alumno_agregarAlumnoArray(arrayPunterosAlumno,QTY_ALUMNOS,"MARIA",1.85,111) >= 0)
				{
					printf("Alta OK.\n");
				}

				break;

			case 2:
				if(!alumno_borrarPorIdArray(arrayPunterosAlumno,QTY_ALUMNOS,111))
				{
					printf("\nBORRADO OK");
				}
				break;
			case 3:
				if(!alumno_modificarArray(arrayPunterosAlumno,QTY_ALUMNOS,1))
				{
					printf("Alumno modificado con éxito");
				}
				break;
			case 4:
				break;
			case 5:
				alumno_imprimirArray(arrayPunterosAlumno,QTY_ALUMNOS);
				break;
			}
		}
	}while (opcionMenu != 8);

	return 0;
}
