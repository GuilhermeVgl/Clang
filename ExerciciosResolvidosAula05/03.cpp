#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define MAX 30

int main(){
	FILE *p;
	char str[MAX];
	char caractereProcurado;
	char caractereAtual;
	int contador;
	
	printf("Entre com um nome para o arquivo:\n");
	fgets(str,29,stdin);
		for(int i=0; str[i]; i++) //Elimina o \n da string lida
       	if(str[i]=='\n')
			str[i]='\0';
	
	
	if (!(p = fopen(str,"r"))) {		
       	printf("Erro! \n");
       	exit(1); 
    }
	
	printf("Entre com o caractere a ser procurado:");
	scanf("%c", &caractereProcurado);

    while ((caractereAtual = fgetc(p)) != EOF)
    {
    	if(caractereAtual == caractereProcurado)
		{
			contador++;	
		}
	}
	printf("O caractere solicitado aparece: %d", contador);
	printf(" vezes no arquivo!\n");
	
	fclose(p);
    
    return(0);
}
			



