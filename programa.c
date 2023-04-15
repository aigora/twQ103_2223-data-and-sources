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
	printf("    |____________|\n"); color(hConsole, 1);
	printf("          ||   \n"); color(hConsole, 1);
	printf("          ||\n"); color (hConsole, 1);
	printf("   _______||_______\n"); color(hConsole, 1);
	printf("  |                |\n"); color(hConsole, 1);
	printf("  |                |\n"); color(hConsole, 1);
	printf("  |________________|\n"); color(hConsole, 1);
	
	color (hConsole, 15);
	
	return;
}

int main () {
	//Imprimir Banner
	Banner();
	
	//Podemos poner tildes
	setlocale (LC_CTYPE,"spanish");
	
	return 0; 
}
