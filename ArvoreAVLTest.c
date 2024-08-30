// ArvoreAVLTest.c

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