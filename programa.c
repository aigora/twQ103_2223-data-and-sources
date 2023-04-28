#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#define color SetConsoleTextAttribute
#define TAM_MAX 300


//Funciones

//Funci�n banner
void Banner(){
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	printf("Bienvenido a Data&Sources, esperamos que te sea util la aplicacion :)\n");
	printf("\n");
	
	color(hConsole, 1);	printf("      __________     \n"); color(hConsole, 1);
	printf("     |          |\n"); color(hConsole, 1);
	printf("     |          |\n"); color(hConsole, 1);
	printf("     |__________|\n"); color(hConsole, 1);
	printf("          ||   \n"); color(hConsole, 1);
	printf("     _____||_____\n"); color(hConsole, 1);
	printf("    |            |\n"); color(hConsole, 1);
	printf("    |            |\n"); color(hConsole, 1); 
	printf("    |____________|\n"); color(hConsole, 1); color(hConsole, 4);
	printf("   %cDATA & SOURCES%c\n", 254, 254); color (hConsole, 1);
	printf("          ||                   (.)< \n"); color (hConsole, 1);
	printf("   _______||_______            ||\n"); color(hConsole, 1);
	printf("  (                )      _ _ _||\n"); color(hConsole, 1);
	printf("  (                )     (_ _ _ _)\n"); color(hConsole, 1);
	printf("  (________________)        |_  |_    \n"); color(hConsole, 1);  
	
	color (hConsole, 15);
}

//Funci�n para imprimir datos del fichero (Revisar)
int ImprimirDatos() {
��� int i;

��� struct TUsuario usuario [TAM_MAX];

��� FILE *fdatos;

��� fdatos = fopen("DatosUsuarios.txt", "r");
��� if(fdatos == NULL) {
������� printf("Error en la apertura de salida.\n");
������� return -1;
��� }

��� i=0;
��� while (fscanf(fdatos, "%s %s %s %s",usuario[i].nombre, usuario[i].apellidos, usuario[i].profesion, usuario[i].provincia) != EOF) {
������� printf("%s\t %s\t %s\t %s\n", usuario[i].nombre, usuario[i].apellidos, usuario[i].profesion, usuario[i].provincia);
������� i++;
��� }
��� printf("\n");
��� fclose (fdatos);


��� return 0;
}

//Funci�n para inicio de sesi�n
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
	
	printf("	Intruduce tu profesi�n: \n");
	printf("	PROFESI�N: ");
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

//Funci�n verificaci�n de datos

int main () {
	//Declaraci�n de variables
	int i;
	FILE *fdatos;	
	//Imprimir Banner
	Banner();
	
	//Podemos poner tildes
	setlocale (LC_CTYPE,"spanish");
	
	do{
		printf ("\n");
		printf("	MEN� DE OPCIONES\n");
		printf("	Escriba el n�mero que representa la acci�n que desea realizar:\n");
    	printf("	1. Instrucciones del programa.\n");
    	printf("	2. Iniciar  sesi�n.\n");
    	printf("	3. Verificaci�n de datos.\n");
    	printf("	4. Iniciar programa.\n");
    	printf("	5. Salir del programa.\n");

		printf("	OPCI�N: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				system("cls");
				Instrucciones();
				break;
				
			case 2: //A�adir funci�n 
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
				
	do{
		printf ("\n");
		printf("	MEN� INICIAL\n");
		printf("	Escriba el n�mero que representa la acci�n que desea realizar:\n");
    	printf("	1. Consultar datos almacenados de fuentes\n");
    	printf("	2. Promedio de propiedades de las fuentes\n");
    	printf("	3. Calidad de la fuente seg�n el pH\n");
    	printf("	4. Motivos de utilizaci�n\n");
    	printf("    5. Valoraci�n final\n")
    	printf("    6. Salir\n\n")

		printf("	OPCI�N: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				system("cls");
				//funci�n leer ficheros por barrio 
				break;
				
			case 2:
				system("cls");
            	//funci�n promedio o media de las propiedades segun el barrio 
				break;
				
			case 3:
				system("cls");
				//Instrucciones pH
				//funte con mejor pH seg�n variables de un fichero
				break;
			
			case 4: 
				system("cls");
				//Motivo de la utilizaci�n de la aplicaci�n con porcetajes y opciones 
				break;
			
			case 5:
				system("cls");
				printf("Encuesta de valoraci�n de la Aplicaci�n");
				printf("La respuesta de estas preguntas nos permite hacer un seguimiento de la aplicaci�n para mejor la experiencia de los usuarios");
	
	
				printf("\t"); 
	
				//Preguntar y obtener repsues del usuario
				printf("1. �Ha encontrado �til la aplicaci�n? (1-5)\n");
				scanf("%d", &utilidad);
				printf("2. �La aplicaci�n resulta intuitiva? (1-5)\n");
				scanf("%d", &experiencia);
				printf("�Volve�as a utilizar la aplicaci�n? (1-5)\n");
				scanf("%d", &uso);
	
				//Calificaci�n promedio de cada pregunta 
				promedio_utilidad = (float)(utilidad) / 3;
				promedio_experiencia = (float)(experiencia) / 3;
				promedio_uso = (float)(uso) / 3;
	
				//resultados por pantalla 
				printf("\nResultados:\n");
				printf("1. Utilidad: %.2f\n", promedio_utilidad);
				printf("2. Intuitiva: %.2f\n", promedio_experiencia);
				printf("1. Utilidad: %.2f\n", promedio_uso); 
				break; 
		}
		
		
	}while (opcion != 6);
	
	
	system("cls");
	printf("FIN DEL PROGRAMA\n");
				
				break;
		}
		
		
	}while (opcion != 5);
	
	
	system("cls");
	printf("FIN DEL PROGRAMA\n");
	
	return 0; 
}
