#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TMN_MAX 100

int main() {
    
    char *linha = (char *)malloc(TMN_MAX * sizeof(char));
    int final = 0;

    while (final == 0 && fgets(linha, TMN_MAX, stdin) != NULL) {
        
        linha[strcspn(linha, "\n")] = '\0';

        if (strcmp(linha, "the end!") == 0) final = 1;
        
        else {
            for (int i = 0; linha[i] != '\0'; ++i) {
                linha[i] = toupper(linha[i]);
            }

            printf("%s\n", linha);
        }
    }

    free(linha);
    return 0;
}
