#include <stdio.h>
#include <stdlib.h>
#define MAX 40

bool vogal(char c) {
    char vogais[] = {'a', 'A', 'á', 'Á', 'à', 'À', 'ã', 'Ã', 'â', 'Â',
                     'e', 'E', 'é', 'É', 'è', 'È', 'ê', 'Ê',
                     'i', 'I', 'í', 'Í', 'ì', 'Ì', 'î', 'Î',
                     'o', 'O', 'ó', 'Ó', 'ò', 'Ò', 'õ', 'Õ', 'ô', 'Ô', 'ö', 'Ö',
                     'u', 'U', 'ú', 'Ú', 'ù', 'Ù', 'û', 'Û', 'ü', 'Ü'};
    
    for (int i = 0; i < sizeof(vogais); i++) 
	{
        if (c == vogais[i]) 
		{
            return true;
        }
    }
    
    return false;
}

int main() {
    FILE *arquivoOriginal, *arquivoCopia;
	char str[MAX], str2[MAX];
    char c;

    printf("Arquivo original: ");
    scanf("%s", str);

    arquivoOriginal = fopen(str, "r");
    
    if (arquivoOriginal == NULL) 
	{
        printf("Erro!\n");
        return 1;
    }
    
    printf("Arquivo copia: ");
    scanf("%s", str2);

    arquivoCopia = fopen(str2, "w");
    
    if (arquivoCopia == NULL) 
	{
        printf("Erro!\n");
        return 1;
    }

    while ((c = fgetc(arquivoOriginal)) != EOF) 
	{
        if (vogal(c)) {
            fputc('*', arquivoCopia);
        } else {
            fputc(c, arquivoCopia);
        }
    }

    fclose(arquivoOriginal);
    fclose(arquivoCopia);

    printf("Arquivo gerado!");

    return 0;
}



