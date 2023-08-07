#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Calculadora Fechas.h"


void msgIni()
{
    printf("\n*******************************\n");
    printf("*        \\--WELCOME!!--/      *\n");
    printf("*         \\   O    O  /       *\n");
    printf("*          \\    ^    /        *\n");
    printf("*           \\  ___  /         *\n");
    printf("*           /       \\         *\n");
    printf("*          /         \\        *\n");
    printf("*******************************\n\n");

    system("pause");
}


int msgMenu(Fecha fecha)
{
    int op;
    system("cls");
    do{
        printf("-------MENU CALCULADORA DE FECHAS:-------\n");
        printf("1 ---> Cargar una Fecha\n");
        printf("2 ---> Dia siguiente a la fecha\n");
        printf("3 ---> Dia anterior a la fecha\n");
        printf("4 ---> Sumar N dias a la fecha\n");
        printf("5 ---> Restar N dias a la fecha\n");
        printf("6 ---> Diferencia entre fechas\n");
        printf("7 ---> Edad de una persona\n");
        printf("0 ---> Salir\n");

        if(fecha.d!=0)
            mostrarFecha(fecha);

        printf("\nIngrese la opcion deseada:\t");

        scanf("%d",&op);
        if(op<0 || op>7)
        {
            system("cls");
            printf("\nOPCION NO VALIDA\n\n");
        }
    }while(op<0 || op>7);


    return op;
}


void mostrarFecha(Fecha f)
{
    printf("\nFecha cargada --> %d/%d/%d\n",f.d,f.m,f.a);
}


int ingrEnteroPos()
{
    int num;
    printf("Ingrese un numero positivo --> ");
    scanf("%d",&num);

    while(!esPositivo(num))
    {
        printf("Ingrese un numero positivo --> ");
        scanf("%d",&num);
    }
    return num;
}

bool esPositivo(int n)
{
    return(n>=0);
}



Fecha ingrFecha()
{
    Fecha fecha;
    system("cls");
    printf("----------------Ingreso de Fecha----------------\n");
    printf("Ingrese una fecha en formato d/m/a --> ");
    scanf("%d/%d/%d",&fecha.d,&fecha.m,&fecha.a);

    while(!esFechaValida(fecha))
    {
        puts("Fecha invalida, ingrese una fecha en formato d/m/a");
        scanf("%d/%d/%d",&fecha.d,&fecha.m,&fecha.a);
    }
    return fecha;
}

bool esFechaValida(Fecha f)
{
    if(f.a>=ANIO_BASE)
        if(f.m>=1 && f.m<=12)
            if(f.d>=1 && f.d<=cantDias(f.m,f.a))
                return true;

    return false;
}


int cantDias(int mes,int anio)
{
    int cdm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (mes==2 && ESBISIESTO(anio))
        return 29;
    return cdm [mes];
}


Fecha fechaSiguiente (Fecha f)
{
    Fecha aux;
    aux.d=f.d+1;
    aux.m=f.m;
    aux.a=f.a;

    if(aux.d>cantDias(f.m,f.a))
    {
        aux.d=aux.d- cantDias(f.m,f.a);
        aux.m++;
        if(aux.m>12)
        {
            aux.m=1;
            aux.a++;
        }
    }
    return aux;
}

Fecha fechaAnterior (Fecha f)
{
    Fecha aux;
    aux.d=f.d-1;
    aux.m=f.m;
    aux.a=f.a;

    if(aux.d==0)
    {
        aux.m--;
        if(aux.m==0)
        {
            aux.m=12;
            aux.a--;
        }
        aux.d=cantDias(aux.m,aux.a);
    }
    return aux;
}

Fecha sumarDiasFecha(Fecha f,int n)
{
    Fecha aux={f.d+n,f.m,f.a};

    while(aux.d>cantDias(aux.m,aux.a))
    {
        aux.d=aux.d - cantDias(aux.m,aux.a);
        aux.m++;
        if(aux.m>12)
        {
            aux.m=1;
            aux.a++;
        }
    }
    return aux;
}

Fecha restarDiasFecha (Fecha f, int n)
{
    Fecha aux;
    aux.d=f.d-n;
    aux.m=f.m;
    aux.a=f.a;

    while(aux.d<=0)
    {
        aux.m--;
        if(aux.m<1)
        {
            aux.m=12;
            aux.a--;
        }
        aux.d=aux.d+cantDias(aux.m,aux.a) ;
    }
    return aux;
}




int fechaMenosFecha (Fecha f, Fecha f2)
{
    int n,n2,i,j;

    n=(f.a)*365;
    n2=(f2.a)*365;

    for(i=1;i<=(12-f.m);i++)
    {
        n-=cantDias(i,f.a);
    }
    for(j=1;j<=(12-f2.m);j++)
    {
        n2-=cantDias(j,f2.a);
    }

    n-=(cantDias(f.m,f.a)-f.d);
    n2-=(cantDias(f2.m,f2.a)-f2.d);

    if(n>n2)
    {
        n-=n2;
        return n;
    }
    else{
        n2-=n;
        return n2;
    }
}


int calcularEdad(Fecha fechaNac, Fecha fechaAct)
{
    if (fechaAct.m < fechaNac.m || (fechaAct.m == fechaNac.m && fechaAct.d < fechaNac.d))
        return fechaAct.a - fechaNac.a - 1;
    else
    {
        return fechaAct.a - fechaNac.a;
    }
}
