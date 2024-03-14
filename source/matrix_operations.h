#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

// Estrutura para um nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/**
 * @brief Insere um nó no final da lista.
 * 
 * Esta função insere um novo nó contendo o dado fornecido no final da lista ligada.
 * 
 * @param headRef O endereço do ponteiro para o primeiro nó da lista.
 * @param data O dado a ser armazenado no novo nó.
 */

// Função para inserir um nó no final da lista
void insertEnd(Node** headRef, int data);
/**
 * @brief Imprime os elementos da lista em formato tabular, simulando uma matriz.
 * 
 * Esta função imprime os elementos da lista como uma matriz, usando o número de linhas e colunas especificado.
 * 
 * @param head O ponteiro para o primeiro nó da lista.
 * @param rows O número de linhas da matriz.
 * @param cols Um array contendo o número de colunas em cada linha.
 */

// Função para imprimir os elementos da lista em formato tabular
void printMatrix(Node* head, int rows, int cols[]);
/**
 * @brief Altera o número em uma posição específica da matriz.
 * 
 * Esta função altera o valor em uma posição específica da matriz representada pela lista ligada.
 * 
 * @param head O ponteiro para o primeiro nó da lista.
 * @param rows O número de linhas da matriz.
 * @param cols Um array contendo o número de colunas em cada linha.
 * @param rowIndex O índice da linha onde o valor deve ser alterado.
 * @param colIndex O índice da coluna onde o valor deve ser alterado.
 * @param newValue O novo valor a ser atribuído à posição especificada.
 */

// Função para alterar o número em uma posição específica da matriz
void alterNumber(Node* head, int rows, int cols[], int rowIndex, int colIndex, int newValue);

/**
 * @brief Libera a memória alocada para a lista ligada.
 * 
 * Esta função libera a memória alocada para todos os nós da lista ligada.
 * 
 * @param head O ponteiro para o primeiro nó da lista.
 */
// Função para liberar a memória alocada para a lista
void freeList(Node* head);

#endif /* MATRIX_OPERATIONS_H */