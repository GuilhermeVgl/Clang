#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main (){ 

	int input; 
	FILE *pa; 
	char nome[] = "texto.txt"; 
	
	if ((pa=fopen(nome, "w+")) == NULL) 
	{
	    printf("\n\nNao foi possivel abrir o arquivo.\n");
	    exit(1);
	} 
	
	printf("Informe a quantidade de numeros a serem gerados:");
	scanf("%d", &input);
	
	srand(time(NULL));
	
	fprintf(pa, "%d\n", input);
	
	for(int contador = 0; contador < input; contador++) 
	{
		int random = rand() % 100 + 1;
		
		fprintf(pa,"%d\n", random);
		
	}

	fclose(pa);
	printf("Numeros salvos!\n");
	
	printf("Pressione Enter para sair...");
    getchar();
    getchar();
    
	return 0;
}


