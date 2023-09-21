#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int calcularMenorElemento(int vetor[], int t) {
    int menor = vetor[0];
    for (int i = 1; i < t; i++) 
	{
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

float calcularMedia(int vetor[], int t) {
    float soma = 0;
    float media;
    for (int i = 0; i < t; i++) 
	{
        soma = soma + vetor[i];
    }
    media = soma / t;
    return media;
}

int main (){ 

	FILE *arquivo = fopen("texto.txt", "r"); 
	char nome[] = "texto.txt"; 
	int quantidadeDeNumeros = 0;
	int numeros[100];
	int numero;
	int i = 0;
	
	if (arquivo == NULL) {
	    printf("\n\nNao foi possivel abrir o arquivo.\n");
	    exit(1);
	} 

	while(fscanf(arquivo, "%d", &numero) != EOF)
	{
		numeros[quantidadeDeNumeros] = numero;
		quantidadeDeNumeros++;
	}

	fclose(arquivo);
	
	printf("Numeros lidos:");
	
	for (int cont = 0; cont < quantidadeDeNumeros; cont++) {
        printf("%d\n", numeros[cont]);
    }
    
    int menorElemento = calcularMenorElemento(numeros, quantidadeDeNumeros);
    double media = calcularMedia(numeros, quantidadeDeNumeros);
    
    printf("Menor valor: %d\n", menorElemento);
	
	printf("Media: %lf\n", media);
	
	printf("Pressione Enter para sair...");
    getchar();
    getchar();
    
	return 0;
}


