/**
 * @file matrix_operations.c
 * @author Marco Alves (a23036@alunos.ipca.pt)
 * @brief Implementação de funções para manipulação de uma matriz representada por uma lista ligada.
 * @version 0.1
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "matrix_operations.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Cria um novo nó para a lista ligada.
 * 
 * Esta função aloca memória para um novo nó da lista ligada e o inicializa com o valor fornecido.
 * 
 * @param data O valor a ser armazenado no novo nó.
 * @return Um ponteiro para o novo nó criado.
 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para um novo nó.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no final da lista
void insertEnd(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}
/**
 * @brief Imprime os elementos da lista em formato tabular, simulando uma matriz.
 * 
 * @param head O ponteiro para o primeiro nó da lista.
 * @param rows O número de linhas da "matriz".
 * @param cols Um array contendo o número de colunas em cada linha.
 */
void printMatrix(Node* head, int rows, int cols[]) {
    Node* current = head;
    int row, col;

    printf("Valores da matriz:\n");
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols[row]; col++) {
            printf("%d\t", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
/**
 * @brief Altera o número em uma posição específica da "matriz".
 * 
 * @param head O ponteiro para o primeiro nó da lista.
 * @param rows O número de linhas da "matriz".
 * @param cols Um array contendo o número de colunas em cada linha.
 * @param rowIndex O índice da linha onde o valor deve ser alterado.
 * @param colIndex O índice da coluna onde o valor deve ser alterado.
 * @param newValue O novo valor a ser atribuído à posição especificada.
 */


// Função para alterar o número em uma posição específica da matriz
void alterNumber(Node* head, int rows, int cols[], int rowIndex, int colIndex, int newValue) {
    Node* current = head;
    int row, col;
    int count = 0;

    for (row = 0; row < rowIndex; row++) {
        count += cols[row];
    }
    count += colIndex;

    // Percorre a lista até o nó correspondente à posição desejada
    for (int i = 0; i < count; i++) {
        if (current == NULL) {
            printf("Posição inválida.\n");
            return;
        }
        current = current->next;
    }

    // Altera o valor do nó correspondente
    if (current != NULL)
        current->data = newValue;
    else
        printf("Posição inválida.\n");
}
/**
 * @brief Libera a memória alocada para a lista ligada.
 * 
 * @param head O ponteiro para o primeiro nó da lista.
 */
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
