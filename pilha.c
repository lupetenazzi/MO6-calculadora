#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializar(Pilha *p) {
    p->topo = -1;
}

int empilhar(Pilha *p, int valor) {
    if (p->topo >= MAX_TAM - 1) return -1;
    p->itens[++(p->topo)] = valor;
    return 0;
}

int desempilhar(Pilha *p) {
    if (p->topo < 0) return 0;
    return p->itens[(p->topo)--];
}

int calcularExpressao(char entrada[], Pilha *p) {
    char *token = strtok(entrada, " ");
    while (token != NULL) {
        if (strlen(token) == 1 && strchr("+-*/", token[0])) {
            int n2 = desempilhar(p);
            int n1 = desempilhar(p);
            int resultado;
            switch (token[0]) {
                case '+': resultado = n1 + n2; break;
                case '-': resultado = n1 - n2; break;
                case '*': resultado = n1 * n2; break;
                case '/': resultado = n1 / n2; break;
            }
            empilhar(p, resultado);
        } else {
            empilhar(p, atoi(token));
        }
        token = strtok(NULL, " ");
    }
    return desempilhar(p);
}
