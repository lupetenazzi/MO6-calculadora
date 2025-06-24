#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main() {
    Pilha pilha;
    char expressao[MAX_TAM];

    inicializar(&pilha);

    printf("Digite a expressão RPN: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    int resultado = calcularExpressao(expressao, &pilha);
    printf("Resultado: %d\n", resultado);

    return 0;
}
