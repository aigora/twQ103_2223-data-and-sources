#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#define color SetConsoleTextAttribute
#define TAM_MAX 300


//Declaración de estructuras

//Estructura para guardar los datos del usuario
struct TUsuario{
	char nombre[50];
	char apellidos[100];
	char profesion[100];
	char provincia[100];
};

//Estructura para los parámetros del agua
struct TFuente{
	char fuentes[30];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};

//Estructura para leer la cabecera de los ficheros
struct TCabecera {
	char columna[30];
};

//FUNCIONES

//Función banner
void Banner(){
	setlocale (LC_CTYPE,"spanish");
	HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	printf("	Bienvenido a Data&Sources, esperamos que te sea útil la aplicacion :)\n");
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

//Función para inicio de sesión
int InicioDeSesion () {

	struct TUsuario usuario [TAM_MAX];

	int encontrado = 0, contadorestudiante = 0, contadorprofesor = 0, contadorciudadano = 0;

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

	printf("	Intruduce tu profesión (estudiante, profesor o ciudadano): \n");
	printf("	PROFESIÓN: ");
	fflush(stdin);
	gets(usuario[i].profesion);
	printf("\n");
	fprintf(fdatos, "%s\t", usuario[i].profesion);
	if(strcmp(usuario[i].profesion, "estudiante") == 0){
		encontrado = 1;
	} else if(strcmp(usuario[i].profesion, "profesor") == 0){
		encontrado = 1;
	}else if(strcmp(usuario[i].profesion, "ciudadano") == 0){
		encontrado = 1;
	}else{
		printf("	No ha seleccionado ninguna opción correcta vuelva a intentarlo.\n");
		return 0;
	}

	printf("	Intruduce tu provincia: \n");
	printf("	PROVINCIA: ");
	fflush(stdin);
	gets(usuario[i].provincia);
	printf("\n");
	fprintf(fdatos, "%s\t", usuario[i].provincia);
	fprintf(fdatos, "\n");
	fclose(fdatos);

	return 0;
}

//Función para imprimir datos del fichero del inicio de sesion 
int ImprimirDatos() {

	struct TUsuario usuario[TAM_MAX];

	int i;

	FILE *fdatos;

	fdatos = fopen("DatosUsuarios.txt", "r");
	if(fdatos == NULL){
		printf("Error en la apertura del fichero.\n");
		return -1;
	}

	i=0;
	while(fscanf(fdatos, "%s %s %s %s", usuario[i].nombre, usuario[i].apellidos, usuario[i].profesion, usuario[i].provincia) != EOF){
		printf("%s\t %s\t %s\t %s\n", usuario[i].nombre, usuario[i].apellidos, usuario[i].profesion, usuario[i].provincia);
		i++;
	}
	printf("\n");
	fclose(fdatos);
}

//Función para imprimir los datos de los ficheros
int ImprimirFicheros (){

	int num_fuentes = 0;

	char linea[100], opcion;

	struct TFuente fuentes[TAM_MAX];

	FILE *flavapies, *fchamberi, *fsalamanca;

	printf("Introduce el fichero del cual quieres saber los datos: \n");
	printf("	1. Lavapies (l/L).\n");
	printf("	2. Chamberi (c/C).\n");
	printf("	3. Salamanca (s/S).\n");
	printf("	OPCIÓN: ");
	scanf("%c", &opcion);
	fflush(stdin);

	if(opcion == 'l' || opcion == 'L'){
		flavapies = fopen("Lavapies.txt", "r");
		if(flavapies == NULL) {
			printf("Error en la apertura de salida.\n");
			return -1;
		}


		fgets(linea, 100, flavapies);
		printf("%s", linea);

   		while (fscanf(flavapies, "%s %f %d %d %d", fuentes[num_fuentes].fuentes, &fuentes[num_fuentes].pH, &fuentes[num_fuentes].conductividad, &fuentes[num_fuentes].turbidez, &fuentes[num_fuentes].coliformes) != EOF) {
	  		 printf("%s\t\t %.2f\t\t\t %d\t %d\t\t\t\t %d\n", fuentes[num_fuentes].fuentes, fuentes[num_fuentes].pH, fuentes[num_fuentes].conductividad, fuentes[num_fuentes].turbidez, fuentes[num_fuentes].coliformes);
	  		 if (num_fuentes >= TAM_MAX){
        		printf("Error: demasiadas fuentes en el fichero\n");
        		num_fuentes++;
        		break;
			}
   		 }

    	if(num_fuentes == 0){
    		printf("Error: archivo vacio\n");
		}
		fclose (flavapies);

	} else if (opcion == 'c' || opcion == 'C'){
		fchamberi = fopen("Chamberi.txt", "r");
		if(fchamberi == NULL) {
			printf("Error en la apertura de salida.\n");
			return -1;
		}


		fgets(linea, 100, fchamberi);
		printf("%s", linea);

   		while (fscanf(fchamberi, "%s %f %d %d %d", fuentes[num_fuentes].fuentes, &fuentes[num_fuentes].pH, &fuentes[num_fuentes].conductividad, &fuentes[num_fuentes].turbidez, &fuentes[num_fuentes].coliformes) != EOF) {
	  		 printf("%s\t\t %.2f\t\t %d\t\t %d\t\t\t %d\n", fuentes[num_fuentes].fuentes, fuentes[num_fuentes].pH, fuentes[num_fuentes].conductividad, fuentes[num_fuentes].turbidez, fuentes[num_fuentes].coliformes);
	  		 if (++num_fuentes >= TAM_MAX){
        		printf("Error: demasiadas fuentes en el fichero\n");
        		break;
			}
   		 }

    	if(num_fuentes == 0){
    		printf("Error: archivo vacio\n");
		}
		fclose (fchamberi);

	} else if (opcion == 's' || opcion == 'S'){
		fsalamanca = fopen("Salamanca.txt", "r");
		if(fsalamanca == NULL) {
			printf("Error en la apertura de salida.\n");
			return -1;
		}


		fgets(linea, 100, fsalamanca);
		printf("%s", linea);

   		while (fscanf(fsalamanca, "%s %f %d %d %d", fuentes[num_fuentes].fuentes, &fuentes[num_fuentes].pH, &fuentes[num_fuentes].conductividad, &fuentes[num_fuentes].turbidez, &fuentes[num_fuentes].coliformes) != EOF) {
	  		 printf("%s\t\t %.2f\t\t\t %d\t\t %d\t\t\t %d\n", fuentes[num_fuentes].fuentes, fuentes[num_fuentes].pH, fuentes[num_fuentes].conductividad, fuentes[num_fuentes].turbidez, fuentes[num_fuentes].coliformes);
	  		 if (++num_fuentes >= TAM_MAX){
        		printf("Error: demasiadas fuentes en el fichero\n");
        		break;
			}
   		 }

    	if(num_fuentes == 0){
    		printf("Error: archivo vacio\n");
		}
		fclose (fsalamanca);
	} else{
		printf("La opción introducida no es válida, vuelvalo a intentar.\n");
	}


    return 0;
}

//Función lectura de fichero instrucciones
int LecturaFicheroInformacion(char *nombreFichero){
    FILE *farchivo;
    farchivo = fopen(nombreFichero, "r");
    char lineainstrucciones[80];
    if(farchivo == NULL){
       printf("	Error en la apertura del fichero\n");
       return -1;
    }

    char c;

    while(((c = fgetc(farchivo))) != EOF) {
        printf("%c", c);
    }
    printf("\n\n");
    return 0;
}

//Función verificación de datos personales
int VerificacionDatos (){
	int num_fuentes = 0;
	char respuesta;
	printf("¿Son sus datos correctos? Si(s) o No(n): ");
	fflush(stdin);
	scanf("%c", &respuesta);
	if(respuesta == 'n' || respuesta == 'N'){
		printf("Vuelva a introducir sus datos.\n");
		InicioDeSesion();
		return 0;
	}else{
		printf("Sus datos son correctos, puede continuar con el programa.\n");
	}
	return 0;
}

//Funcion promedio encuestas
float promedio (int funcion, float dim){

    float resultado;

    resultado = (float) funcion/dim;

    return resultado;
}

//Función encuesta
void encuesta() {
	fflush(stdin);
	system("cls");
	printf("Encuesta de valoración de la Aplicación\n");
	printf("La respuesta de estas preguntas nos permite hacer un seguimiento de la aplicación para mejorar la experiencia de los usuarios\n\n");

	int utilidad, experiencia, uso, dim = 3;

	//Preguntar y obtener respuestas del usuario
	printf("	1. ¿Ha encontrado útil la aplicación? (1-5)\n");
    printf("		RESPUESTA: ");
    scanf("%d", &utilidad);
    printf("	2. ¿La aplicación resulta intuitiva? (1-5)\n");
    printf("		RESPUESTA: ");
    scanf("%d", &experiencia);
    printf("	3. ¿Volverías a utilizar la aplicación? (1-5)\n");
    printf("		RESPUESTA: ");
    scanf("%d", &uso);

	//resultados por pantalla
	printf("    \nResultados:\n");
    printf("	1. Utilidad: %.2f\n", promedio (utilidad,  dim));
    printf("	2. Intuitiva: %.2f\n", promedio (experiencia, dim));
    printf("	3. Reutilización: %.2f\n", promedio (uso, dim));
    //Resultado final sobre 5
    printf("	Resultado final sobre 5 de su experiencia con la aplicación: %.2f\n", promedio (utilidad,  dim) + promedio (experiencia, dim) + promedio (uso, dim));
}

//Función media conductividad
float calcularconductividad(char* nombreFichero){
		
	int num_fuentes = 0;
	
	struct TFuente fuentes[TAM_MAX];
	struct TCabecera cabecera[5];
	
	float mediaconductividad = 0.0f;
	
	int i = 0;
		
	FILE *farchivo;
	
	farchivo = fopen(nombreFichero, "r");
	
	if(farchivo == NULL){
		printf("Error en la apertura de fichero.\n");
		return -1;
	}
	
	fscanf(farchivo,"%s %s %s %s %s", cabecera[0].columna, cabecera[1].columna, cabecera[2].columna, cabecera[3].columna, cabecera[4].columna);
	
	while(fscanf(farchivo, "%s %f %d %d %d", fuentes[i].fuentes, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF){
		if(num_fuentes >= TAM_MAX){
			printf("Error, demasiadas fuentes en el fichero.\n");
			fclose(farchivo);
			return -1;
		}
		num_fuentes++;
		i++; 
	}

	
	if(num_fuentes == 0){
		printf("Error: el archivo esta vacio.\n");
	}
	
	for(i = 0; i < num_fuentes;i++) {
		mediaconductividad += fuentes[i].conductividad;
	}
	
	fclose(farchivo);
	
	return (mediaconductividad/(float) 25);
}

//Función contador conductividad
int Contadorconductividad(char* nombreFichero){
		
	int num_fuentes = 0;
	
	struct TFuente fuentes[TAM_MAX];
	struct TCabecera cabecera[5];
	
	int contadorconductividad = 0;
	
	int i = 0;
		
	FILE *farchivo;
	
	farchivo = fopen(nombreFichero, "r");
	
	if(farchivo == NULL){
		printf("Error en la apertura de fichero.\n");
		return -1;
	}
	
	fscanf(farchivo,"%s %s %s %s %s", cabecera[0].columna, cabecera[1].columna, cabecera[2].columna, cabecera[3].columna, cabecera[4].columna);
	
	while(fscanf(farchivo, "%s %f %d %d %d", fuentes[i].fuentes, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF){
		if(num_fuentes >= TAM_MAX){
			printf("Error, demasiadas fuentes en el fichero.\n");
			fclose(farchivo);
			return -1;
		}
		num_fuentes++;
		i++; 
	}

	
	if(num_fuentes == 0){
		printf("Error: el archivo esta vacio.\n");
	}
	
	for(i = 0; i < num_fuentes;i++) {
		if(100 < fuentes[i].conductividad && fuentes[i].conductividad < 200){
			contadorconductividad++;
		}
	}

	fclose(farchivo);
	
	return contadorconductividad;
}

//Función Calidad conductividad
void CalidadConductividad() {
	int opcion;
	setlocale (LC_CTYPE,"spanish");
	do{
		printf("	Introduzca la opción que desea realizar: ");
		printf("\n");
		printf("	1. Ver la media de la conductividad de los barrios.\n");
		printf("	2. Ver el número de fuentes aptas para consumo por barrio.\n");
		printf("	3. Ver el barrio con mejor calidad.\n");
		printf("	4. Salir");
		printf("\n\n");
		printf("	OPCIÓN: ");
		scanf("%d", &opcion);
	
		switch (opcion){
			case 1: 
				system("cls");
				printf("	La media de la conductividad de lavapies es %f\n", calcularconductividad("Lavapies.txt"));
				printf("	La media de la conductividad de salamanca es %f\n", calcularconductividad("Salamanca.txt"));
				printf("	La media de la conductividad de chamberi es %f\n", calcularconductividad("Chamberi.txt"));
				printf("\n\n");	
				break;
				
			case 2:
				system("cls");
				printf("	Hay %d fuentes aptas para consumo en Lavapiés.\n", Contadorconductividad("Lavapies.txt"));
				printf("	Hay %d fuentes aptas para consumo en Salamanca.\n", Contadorconductividad("Salamanca.txt"));
				printf("	Hay %d fuentes aptas para consumo en Chamberí.\n", Contadorconductividad("Chamberi.txt"));
				printf("\n\n");	
				break;
				
			case 3:
				system("cls");
				if(Contadorconductividad("Lavapies.txt") > Contadorconductividad("Salamanca.txt") && Contadorconductividad("Lavapies.txt") > Contadorconductividad("Chamberi.txt")){
					printf("	El barrio con mejor conductividad es Lavapiés.\n");
				}else if (Contadorconductividad("Salamanca.txt") > Contadorconductividad("Lavapies.txt") && Contadorconductividad("Salamanca.txt") > Contadorconductividad("Chamberi.txt")){
					printf("	El barrio con mejor conductividad es Salamanca.\n");
				}else{
					printf("	El barrio con mejor conductividad es Chamberí.\n");
				}
				printf("\n\n");	
				break;
		}
	}while (opcion!=4);	
}

//Función media turbidez
float calcularturbidez(char* nombreFichero){
		
	int num_fuentes = 0;
	
	struct TFuente fuentes[TAM_MAX];
	struct TCabecera cabecera[5];
	
	float mediaturbidez = 0.0f;
	
	int i = 0;
		
	FILE *farchivo;
	
	farchivo = fopen(nombreFichero, "r");
	
	if(farchivo == NULL){
		printf("Error en la apertura de fichero.\n");
		return -1;
	}
	
	fscanf(farchivo,"%s %s %s %s %s", cabecera[0].columna, cabecera[1].columna, cabecera[2].columna, cabecera[3].columna, cabecera[4].columna);
	
	while(fscanf(farchivo, "%s %f %d %d %d", fuentes[i].fuentes, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF){
		if(num_fuentes >= TAM_MAX){
			printf("Error, demasiadas fuentes en el fichero.\n");
			fclose(farchivo);
			return -1;
		}
		num_fuentes++;
		i++; 
	}

	
	if(num_fuentes == 0){
		printf("Error: el archivo esta vacio.\n");
	}
	
	for(i = 0; i < num_fuentes;i++) {
		mediaturbidez += fuentes[i].turbidez;
	}
	
	fclose(farchivo);
	
	return (mediaturbidez/(float) 25);
}

//Función contador turbidez
int Contadorturbidez(char* nombreFichero){
		
	int num_fuentes = 0;
	
	struct TFuente fuentes[TAM_MAX];
	struct TCabecera cabecera[5];
	
	int contadorturbidez = 0;
	
	int i = 0;
		
	FILE *farchivo;
	
	farchivo = fopen(nombreFichero, "r");
	
	if(farchivo == NULL){
		printf("Error en la apertura de fichero.\n");
		return -1;
	}
	
	fscanf(farchivo,"%s %s %s %s %s", cabecera[0].columna, cabecera[1].columna, cabecera[2].columna, cabecera[3].columna, cabecera[4].columna);
	
	while(fscanf(farchivo, "%s %f %d %d %d", fuentes[i].fuentes, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF){
		if(num_fuentes >= TAM_MAX){
			printf("Error, demasiadas fuentes en el fichero.\n");
			fclose(farchivo);
			return -1;
		}
		num_fuentes++;
		i++; 
	}

	
	if(num_fuentes == 0){
		printf("Error: el archivo esta vacio.\n");
	}
	
	for(i = 0; i < num_fuentes;i++) {
		if(fuentes[i].turbidez < 1){
			contadorturbidez++;
		}
	}

	fclose(farchivo);
	
	return contadorturbidez;
}

//Función Calidad turbidez
void CalidadTurbidez() {
	int opcion;
	setlocale (LC_CTYPE,"spanish");
	do{
		printf("	Introduzca la opción que desea realizar: ");
		printf("\n");
		printf("	1. Ver la media de la turbidez de los barrios.\n");
		printf("	2. Ver el número de fuentes aptas para consumo por barrio.\n");
		printf("	3. Ver el barrio con mejor calidad.\n");
		printf("	4. Salir");
		printf("\n\n");
		printf("	OPCIÓN: ");
		scanf("%d", &opcion);
	
		switch (opcion){
			case 1: 
				system("cls");
					printf("	La media de la turbidez lavapies es %f\n", calcularturbidez("Lavapies.txt"));
					printf("	La media de la turbidez de salamanca es %f\n", calcularturbidez("Salamanca.txt"));
					printf("	La media de la turbidez de chamberi es %f\n", calcularturbidez("Chamberi.txt"));
				printf("\n\n");	
				break;
				
			case 2:
				system("cls");
				printf("	Hay %d fuentes aptas para consumo en Lavapiés.\n", Contadorturbidez("Lavapies.txt"));
				printf("	Hay %d fuentes aptas para consumo en Salamanca.\n", Contadorturbidez("Salamanca.txt"));
				printf("	Hay %d fuentes aptas para consumo en Chamberí.\n", Contadorturbidez("Chamberi.txt"));
				printf("\n\n");	
				break;
				
			case 3:
				system("cls");
				if(Contadorturbidez("Lavapies.txt") > Contadorturbidez("Salamanca.txt") && Contadorturbidez("Lavapies.txt") > Contadorturbidez("Chamberi.txt")){
					printf("	El barrio con mejor turbidez es Lavapiés.\n");
				}else if (Contadorturbidez("Salamanca.txt") > Contadorturbidez("Lavapies.txt") && Contadorturbidez("Salamanca.txt") > Contadorturbidez("Chamberi.txt")){
					printf("	El barrio con mejor turbidez es Salamanca.\n");
				}else{
					printf("	El barrio con mejor turbidez es Chamberí.\n");
				}
				printf("\n\n");	
				break;
		}
	}while (opcion!=4);	
}

//Función media pH
float calcularpH(char* nombreFichero){
		
	int num_fuentes = 0;
	
	struct TFuente fuentes[TAM_MAX];
	struct TCabecera cabecera[5];
	
	float mediaph = 0.0f;
	
	int i = 0;
		
	FILE *farchivo;
	
	farchivo = fopen(nombreFichero, "r");
	
	if(farchivo == NULL){
		printf("Error en la apertura de fichero.\n");
		return -1;
	}

	fscanf(farchivo,"%s %s %s %s %s", cabecera[0].columna, cabecera[1].columna, cabecera[2].columna, cabecera[3].columna, cabecera[4].columna);
	
	while(fscanf(farchivo, "%s %f %d %d %d", fuentes[i].fuentes, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF){
		if(num_fuentes >= TAM_MAX){
			printf("Error, demasiadas fuentes en el fichero.\n");
			fclose(farchivo);
			return -1;
		}		
		num_fuentes++;
		i++; 
	}
	
	if(num_fuentes == 0){
		printf("Error: el archivo esta vacio.\n");
	}

	for(i = 0; i < num_fuentes;i++) {
		mediaph += fuentes[i].pH;
	}

	fclose(farchivo);
	
	return (mediaph/(float) 25);
}

//Función contador pH
int Contadorph(char* nombreFichero){
		
	int num_fuentes = 0;
	
	struct TFuente fuentes[TAM_MAX];
	struct TCabecera cabecera[5];
	
	int contadorph = 0;
	
	int i = 0;
		
	FILE *farchivo;
	
	farchivo = fopen(nombreFichero, "r");
	
	if(farchivo == NULL){
		printf("Error en la apertura de fichero.\n");
		return -1;
	}
	
	fscanf(farchivo,"%s %s %s %s %s", cabecera[0].columna, cabecera[1].columna, cabecera[2].columna, cabecera[3].columna, cabecera[4].columna);
	
	while(fscanf(farchivo, "%s %f %d %d %d", fuentes[i].fuentes, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF){
		if(num_fuentes >= TAM_MAX){
			printf("Error, demasiadas fuentes en el fichero.\n");
			fclose(farchivo);
			return -1;
		}
		num_fuentes++;
		i++; 
	}

	
	if(num_fuentes == 0){
		printf("Error: el archivo esta vacio.\n");
	}
	
	for(i = 0; i < num_fuentes;i++) {
		if(6.5 < fuentes[i].pH && fuentes[i].pH < 9.5){
			contadorph++;
		}
	}

	fclose(farchivo);
	
	return contadorph;
}

//Función calidad pH
void CalidadPh() {
	int opcion;
	setlocale (LC_CTYPE,"spanish");
	do{
		printf("	Introduzca la opción que desea realizar: ");
		printf("\n");
		printf("	1. Ver la media del ph de los barrios.\n");
		printf("	2. Ver el número de fuentes aptas para consumo por barrio.\n");
		printf("	3. Ver el barrio con mejor calidad.\n");
		printf("	4. Salir");
		printf("\n\n");
		printf("	OPCIÓN: ");
		scanf("%d", &opcion);
	
		switch (opcion){
			case 1: 
				system("cls");
				printf("	La media del ph de Lavapiés es %f\n", calcularpH("Lavapies.txt"));
				printf("	La media del ph de Salamanca es %f\n", calcularpH("Salamanca.txt"));
				printf("	La media del ph de Chamberí es %f\n", calcularpH("Chamberi.txt"));
				printf("\n\n");	
				break;
				
			case 2:
				system("cls");
				printf("	Hay %d fuentes aptas para consumo en Lavapiés.\n", Contadorph("Lavapies.txt"));
				printf("	Hay %d fuentes aptas para consumo en Salamanca.\n", Contadorph("Salamanca.txt"));
				printf("	Hay %d fuentes aptas para consumo en Chamberí.\n", Contadorph("Chamberi.txt"));
				printf("\n\n");	
				break;
				
			case 3:
				system("cls");
				if(Contadorph("Lavapies.txt") > Contadorph("Salamanca.txt") && Contadorph("Lavapies.txt") > Contadorph("Chamberi.txt")){
					printf("	El barrio con mejor ph es Lavapiés.\n");
				}else if (Contadorph("Salamanca.txt") > Contadorph("Lavapies.txt") && Contadorph("Salamanca.txt") > Contadorph("Chamberi.txt")){
					printf("	El barrio con mejor ph es Salamanca.\n");
				}else{
					printf("	El barrio con mejor ph es Chamberí.\n");
				}
				printf("\n\n");	
				break;
		}
	}while (opcion!=4);	
}

//Función calcular coliformes
float calcularcoliformes(char* nombreFichero){
		
	int num_fuentes = 0;
	
	struct TFuente fuentes[TAM_MAX];
	struct TCabecera cabecera[5];
	
	float mediacoliformes = 0.0f;
	
	int i = 0;
		
	FILE *farchivo;
	
	farchivo = fopen(nombreFichero, "r");
	
	if(farchivo == NULL){
		printf("Error en la apertura de fichero.\n");
		return -1;
	}
	
	fscanf(farchivo,"%s %s %s %s %s", cabecera[0].columna, cabecera[1].columna, cabecera[2].columna, cabecera[3].columna, cabecera[4].columna);
	
	while(fscanf(farchivo, "%s %f %d %d %d", fuentes[i].fuentes, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF){
		if(num_fuentes >= TAM_MAX){
			printf("Error, demasiadas fuentes en el fichero.\n");
			fclose(farchivo);
			return -1;
		}
		num_fuentes++;
		i++; 
	}

	
	if(num_fuentes == 0){
		printf("Error: el archivo esta vacio.\n");
	}
	
	for(i = 0; i < num_fuentes;i++) {
		mediacoliformes += fuentes[i].coliformes;
	}

	fclose(farchivo);
	
	return (mediacoliformes/(float) 25);
}

//Función contador coliformes
int Contadorcoliformes(char* nombreFichero){
		
	int num_fuentes = 0;
	
	struct TFuente fuentes[TAM_MAX];
	struct TCabecera cabecera[5];
	
	int contadorcoliformes = 0;
	
	int i = 0;
		
	FILE *farchivo;
	
	farchivo = fopen(nombreFichero, "r");
	
	if(farchivo == NULL){
		printf("Error en la apertura de fichero.\n");
		return -1;
	}
	
	fscanf(farchivo,"%s %s %s %s %s", cabecera[0].columna, cabecera[1].columna, cabecera[2].columna, cabecera[3].columna, cabecera[4].columna);
	
	while(fscanf(farchivo, "%s %f %d %d %d", fuentes[i].fuentes, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF){
		if(num_fuentes >= TAM_MAX){
			printf("Error, demasiadas fuentes en el fichero.\n");
			fclose(farchivo);
			return -1;
		}
		num_fuentes++;
		i++; 
	}

	
	if(num_fuentes == 0){
		printf("Error: el archivo esta vacio.\n");
	}
	
	for(i = 0; i < num_fuentes;i++) {
		if(fuentes[i].coliformes == 0){
			contadorcoliformes++;
		}
	}

	fclose(farchivo);
	
	return contadorcoliformes;
}

//Función Calidad coliformes
void CalidadColiformes() {
	int opcion;
	setlocale (LC_CTYPE,"spanish");
	do{
		printf("	Introduzca la opción que desea realizar: ");
		printf("\n");
		printf("	1. Ver la media de los coliformes de los barrios.\n");
		printf("	2. Ver el número de fuentes aptas para consumo por barrio.\n");
		printf("	3. Ver el barrio con mejor calidad.\n");
		printf("	4. Salir");
		printf("\n\n");
		printf("	OPCIÓN: ");
		scanf("%d", &opcion);
	
		switch (opcion){
			case 1: 
				system("cls");
				printf("	La media de los coliformes de Lavapiés es %f\n", calcularcoliformes("Lavapies.txt"));
				printf("	La media de los coliformes de Salamanca es %f\n", calcularcoliformes("Salamanca.txt"));
				printf("	La media de los coliformes de Chamberí es %f\n", calcularcoliformes("Chamberi.txt")); 
				printf("\n\n");	
				break;
				
			case 2:
				system("cls");
				printf("	Hay %d fuentes aptas para consumo en Lavapiés.\n", Contadorcoliformes("Lavapies.txt"));
				printf("	Hay %d fuentes aptas para consumo en Salamanca.\n", Contadorcoliformes("Salamanca.txt"));
				printf("	Hay %d fuentes aptas para consumo en Chamberí.\n", Contadorcoliformes("Chamberi.txt"));
				printf("\n\n");	
				break;
				
			case 3:
				system("cls");
				if(Contadorcoliformes("Lavapies.txt") > Contadorcoliformes("Salamanca.txt") && Contadorcoliformes("Lavapies.txt") > Contadorcoliformes("Chamberi.txt")){
					printf("	El barrio con mejor conductividad es Lavapiés.\n");
				}else if (Contadorcoliformes("Salamanca.txt") > Contadorcoliformes("Lavapies.txt") && Contadorcoliformes("Salamanca.txt") > Contadorcoliformes("Chamberi.txt")){
					printf("	El barrio con mejor conductividad es Salamanca.\n");
				}else{
					printf("	El barrio con mejor conductividad es Chamberí.\n");
				}
				printf("\n\n");	
				break;
		}
	}while (opcion!=4);	
}


//Función MenúPromedio
void menuPromedio () {

	int opcion2;
	setlocale (LC_CTYPE,"spanish");

	do {
	printf("\n\n	PROMEDIO DE PROPIEDADES DE LAS FUENTES \n\n");
	printf("	1. Calidad promedio según el ph\n");
	printf("	2. Calidad promedio según la conductividad\n");
	printf("	3. Calidad promedio según la turbidez\n");
	printf("	4. Calidad promedio según los coliformes\n");
	printf("	5. Salir\n\n");
	fflush(stdin);
	printf("	OPCIÓN: ");
	scanf("%d", &opcion2);

	switch (opcion2) {

		case 1:
			system("cls");
			LecturaFicheroInformacion("pH.txt");
			CalidadPh();
			break;
		case 2:
			system("cls");
			LecturaFicheroInformacion("Conductividad.txt");
			CalidadConductividad();
			break;
		case 3:
			system("cls");
			LecturaFicheroInformacion("Turbidez.txt");
			CalidadTurbidez();
			break;
		case 4:
			system("cls");
			LecturaFicheroInformacion("Coliformes.txt");
			CalidadColiformes();
			break;

	}

	} while(opcion2 != 5);

}

//Función MenúInicial
void MenuInicial() {
	int opcion1;
	setlocale (LC_CTYPE,"spanish");
	
	printf("\n");
	do{
		printf ("\n");
		printf("	MENÚ INICIAL\n");
		printf("	Escriba el número que representa la acción que desea realizar:\n");
    	printf("	1. Consultar datos almacenados de fuentes\n");
    	printf("	2. Promedio de propiedades de las fuentes\n");
    	printf("	3. Valoración final\n");
    	printf("	4. Salir\n\n");
		fflush(stdin);
		printf("	OPCIÓN: ");
		scanf("%d", &opcion1);

		switch(opcion1){
			case 1:
				fflush(stdin);
				system("cls");
				ImprimirFicheros ();
				break;

			case 2:
				fflush(stdin);
				system("cls");
            	menuPromedio ();
				break;
				
			case 3:
				fflush(stdin);
				system("cls");
                encuesta();
				break;
		}
	}while(opcion1 != 4);
}

void MenuOpciones (){
	
	int opcion;
	
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
				LecturaFicheroInformacion("Instrucciones.txt");
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
				VerificacionDatos();
				break;

			case 4:
				system("cls");
				MenuInicial();
				break;
		}
	}while (opcion != 5);
}

int main () {
	//Imprimir Banner
	Banner();
	//Imprimir el menu de opciones
	MenuOpciones();
	system("cls");
	printf("FIN DEL PROGRAMA\n");
	
	return 0;
}
