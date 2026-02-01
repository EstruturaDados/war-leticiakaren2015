#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct definition to store territory information
// Definição da struct para armazenar informações do território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Function to register territories
// Função para cadastrar territórios
void cadastrarTerritorios(struct Territorio *mapa, int quantidade) {
    int i;

    for (i = 0; i < quantidade; i++) {
        printf("\nTerritorio %d:\n", i + 1);

        printf("Digite o nome do territorio: ");
        scanf("%s", mapa[i].nome);

        printf("Digite a cor do exercito: ");
        scanf("%s", mapa[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// Function to display all territories
// Função para exibir todos os territórios
void exibirTerritorios(struct Territorio *mapa, int quantidade) {
    int i;

    printf("\n=== Situacao Atual dos Territorios ===\n");

    for (i = 0; i < quantidade; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do exercito: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }
}

// Function that simulates an attack between two territories
// Função que simula um ataque entre dois territórios
void atacar(struct Territorio *atacante, struct Territorio *defensor) {

    int dadoAtacante, dadoDefensor;

    // Simulating dice rolls
    // Simulando rolagem de dados
    dadoAtacante = rand() % 6 + 1;
    dadoDefensor = rand() % 6 + 1;

    printf("\nResultado dos dados:\n");
    printf("Atacante tirou: %d\n", dadoAtacante);
    printf("Defensor tirou: %d\n", dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("\nO atacante venceu a batalha!\n");

        // Transfer ownership and half troops
        // Transferir domínio e metade das tropas
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas = atacante->tropas - defensor->tropas;

    } else {
        printf("\nO defensor venceu a batalha!\n");

        // Attacker loses one troop
        // Atacante perde uma tropa
        if (atacante->tropas > 1) {
            atacante->tropas--;
        }
    }
}

// Function to free allocated memory
// Função para liberar memória alocada
void liberarMemoria(struct Territorio *mapa) {
    free(mapa);
    printf("\nMemoria liberada com sucesso!\n");
}

int main() {

    int quantidade, atacante, defensor;

    srand(time(NULL));

    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &quantidade);

    // Dynamic memory allocation for territories
    // Alocação dinâmica de memória para os territórios
    struct Territorio *mapa =
        (struct Territorio *) calloc(quantidade, sizeof(struct Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    cadastrarTerritorios(mapa, quantidade);

    exibirTerritorios(mapa, quantidade);

    printf("\n=== Sistema de Ataque ===\n");

    printf("Escolha o numero do territorio atacante: ");
    scanf("%d", &atacante);

    printf("Escolha o numero do territorio defensor: ");
    scanf("%d", &defensor);

    // Validate choices
    // Validar escolhas
    if (atacante < 1 || atacante > quantidade ||
        defensor < 1 || defensor > quantidade) {

        printf("Territorios invalidos!\n");
    }
    else if (strcmp(mapa[atacante-1].cor, mapa[defensor-1].cor) == 0) {

        printf("Nao e possivel atacar um territorio da mesma cor!\n");
    }
    else {
        atacar(&mapa[atacante-1], &mapa[defensor-1]);
    }

    exibirTerritorios(mapa, quantidade);

    liberarMemoria(mapa);

    return 0;
}
