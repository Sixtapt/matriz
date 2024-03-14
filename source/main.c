/**
 * @file main.c
 * @author Marco Silva Alves (a23036@alunos.ipca.pt)
 * @brief Main do programa
 * @version 0.1
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

/**
 * @brief Função principal do programa.
 * 
 * @return Retorna 0 se o programa for executado com sucesso, caso contrário, retorna um valor diferente de zero.
 */
int main() {
    Node* head = NULL;
    int num, rows = 0, cols[100] = {0}; // Supondo que o número máximo de linhas é 100

    FILE* file = fopen("matrix.txt", "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    // Lendo os valores do arquivo e inserindo na lista
    while (fscanf(file, "%d;", &num) == 1) {
        insertEnd(&head, num);
        cols[rows]++; // Incrementa o número de colunas para a linha atual
        if (fgetc(file) == '\n') {
            rows++; // Passa para a próxima linha
        }
    }

    fclose(file);

    // Imprimindo a matriz tabular
    printMatrix(head, rows + 1, cols);

    // Alterando o número em uma posição específica
    alterNumber(head, rows + 1, cols, 0, 0, 100); // Altera o número na posição (1, 1) para 100

    // Imprimindo a matriz tabular após a alteração
    printf("\nMatriz após alteração:\n");
    printMatrix(head, rows + 1, cols);

    // Liberando a memória alocada para a lista
    freeList(head);

    return 0;
}
