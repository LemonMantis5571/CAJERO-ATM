#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define USUARIOREAL "Admin"
#define CLAVEREAL "1234"
#define LONGITUD 8
#define MAXINTENTOS 3
void loadingscreen();
char tecla,tecla1,teclasalida;
void intentosrestantes(void);
void sinintentos(void);
void numeroinvalido(void);
void opcioninvalida(void);
void otratrans(void);
void iterador (void);
int denuevo=1;
int intento=0;
int intentoactual = 0;
char usuario[LONGITUD];
char clave[LONGITUD];
int opcion;
int opcion1;
float recarga;
float saldo=0;
float retiro;
char numeros[8];
char numdigits[4];
int numdigit;
char empresa;
char transnueva[1];
int otravez=1;
int numero;
int copia[8], prefijo, copianum;
int limiterecarga = 1000;
int i = 0;
int acsii();
int VerificacionPrefijos(int prefijoNumero);
void iterador (void);
int arregloClaro[8][2] = 
{
    { 5740, 5809 },
    { 8330, 8369 },
    { 8400, 8449 },
    { 8490, 8549 },
    { 8600, 8669 },
    { 8690, 8749 },
    { 8820, 8859 },
    { 8900, 8949 },
};
int arregloTigo[8][2] =
{
    { 7710, 8329 },
    { 8370, 8399 },
    { 8450, 8489 },
    { 8550, 8599 },
    { 8670, 8689 },
    { 8750, 8819 },
    { 8860, 8899 },
    { 8950, 8999 },
};

int claroLongi = sizeof(arregloClaro) / sizeof(arregloClaro[0]);
int tigoLongi = sizeof(arregloTigo) / sizeof(arregloTigo[0]);

