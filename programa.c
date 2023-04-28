#include <stdio.h>
#include <windows.h>
#include <locale.h>
#define color SetConsoleTextAttribute

void Banner(){
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	color (hConsole, 1);
	
	printf("      __________     \n"); color(hConsole, 1);
	printf("     |          |\n"); color(hConsole, 1);
	printf("     |          |\n"); color(hConsole, 1);
	printf("     |__________|\n"); color(hConsole, 1);
	printf("          ||   \n"); color(hConsole, 1);
	printf("     _____||_____\n"); color(hConsole, 1);
	printf("    |            |\n"); color(hConsole, 1);
	printf("    |            |\n"); color(hConsole, 1); 
	printf("    |____________|\n"); color(hConsole, 1); color(hConsole, 4);
	printf("   %cDATA & SOURCES%c\n", 254, 254); color (hConsole, 1);
	printf("          ||\n"); color (hConsole, 1);
	printf("   _______||_______\n"); color(hConsole, 1);
	printf("  (                )\n"); color(hConsole, 1);
	printf("  (                )\n"); color(hConsole, 1);
	printf("  (________________)\n"); color(hConsole, 1);
	
	color (hConsole, 15);
	
	return;
}

int ImprimirDatos() {
    int i;

    struct TUsuario usuario [TAM_MAX];

    FILE *fprueba;

    fprueba = fopen("inicioprueba.txt", "r");
    if(fprueba == NULL) {
        printf("Error en la apertura de salida.\n");
        return -1;
    }

    i=0;
    while (fscanf(fprueba, "%s %s %s %s",usuario[i].nombre, usuario[i].apellidos, usuario[i].profesion, usuario[i].provincia) != EOF) {
        printf("%s\t %s\t %s\t %s\n", usuario[i].nombre, usuario[i].apellidos, usuario[i].profesion, usuario[i].provincia);
        i++;
    }
    printf("\n");
    fclose (fprueba);


    return 0;
}

int main () {
	//Imprimir Banner
	Banner();
	
	//Podemos poner tildes
	setlocale (LC_CTYPE,"spanish");
	
	do{
		printf ("\n");
		printf("	MENÚ DE OPCIONES\n");
		printf("	Escriba el número que representa la acción que desea realizar:\n");
    	printf("	1. Instrucciones del programa\n");
    	printf("	2. Iniciar  sesión\n");
    	printf("	3. Iniciar programa\n");
    	printf("	4. Salir\n\n");

		printf("	OPCIÓN: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				system("cls");
				Instrucciones();
				break;
				
			case 2: //Añadir función 
				system("cls");
            	printf("\n");

				pfichero=fopen ("Datos.txt", "w");

				printf("	Intruduce tu nombre: \n");
				printf("	NOMBRE: ");
				fflush(stdin);
				gets(Usuario.nombre);
				printf("\n");
				
				printf("	Intruduce tus apellidos: \n");
				printf("	APELLIDOS: ");
				fflush(stdin);
				gets(Usuario.apellidos);
				printf("\n");

				printf("	Intruduce tu profesión: \n");
				printf("	PROFESIÓN: ");
				fflush(stdin);
				gets(Usuario.profesion);
				printf("\n");

				printf("	Intruduce tu provincia: \n");
				printf("	PROVINCIA: ");
				fflush(stdin);
				gets(Usuario.provincia);
				printf("\n");


				printf ("	Bienvenido a la aplicación\n\n");
				printf ("	En breves comenzará el programa\n");
				printf("\n");

				break;
				
			case 3:
				
				break;
		}
		
		
	}while (opcion != 4);
	
	
	system("cls");
	printf("FIN DEL PROGRAMA\n");
	
	return 0; 
}
