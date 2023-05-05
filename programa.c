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

//Funciones

//Función banner
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
		contadorestudiante++;
		encontrado = 1;
	} else if(strcmp(usuario[i].profesion, "profesor") == 0){
		contadorprofesor++;
		encontrado = 1;
	}else if(strcmp(usuario[i].profesion, "ciudadano") == 0){
		contadorciudadano++;
		encontrado = 1;
	}else{
		printf("	No ha seleccionado nunguna opción correcta vuelva a intentarlo.\n");
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

//Función para imprimir datos del fichero del inicio de sesion (Revisar)

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
	//struct TCabecera cabecera;
	
	FILE *flavapies, *fchamberi, *fsalamanca;
	
	//Importante o habría que usar el punto como separador decimal.
	setlocale(LC_ALL, "spanish"); 

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
	  		 printf("%s\t\t %.2f\t\t\t %d\t\t %d\t\t %d\n", fuentes[num_fuentes].fuentes, fuentes[num_fuentes].pH, fuentes[num_fuentes].conductividad, fuentes[num_fuentes].turbidez, fuentes[num_fuentes].coliformes);
	  		 if (++num_fuentes >= TAM_MAX){
        		printf("Error: demasiadas fuentes en el fichero\n");
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
	  		 printf("%s\t %.2f\t\t %d\t\t %d\t\t %d\n", fuentes[num_fuentes].fuentes, fuentes[num_fuentes].pH, fuentes[num_fuentes].conductividad, fuentes[num_fuentes].turbidez, fuentes[num_fuentes].coliformes);
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

//Función lectura de fichero
int Instrucciones(){
    FILE *pinstrucciones;
    pinstrucciones = fopen("Instrucciones.txt", "r");
    char lineainstrucciones[80];
    if(pinstrucciones == NULL){
       printf("	Error en la apertura del fichero\n");
       return -1;
    }

    char c;

    while(((c = fgetc(pinstrucciones))) != EOF) {
        printf("%c", c);
    }
    printf("\n\n");
    return 0;
}

//Función verificación de datos
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

//Función pH
int pH() {
	int contadorsalamanca, contadorlavapies, contadorchamberi;
	
	char linea[100];
	
	int num_fuentes = 0;
	
	struct TFuente fuentes[TAM_MAX];
	
	FILE *flavapies, *fsalamanca, *fchamberi;
	
		flavapies = fopen("Lavapies.txt", "r");
		if(flavapies == NULL) {
			printf("Error en la apertura de salida.\n");
			return -1;
		}
	
   		while (fscanf(flavapies, "%s %f %d %d %d", fuentes[num_fuentes].fuentes, &fuentes[num_fuentes].pH, &fuentes[num_fuentes].conductividad, &fuentes[num_fuentes].turbidez, &fuentes[num_fuentes].coliformes) != EOF) {
	  		 if (num_fuentes >= TAM_MAX){
        		printf("Error: demasiadas fuentes en el fichero\n");
        		break;
			}
			if(6.5<= fuentes[num_fuentes].pH <= 9.5){
				contadorlavapies++;
			}
   		 }
    
    	if(num_fuentes == 0){
    		printf("Error: archivo vacio\n");
		} 
		fclose (flavapies);
		

		fchamberi = fopen("Chamberi.txt", "r");
		if(fchamberi == NULL) {
			printf("Error en la apertura de salida.\n");
			return -1;
		}
	
	
   		while (fscanf(fchamberi, "%s %f %d %d %d", fuentes[num_fuentes].fuentes, &fuentes[num_fuentes].pH, &fuentes[num_fuentes].conductividad, &fuentes[num_fuentes].turbidez, &fuentes[num_fuentes].coliformes) != EOF) {
	  		 if (num_fuentes >= TAM_MAX){
        		printf("Error: demasiadas fuentes en el fichero\n");
        		break;
			}
			if(6.5<= fuentes[num_fuentes].pH <= 9.5){
				contadorchamberi++;
			}
   		 }
    
    	if(num_fuentes == 0){
    		printf("Error: archivo vacio\n");
		} 
		fclose (fchamberi);
		
		fsalamanca = fopen("Salamanca.txt", "r");
		if(fsalamanca == NULL) {
			printf("Error en la apertura de salida.\n");
			return -1;
		}
	
   		while (fscanf(fsalamanca, "%s %f %d %d %d", fuentes[num_fuentes].fuentes, &fuentes[num_fuentes].pH, &fuentes[num_fuentes].conductividad, &fuentes[num_fuentes].turbidez, &fuentes[num_fuentes].coliformes) != EOF) {
	  		 if (num_fuentes >= TAM_MAX){
        		printf("Error: demasiadas fuentes en el fichero\n");
        		break;
			}
			if(6.5<= fuentes[num_fuentes].pH <= 9.5){
				contadorsalamanca++;
			}
   		 }
    
    	if(num_fuentes == 0){
    		printf("Error: archivo vacio\n");
		} 
		fclose (fsalamanca);

	if (contadorsalamanca > contadorlavapies && contadorsalamanca > contadorchamberi){
		printf("El barrio con mejor pH es el barrio Salamanca.\n");
	}else if (contadorlavapies > contadorsalamanca && contadorlavapies > contadorchamberi){
		printf("El barrio con mejor pH es el barrio de Lavapies.\n");
	}else {
		printf("El barrio con mejor pH es el barrio de Chamberi.\n");
	}

	return 0;
}

//Funcion promedio 
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
	printf("La respuesta de estas preguntas nos permite hacer un seguimiento de la aplicación para mejor la experiencia de los usuarios\n\n");
	
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

int main () {
	//Declaración de variables
	int i, opcion, opcion1, opcion2;
	//char respuesta;
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
				VerificacionDatos();
				break;
			
			case 4:
				system("cls");
				do{
					printf ("\n");
					printf("	MENÚ INICIAL\n");
					printf("	Escriba el número que representa la acción que desea realizar:\n");
    				printf("	1. Consultar datos almacenados de fuentes\n");
    				printf("	2. Promedio de propiedades de las fuentes\n");
    				printf("	3. Motivos de utilización\n");
    				printf("	4. Valoración final\n");
    				printf("	5. Salir\n\n");
					fflush(stdin);
					printf("	OPCIÓN: ");
					scanf("%d", &opcion1);
		
					switch(opcion1){
						case 1:
							fflush(stdin);
							system("cls");
							ImprimirFicheros ();
							//función leer ficheros por barrio 
							break;
				
						case 2:
							fflush(stdin);
							system("cls");
            				//función promedio o media de las propiedades segun el barrio 
							break;
			
						case 3: 
							fflush(stdin);
							system("cls");
							//Motivo de la utilización de la aplicación con porcetajes y opciones 
							break;
			
						case 4:
                            encuesta();
							break; 
						}
					}while(opcion1 != 5);
		}
	}while (opcion != 5);

	system("cls");
	printf("FIN DEL PROGRAMA\n");
	
	return 0; 
}