int main()
{
    system("color 0C");
    system("cls");
    do
    {
    	system("cls");
        printf("\n\t\t\t\tINICIO DE SESION\n\t\t\t\t----------------");
        printf("\n\t\t\t\tUSUARIO:");
        gets(usuario);

        printf("\n\t\t\t\tCLAVE:");
        gets(clave);
 
        if(strcmp(usuario, USUARIOREAL)!=0 && (clave, CLAVEREAL)!=0)
        {
            intento++;
        	intentoactual=(MAXINTENTOS - intento);
            sinintentos();          
            printf("\t\t\t\tUsuario y clave incorrectos\n");
            intentosrestantes();
        }
        
        else if(strcmp(usuario, USUARIOREAL) !=0)
        {
            intento++;
        	intentoactual=(MAXINTENTOS - intento);
            sinintentos();
            printf("\n\t\t\t\tUsuario incorrecto\n");
            intentosrestantes();
        }
        
        else if(strcmp(clave, CLAVEREAL) !=0)
        {
            intento++;
        	intentoactual=(MAXINTENTOS - intento);       
            sinintentos();                
            printf("\n\t\t\t\tClave incorrecta\n");
            intentosrestantes();
        }
        
        else
        {
            while(otravez=1)
            {
                menuprincipal:
                system("cls");
                printf("\n\t\t\t\tMENU PRINCIPAL\n\t\t\t\t--------------");
                printf("\n\t\t\t\t1. Cajero UNI");
                printf("\n\t\t\t\t2. Recarga");
                printf("\n\t\t\t\t3. Salir\n\t\t\t\t");
                tecla = getch();
                if (tecla==49 || tecla==50 || tecla==51)
                {
                    switch (tecla)
                    {             
                    case 49:
                        cajerouni:
                        fflush(stdin);
                        system("cls");
                        printf("\n\t\t\t\tCAJERO UNI\n\t\t\t\t----------");
                        printf("\n\t\t\t\t1. Ingresar saldo");
                        printf("\n\t\t\t\t2. Ver saldo");
                        printf("\n\t\t\t\t3. Retirar saldo");
                        printf("\n\t\t\t\t4. Regresar\n\t");
                        tecla1 = getch();
                        if (tecla1>=49 || tecla1<=52)
                        {
                            switch (tecla1)
                            {
                                case 49:
                                while(denuevo=1)
                                {
                                    float limite = 10000;
                                    recarga:
                                    system("cls");
                                    printf("\n\tIngrese el monto a recargar (Menor a 10.000 C$ y mayor a 0 C$)\n\t");
                                    scanf("%f",&recarga);
                                    if (recarga>9999 || recarga<=0 || isalpha(recarga))
                                    {
                                        system("cls");
                                        printf("\n\tIngrese un valor numerico menor a 10.000 C$ y mayor a 0 C$");
                                        printf("\n\tPulse una tecla para continuar");
                                        getch();
                                        goto cajerouni;
                                    }
                                    else if  (recarga>limite  || saldo > limite)
                                    {
                                    system("cls");
                                    printf("\n\t La recarga sobrepasa el limite de saldo");
                                    printf ("\n\t Pulse una tecla para continuar");
                                    getch();
                                    goto cajerouni;
                                    }
                                    else if (saldo+recarga>limite)
                                    {
                                        printf("\n\t La recarga sobrepasa el limite de saldo");
                                        printf ("\n\t Pulse una tecla para continuar");
                                        getch();
                                        goto cajerouni;
                                    }
                                    
                                    else 
                                    {
                                        saldo=saldo+recarga;
                                        recargaexitosa:
                                        system("cls");
                                        printf("\n\tRecarga realizada exitosamente");
                                        printf("%s %.2f","\n\tSu nuevo saldo es",saldo);
                                        otratrans();

                                        if (tecla==83 || tecla==115)
                                        {
                                            goto cajerouni;
                                        }

                                        else if (tecla==78 || tecla==110)
                                        {
                                            printf("\n\tGracias por preferirnos!\n");
                                            printf("\tPulse una tecla para salir del programa");
                                            getch();
                                            exit(1);
                                        }

                                        else
                                        {
                                            goto recargaexitosa;
                                        }
                                        break;
                                    }
                                }
                                
                                case 50:
                                    system("cls");
                                    printf("%s %.2f %s","\n\tSu saldo actual es: ",saldo,"\n\t");
                                    printf("Pulse una tecla para continuar");
                                    getch();
                                    goto cajerouni;                            

                                case 51:
                                while(denuevo=1)
                                {
                                    retiro:
                                    if (saldo<=0)
                                    {
                                        system("cls");
                                        printf("\n\tNo tiene saldo disponible\n\t");
                                        printf("\n\tPulse una tecla para continuar");
                                        getch();
                                        goto cajerouni;
                                    }

                                    system("cls");
                                    printf("\n\tIngrese el monto a retirar (Menor a 10.000 C$)\n\t");
                                    scanf("%f",&retiro);

                                    if (retiro>9999 || retiro<=0 || isalpha(retiro))
                                    {
                                        
                                        system("cls");
                                        cameback1:
                                        printf("\n\tIngrese un valor numerico menor a 10.000 C$ y mayor a 0 C$");
                                        printf("\n\tPulse una tecla para continuar");
                                        getch();
                                        system("cls");
                                        goto cajerouni;
                                            
                                         
                                    }

                                    else if (retiro>saldo)
                                    {   
                                        char tecla3;
                                        system("cls");
                                        cameback:
                                        printf("\n\tNo posee suficiente saldo para retirar este monto");
                                        printf("%s %.2f","\n\tSu saldo actual es: ",saldo);
                                        printf("\n\tPulse una tecla para continuar");
                                        getch();
                                        system("cls");
                                        goto cajerouni;
                                    }

                                    else
                                    {
                                        saldo=saldo-retiro;
                                        retiroexitoso:
                                        system("cls");
                                        printf("\n\tRetiro realizado exitosamente");
                                        printf("\n\tRetire su efectivo");
                                        printf("%s %.2f","\n\tSu nuevo saldo es",saldo);
                                        otratrans();

                                        if (tecla==83 || tecla==115)
                                        {
                                            goto menuprincipal;
                                        }

                                        else if (tecla==78 || tecla==110)
                                        {
                                            system("cls");
                                            printf("\n\tGracias por preferirnos!");
                                            printf("\tPulse una tecla para salir del programa");
                                            getch();
                                            exit(1);
                                        }

                                        else
                                        {
                                            goto retiroexitoso;
                                        }
                                        break;
                                    }
                                }    
                                case 52:
                                    goto menuprincipal;

                                
                                default:
                                goto cajerouni;
							}        
                    
                    
                        }
                    case 50:
                    system("cls");
                    fflush(stdin);
                    iterador();
                    break;
				    case 51:
                    system("cls");
                    printf("\n\tGracias por preferirnos\n");
                    printf("\tPulse una tecla para salir del programa");
                    getch();
                    exit(1);	    
                    }
                }
          
                else
				{
					goto menuprincipal;
				}
            }
        }
    }
    while(denuevo=1);
}

void intentosrestantes(void)
{
    printf("%s %d %s","\t\t\t\tLe quedan ",intentoactual,"intentos\n");
    printf("\t\t\t\tPulse una tecla para continuar");
    getch();
}

void sinintentos(void)
{
    if(intento>=MAXINTENTOS)
	    {
        system("cls");
        printf("\n\t\t\t\tNo le quedan mas intentos\n");
        printf("\t\t\t\tGracias por preferirnos!\n");
        printf("\t\t\t\tPulse una tecla para salir del programa");
        getch();
        exit(1);
        }	
}

