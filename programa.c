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
	
	return 0; 
}
