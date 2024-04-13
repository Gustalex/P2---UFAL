#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMN_MAX 200

void inverter() {   

    char *linha = (char *)malloc(TMN_MAX * sizeof(char));

    if (fgets(linha, TMN_MAX, stdin)) {
        linha[strcspn(linha, "\n")] = '\n';
        inverter();
        printf("%s", linha);
    }

    free(linha); 
}

int main() {
    inverter();
    return 0;
}
