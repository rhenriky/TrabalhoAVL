// ArvoreAVL.h

#ifndef ARVOREAVL_H
#define ARVOREAVL_H

typedef struct NoAVL {
    int valor;
    struct NoAVL* esquerdo;
    struct NoAVL* direito;
    int altura;
} NoAVL;

typedef struct {
    NoAVL* raiz;
} ArvoreAVL;

ArvoreAVL* criarArvoreAVL();
void destruirArvoreAVL(ArvoreAVL* arvore);   // Já existente, agora também para destruir a árvore inteira
void destruirNoAVL(NoAVL* no);               // Nova função para destruir um nó específico
void inserirAVL(ArvoreAVL* arvore, int valor);
void removerAVL(ArvoreAVL* arvore, int valor);
void emOrdemAVL(NoAVL* no);
void preOrdemAVL(NoAVL* no);
int profundidadeAVL(NoAVL* no);
void imprimirArvore(NoAVL* no, int espaco);

#endif