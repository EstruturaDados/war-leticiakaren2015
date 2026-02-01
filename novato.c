#include <stdio.h>
#include <string.h>

// Struct definition to store territory data
// Definição da struct para armazenar dados do território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {

    // Declaration of an array to store 5 territories
    // Declaração de um vetor para armazenar 5 territórios
    struct Territorio territorios[5];

    int i;

    printf("=== Cadastro de Territorios ===\n\n");

    // Loop to input data for each territory
    // Laço para entrada de dados de cada território
    for(i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);

        printf("Digite o nome do territorio: ");
        scanf("%s", territorios[i].nome);

        printf("Digite a cor do exercito: ");
        scanf("%s", territorios[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Displaying all registered territories
    // Exibição de todos os territórios cadastrados
    printf("=== Territorios Cadastrados ===\n\n");

    for(i = 0; i < 5; i++) {
        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}
