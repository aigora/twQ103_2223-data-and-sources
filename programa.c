#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#define color SetConsoleTextAttribute
#define TAM_MAX 300


//Funciones

//Función banner
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

//Función para imprimir datos del fichero (Revisar)
int ImprimirDatos() {
    int i;

    struct TUsuario usuario [TAM_MAX];

    FILE *fdatos;

    fdatos = fopen("DatosUsuarios.txt", "r");
    if(fdatos == NULL) {
        printf("Error en la apertura de salida.\n");
        return -1;
    }

    i=0;
    while (fscanf(fdatos, "%s %s %s %s",usuario[i].nombre, usuario[i].apellidos, usuario[i].profesion, usuario[i].provincia) != EOF) {
        printf("%s\t %s\t %s\t %s\n", usuario[i].nombre, usuario[i].apellidos, usuario[i].profesion, usuario[i].provincia);
        i++;
    }
    printf("\n");
    fclose (fdatos);


    return 0;
}

//Función para inicio de sesión
int InicioDeSesion () {
	
	struct TUsuario usuario [TAM_MAX];
	
	int i = 0;
	
	FILE *fdatos;
	
	fdatos = fopen("DatosUsuarios.txt", "a");
	if(fdatos == NULL) {
		printf("Error en la apertura de salida.\n");
		return -1;
	}
	
	printf("	Intruduce tu nombre: \n");
	printf("	NOMBRE: ");
	fflush(stdin);
	gets(usuario[i].nombre);
	printf("\n");
	fprintf(fdatos, "%s\t", usuario[i].nombre);
				
	printf("	Intruduce tus apellidos: \n");
	printf("	APELLIDOS: ");
	fflush(stdin);
	gets(usuario[i].apellidos);
	printf("\n");
	fprintf(fdatos, "%s\t", usuario[i].apellidos);
	
	printf("	Intruduce tu profesión: \n");
	printf("	PROFESIÓN: ");
	fflush(stdin);
	gets(usuario[i].profesion);
	printf("\n");
	fprintf(fdatos, "%s\t", usuario[i].profesion);

	printf("	Intruduce tu provincia: \n");
	printf("	PROVINCIA: ");
	fflush(stdin);
	gets(usuario[i].provincia);
	printf("\n");
	fprintf(fdatos, "%s\t", usuario[i].provincia);
	fprintf(fdatos, "\n");
	
	return 0;
}

//Función verificación de datos

int main () {
	//Declaración de variables
	int i;
	FILE *fdatos;	
	//Imprimir Banner
	Banner();
	
	//Podemos poner tildes
	setlocale (LC_CTYPE,"spanish");
	
	do{
		printf ("\n");
		printf("	MENÚ DE OPCIONES\n");
		printf("	Escriba el número que representa la acción que desea realizar:\n");
    	printf("	1. Instrucciones del programa.\n");
    	printf("	2. Iniciar  sesión.\n");
    	printf("	3. Verificación de datos.\n");
    	printf("	4. Iniciar programa.\n");
    	printf("	5. Salir del programa.\n");

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
            	InicioDeSesion ();
				break;
				
			case 3:
				system("cls");
            	printf("\n");
				ImprimirDatos();
				break;
			
			case 4:
				
				break;
		}
		
		
	}while (opcion != 5);
	
	
	system("cls");
	printf("FIN DEL PROGRAMA\n");
	
	return 0; 
}
