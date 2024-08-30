
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

---
