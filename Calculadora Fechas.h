#ifndef CALCULADORA_FECHAS_H_INCLUDED
#define CALCULADORA_FECHAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TODO_OK 0
#define ERROR_MEMORIA 1

#define ANIO_BASE 1601
#define ESBISIESTO(a) ((a%4==0 && a%100!=0) || a%400==0)?true:false

typedef struct
{
    int d;
    int m;
    int a;
}Fecha;

void msgIni();
int msgMenu(Fecha fecha);

int ingrEnteroPos();
bool esPositivo(int);

void mostrarFecha(Fecha f);
Fecha ingrFecha();
Fecha sumarDiasFecha(Fecha,int);
Fecha fechaSiguiente (Fecha);
Fecha fechaAnterior (Fecha);
bool esFechaValida(Fecha);
int cantDias(int,int);
Fecha restarDiasFecha (Fecha, int);
int fechaMenosFecha (Fecha, Fecha);
int calcularEdad(Fecha fechaNac, Fecha fechaAct);


#endif // CALCULADORA_FECHAS_H_INCLUDED