void numeroinvalido(void)
{
    printf ("\n\tDigite un numero telefonico valido de 8 digitos\n\t");
    getch();
}

void opcioninvalida(void)
{
    printf("\n\tDigite una opcion valida\n\t");
    printf("Pulse una tecla para continuar");
    getch();
}

void otratrans(void)
{
    printf("\n\tDesea realizar otra transaccion?\n");
    printf("\t[S]/[N]");
    tecla = getch();    
}

void iterador (void)
{ 
    char empresa[10];
    char tecladecisiva;
    printf("\t\t\t\tBievenido al Sistema de recarga telefonica\n");
    printf("\t\t\t\tQue desea hacer?\n");
    printf("\t\t\t\t1. Recargar saldo\n");
    printf("\t\t\t\t2. Salir\n\t\t\t\t");
    tecladecisiva=getch();  
        if (tecladecisiva>=49 || tecladecisiva<50)
        {
            switch (tecladecisiva)
            {
            case 49:
                
                printf("\n\t\t\t\t* Recarga Electronica *\n");
                printf("\n\t\tIngrese su numero telefonico: ");
                scanf("%i", &numero);
                copianum = numero;

                do
                {
                    copia[i] = numero % 10;
                    numero /= 10;
                    i++;

                }   while (numero != 0);
        
                prefijo = copia[7] * 1000 + copia[6] * 100 + copia[5] * 10 + copia[4];

                int funcion = VerificacionPrefijos(prefijo);

                if (funcion==30)
                {
                    printf("\n\t\t(!) Numero no identificado\n");
                    printf("\n\t\t\t->  Presione cualquier tecla para intentarlo denuevo\n\t\t\t");
                    goto inicio;
        
                }    
                else if (isdigit(recarga))
                {
                    printf("\n\t\tCantidad a recargar: $ ");
                    scanf("%i", &recarga);
                    
                }
                
                if (isalpha(recarga))
                {
                	printf("\n\t\t(Warning) Introduzca un numero valido de 8 digitos\n");
                    printf("\t\tPresione una tecla para continuar");
                    goto inicio;
				}
                if (isdigit(recarga)) 
                {
                    if(funcion==20 && recarga<=saldo)
                    {
                        empresa[0] = 'T';
                        empresa[1] = 'I';
                        empresa[2] = 'G';
                        empresa[3] = 'O';
                        printf("\t\tRecarga aplicada a Tigo\n");
                    }

                    if (funcion==10 && recarga<=saldo)
                    {
                        empresa[0] = 'C';
                        empresa[1] = 'L';
                        empresa[2] = 'R';
                        empresa[3] = 'O';
                        printf("\t\tRecarga aplicada a Claro \n");
                    }
                
                    if(recarga > saldo) 
                    {
                        printf("\n\t\t(Warning) La recarga sobrepasa a su saldo disponible.\n");
                        printf("\t\tPresione una tecla para continuar");
                        goto inicio;
                    }

                    if(recarga > limiterecarga)
                    {
                        printf("\n\t\t(Warning) Sobrepasa el limite de transaccion.\n");
                        printf("\n\t\t\t-> Presione cualquier tecla para intentarlo denuevo\n\t\t\t");
                        goto inicio;
                    }

                    if(recarga <= 0)
                    {
                        printf("\n\t\t(Warning) La recarga no puede ser menor o igual a cero.\n");
                        printf("\n\t\t\t-> Presione cualquier tecla para intentarlo denuevo");
                        goto inicio;

                    }
                    else
                    {
                        saldo = saldo - recarga;
                        printf("\n\t\tSu recarga de aplico correctamente al numero: %i.\n",copianum);
                        printf("\n\t\t(xD)Presione cualquier tecla para continuar\n\t\t");
                        goto inicio;
                    }
                    inicio:
                    getch();
               }
               else
               {
                    printf("\n\t\t(Warning) Introduzca un numero valido de 8 digitos\n");
                    printf("\t\tPresione una tecla para continuar");
                    getch();
                    goto inicio;
               }
               
            }
        }   
        
}

int VerificacionPrefijos(int prefijoNumero)
{   
    for (int i = 0; i < claroLongi; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if ((prefijoNumero >= arregloClaro[i][j]) && (prefijoNumero <= arregloClaro[i][j + 1]))
                return 10;
        }
    }
    for (int i = 0; i < tigoLongi; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if ((prefijoNumero >= arregloTigo[i][j]) && (prefijoNumero <= arregloTigo[i][j + 1]))
                return 20;            
        }
    }

    return 30;
}

    
        








