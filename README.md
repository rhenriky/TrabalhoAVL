
# Estrutura de Dados 2

**Repositório: dados2**

---

## Projeto: Implementação de uma Árvore AVL em C

**Alunos:** João Carlos, Rodrigo Henrique

---

### Descrição

Este projeto implementa uma árvore AVL em C, que é uma árvore binária de busca auto-balanceada. A árvore AVL ajusta automaticamente a altura após inserções e remoções, garantindo que a diferença de altura entre as subárvores esquerda e direita de qualquer nó não seja superior a 1. Isso garante operações de busca, inserção e remoção eficientes, com complexidade de tempo O(log n).

### Estrutura do Projeto

- **`ArvoreAVL.h`**: Arquivo de cabeçalho que define as estruturas e funções principais para a árvore AVL.
- **`ArvoreAVL.c`**: Implementação das funções da árvore AVL, incluindo inserção, remoção, rotações (para balanceamento), e travessias.
- **`ArvoreAVLTest.c`**: Código de teste que permite a inserção e remoção de valores na árvore AVL, além de exibir a árvore em diferentes ordens (in-order, pre-order) e calcular a profundidade.
- **`Makefile`**: Arquivo Make para compilar e executar o projeto.

### Funcionalidades

1. **Inserção (`inserirAVL`)**: Insere um novo nó na árvore AVL e aplica as rotações necessárias para manter a árvore balanceada.
2. **Remoção (`removerAVL`)**: Remove um nó da árvore AVL, ajustando a estrutura da árvore para manter o balanceamento.
3. **Travessias (`emOrdemAVL`, `preOrdemAVL`)**: Funções para percorrer a árvore em diferentes ordens (in-order, pre-order).
4. **Impressão Gráfica (`imprimirArvore`)**: Função para exibir a árvore de maneira gráfica no terminal.
5. **Cálculo da Profundidade (`profundidadeAVL`)**: Calcula a profundidade máxima da árvore.

### Estrutura do Código de Teste

O código de teste (`ArvoreAVLTest.c`) permite ao usuário interagir com a árvore AVL através de um menu, com as seguintes opções:

1. **Inserir valor**: Insere um valor na árvore AVL.
2. **Remover valor**: Remove um valor da árvore AVL.
3. **Exibir a árvore (in-order)**: Exibe a árvore em ordem simétrica.
4. **Exibir a árvore (pre-order)**: Exibe a árvore em pré-ordem.
5. **Calcular profundidade da árvore**: Exibe a profundidade máxima da árvore AVL.
6. **Imprimir árvore graficamente**: Exibe a árvore de forma gráfica no terminal.
7. **Sair**: Encerra o programa.

### Configuração e Execução

#### Requisitos

- GCC (GNU Compiler Collection) ou outro compilador C compatível.

#### Compilação

Para compilar o programa, use o seguinte comando:

```sh
gcc ArvoreAVL.c ArvoreAVLTest.c -o arvore_avl
```

#### Execução

Para executar o programa, use o seguinte comando:

```sh
./arvore_avl   # No Linux/Mac
arvore_avl.exe # No Windows
```

### Exemplo de Uso

Ao executar o programa, o usuário pode interagir com o menu para inserir ou remover valores, visualizar a árvore em diferentes ordens, calcular a profundidade, e imprimir a árvore graficamente.

### Observações

- **Complexidade**: As operações de inserção, remoção e busca na árvore AVL têm complexidade O(log n), devido ao balanceamento automático da árvore.
- **Limitações**: Este exemplo não trata de valores duplicados; valores duplicados não são permitidos na árvore AVL.

/ ArvoreAVLTest.c

#include <stdio.h>
#include "ArvoreAVL.h"

void mostrarMenu() {
    printf("\nMenu:\n");
    printf("1. Inserir valor\n");
    printf("2. Remover valor\n");
    printf("3. Exibir a árvore (in-order)\n");
    printf("4. Exibir a árvore (pre-order)\n");
    printf("5. Calcular profundidade da árvore\n");
    printf("6. Imprimir árvore graficamente\n");
    printf("7. Destruir a árvore inteira\n"); 
    printf("8. Destruir um nó específico\n");  
    printf("9. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    ArvoreAVL* arvore = criarArvoreAVL();
    int opcao, valor;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserirAVL(arvore, valor);
                printf("Valor %d inserido na árvore AVL.\n", valor);
                break;

            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerAVL(arvore, valor);
                printf("Valor %d removido da árvore AVL.\n", valor);
                break;

            case 3:
                printf("Exibindo árvore (in-order): ");
                emOrdemAVL(arvore->raiz);
                printf("\n");
                break;

            case 4:
                printf("Exibindo árvore (pre-order): ");
                preOrdemAVL(arvore->raiz);
                printf("\n");
                break;

            case 5:
                printf("Profundidade da árvore: %d\n", profundidadeAVL(arvore->raiz));
                break;

            case 6:
                printf("Imprimindo árvore graficamente:\n");
                imprimirArvore(arvore->raiz, 0);
                break;

            case 7:
                destruirArvoreAVL(arvore);
                printf("Árvore inteira destruída.\n");
                arvore = criarArvoreAVL();  // Recria a árvore vazia após destruição
                break;

            case 8:
                printf("Digite o valor do nó a ser destruído: ");
                scanf("%d", &valor);
                removerAVL(arvore, valor);
                printf("Nó %d e seus descendentes destruídos.\n", valor);
                break;

            case 9:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 9);

    destruirArvoreAVL(arvore);  // Garante que a árvore seja destruída antes de sair
    return 0;
}

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


---
