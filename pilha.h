#ifndef PILHA_H
#define PILHA_H

#define MAX_TAM 100

typedef struct {
    int itens[MAX_TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p);
int empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p);
int calcularExpressao(char entrada[], Pilha *p);

#endif
