// ArvoreAVL.c

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

static int altura(NoAVL* no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static NoAVL* criarNoAVL(int valor) {
    NoAVL* no = (NoAVL*)malloc(sizeof(NoAVL));
    no->valor = valor;
    no->esquerdo = no->direito = NULL;
    no->altura = 1;  // Novo nó é inicialmente adicionado como folha
    return no;
}

static NoAVL* rotacaoDireita(NoAVL* y) {
    NoAVL* x = y->esquerdo;
    NoAVL* T2 = x->direito;

    // Rotaciona para a direita
    x->direito = y;
    y->esquerdo = T2;

    // Atualiza as alturas
    y->altura = max(altura(y->esquerdo), altura(y->direito)) + 1;
    x->altura = max(altura(x->esquerdo), altura(x->direito)) + 1;

    // Retorna nova raiz
    return x;
}

static NoAVL* rotacaoEsquerda(NoAVL* x) {
    NoAVL* y = x->direito;
    NoAVL* T2 = y->esquerdo;

    // Rotaciona para a esquerda
    y->esquerdo = x;
    x->direito = T2;

    // Atualiza as alturas
    x->altura = max(altura(x->esquerdo), altura(x->direito)) + 1;
    y->altura = max(altura(y->esquerdo), altura(y->direito)) + 1;

    // Retorna nova raiz
    return y;
}

static int obterBalanceamento(NoAVL* no) {
    if (no == NULL)
        return 0;
    return altura(no->esquerdo) - altura(no->direito);
}

static NoAVL* inserirNoAVL(NoAVL* no, int valor) {
    // 1. Inserir normalmente na árvore de busca binária
    if (no == NULL)
        return criarNoAVL(valor);

    if (valor < no->valor)
        no->esquerdo = inserirNoAVL(no->esquerdo, valor);
    else if (valor > no->valor)
        no->direito = inserirNoAVL(no->direito, valor);
    else  // Não permitimos valores duplicados
        return no;

    // 2. Atualizar a altura deste ancestral
    no->altura = 1 + max(altura(no->esquerdo), altura(no->direito));

    // 3. Obter o fator de balanceamento deste ancestral
    int balanceamento = obterBalanceamento(no);

    // 4. Verificar os casos de desbalanceamento e aplicar as rotações

    // Caso 1: Esquerda-Esquerda
    if (balanceamento > 1 && valor < no->esquerdo->valor)
        return rotacaoDireita(no);

    // Caso 2: Direita-Direita
    if (balanceamento < -1 && valor > no->direito->valor)
        return rotacaoEsquerda(no);

    // Caso 3: Esquerda-Direita
    if (balanceamento > 1 && valor > no->esquerdo->valor) {
        no->esquerdo = rotacaoEsquerda(no->esquerdo);
        return rotacaoDireita(no);
    }

    // Caso 4: Direita-Esquerda
    if (balanceamento < -1 && valor < no->direito->valor) {
        no->direito = rotacaoDireita(no->direito);
        return rotacaoEsquerda(no);
    }

    // Retorna o ponteiro do nó (inalterado)
    return no;
}

void inserirAVL(ArvoreAVL* arvore, int valor) {
    arvore->raiz = inserirNoAVL(arvore->raiz, valor);
}

static NoAVL* noMinimo(NoAVL* no) {
    NoAVL* atual = no;

    while (atual->esquerdo != NULL)
        atual = atual->esquerdo;

    return atual;
}

static NoAVL* removerNoAVL(NoAVL* raiz, int valor) {
    // 1. Perform standard BST delete
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor)
        raiz->esquerdo = removerNoAVL(raiz->esquerdo, valor);
    else if (valor > raiz->valor)
        raiz->direito = removerNoAVL(raiz->direito, valor);
    else {
        if ((raiz->esquerdo == NULL) || (raiz->direito == NULL)) {
            NoAVL* temp = raiz->esquerdo ? raiz->esquerdo : raiz->direito;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;
            free(temp);
        } else {
            NoAVL* temp = noMinimo(raiz->direito);
            raiz->valor = temp->valor;
            raiz->direito = removerNoAVL(raiz->direito, temp->valor);
        }
    }

    if (raiz == NULL)
        return raiz;

    raiz->altura = 1 + max(altura(raiz->esquerdo), altura(raiz->direito));

    int balanceamento = obterBalanceamento(raiz);

    if (balanceamento > 1 && obterBalanceamento(raiz->esquerdo) >= 0)
        return rotacaoDireita(raiz);

    if (balanceamento > 1 && obterBalanceamento(raiz->esquerdo) < 0) {
        raiz->esquerdo = rotacaoEsquerda(raiz->esquerdo);
        return rotacaoDireita(raiz);
    }

    if (balanceamento < -1 && obterBalanceamento(raiz->direito) <= 0)
        return rotacaoEsquerda(raiz);

    if (balanceamento < -1 && obterBalanceamento(raiz->direito) > 0) {
        raiz->direito = rotacaoDireita(raiz->direito);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void removerAVL(ArvoreAVL* arvore, int valor) {
    arvore->raiz = removerNoAVL(arvore->raiz, valor);
}

void emOrdemAVL(NoAVL* no) {
    if (no != NULL) {
        emOrdemAVL(no->esquerdo);
        printf("%d ", no->valor);
        emOrdemAVL(no->direito);
    }
}

void preOrdemAVL(NoAVL* no) {
    if (no != NULL) {
        printf("%d ", no->valor);
        preOrdemAVL(no->esquerdo);
        preOrdemAVL(no->direito);
    }
}

ArvoreAVL* criarArvoreAVL() {
    ArvoreAVL* arvore = (ArvoreAVL*)malloc(sizeof(ArvoreAVL));
    arvore->raiz = NULL;
    return arvore;
}

void destruirNoAVL(NoAVL* no) {
    if (no != NULL) {
        destruirNoAVL(no->esquerdo);
        destruirNoAVL(no->direito);
        free(no);
    }
}

void destruirArvoreAVL(ArvoreAVL* arvore) {
    destruirNoAVL(arvore->raiz);
    free(arvore);
}

int profundidadeAVL(NoAVL* no) {
    if (no == NULL)
        return 0;

    int profundidadeEsquerda = profundidadeAVL(no->esquerdo);
    int profundidadeDireita = profundidadeAVL(no->direito);

    return 1 + (profundidadeEsquerda > profundidadeDireita ? profundidadeEsquerda : profundidadeDireita);
}

void imprimirArvore(NoAVL* no, int espaco) {
    if (no == NULL)
        return;

    espaco += 5;

    imprimirArvore(no->direito, espaco);

    printf("\n");
    for (int i = 5; i < espaco; i++)
        printf(" ");
    printf("%d\n", no->valor);

    imprimirArvore(no->esquerdo, espaco);
}
