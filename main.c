#include <stdio.h>
#include <stdlib.h>
#include "Calculadora Fechas.h"

int main()
{
    msgIni();


    int flag=0,ret,n;
    Fecha fecha={0,0,0};
    int op=msgMenu(fecha);

    while(op!=0)
    {

        switch (op)
        {
            case 1:
                {
                    fecha=ingrFecha();
                    flag=1;
                    ret=TODO_OK;
                }
                break;
            case 2:
                if(flag)
                    fecha=fechaSiguiente(fecha);
                break;
            case 3:
                if(flag)
                    fecha=fechaAnterior(fecha);
                break;
            case 4:
                if(flag)
                {
                    system("cls");
                    printf("----------------Suma de N Dias a la Fecha----------------\n");
                    n=ingrEnteroPos();
                    fecha=sumarDiasFecha(fecha,n);
                }
                break;
            case 5:
                if(flag)
                {
                    system("cls");
                    printf("----------------Resta de N Dias a la Fecha----------------\n");
                    n=ingrEnteroPos();
                    fecha=restarDiasFecha(fecha,n);
                }
                break;
            case 6:
                if(flag)
                {
                    system("cls");
                    printf("----------------Diferencia entre fechas----------------\n");
                    Fecha fecha2=ingrFecha();
                    int dias=fechaMenosFecha(fecha,fecha2);
                    mostrarFecha(fecha);
                    mostrarFecha(fecha2);
                    printf("\nLa diferencia es de --> %d dias\n\n",dias);
                    system("pause");
                }
                break;
            case 7:

                system("cls");
                printf("----------------Edad de una Persona----------------\n");
                printf("Ingreso de la fecha de nacimiento\n\n");
                system("pause");
                Fecha fecha2=ingrFecha();
                system("cls");
                printf("Ingreso de la fecha actual\n\n");
                system("pause");
                Fecha fecha3=ingrFecha();
                int anios=calcularEdad(fecha2,fecha3);
                mostrarFecha(fecha2);
                mostrarFecha(fecha3);
                printf("\nLa edad es de --> %d anios\n\n",anios);
                system("pause");
                break;
        }

        if(flag)
        {
            if(ret)
            {
                printf("\nCodigo de error: %d\n",ret);
                system("pause");
            }
            mostrarFecha(fecha);
        }
        else
        {
            if(op!=7)
            {
                printf("\nAntes debe de ingresar una fecha\n");
                system("pause");
            }
        }
        op=msgMenu(fecha);
    }

    printf("\nPROGRAMA FINALIZADO CON EXITO\nADIOS\n");
    return 0;
}


