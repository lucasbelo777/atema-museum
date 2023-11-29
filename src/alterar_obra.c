#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char tema[50], obra_1[255], obra_2[255], obra_3[255], descricao_1[255], descricao_2[255], descricao_3[255];
} Registro;

void mostrarInformacoes(Registro registro) {
    printf("*************************");
    printf("\nID: %d\n", registro.id);
    printf("Tema: %s\n", registro.tema);
    printf("Obra_1: %s\n", registro.obra_1);
    printf("Obra_2: %s\n", registro.obra_2);
    printf("Obra_3: %s\n", registro.obra_3);
    printf("Descricao_1: %s\n", registro.descricao_1);
    printf("Descricao_2: %s\n", registro.descricao_2);
    printf("Descricao_3: %s\n", registro.descricao_3);
    printf("*************************\n\n");
}

void alterarCampo(Registro *registro, int opcao) {
    switch (opcao) {
        case 1:
            printf("Digite o novo tema: ");
            scanf(" %[^\n]s", registro->tema);
            break;
        case 2:
            printf("Digite a nova obra_1: ");
            scanf(" %[^\n]s", registro->obra_1);
            break;
        case 3:
            printf("Digite a nova obra_2: ");
            scanf(" %[^\n]s", registro->obra_2);
            break;
        case 4:
            printf("Digite a nova obra_3: ");
            scanf(" %[^\n]s", registro->obra_3);
            break;
        case 5:
            printf("Digite a nova descricao_1: ");
            scanf(" %[^\n]s", registro->descricao_1);
            break;
        case 6:
            printf("Digite a nova descricao_2: ");
            scanf(" %[^\n]s", registro->descricao_2);
            break;
        case 7:
            printf("Digite a nova descricao_3: ");
            scanf(" %[^\n]s", registro->descricao_3);
            break;
        default:
            printf("Opcao invalida.\n");
    }
}

void alterarRegistro(FILE *arquivo, int id_busca) {
    Registro registro;
    int encontrou = 0;
    char continuar;

    // Volta para o início do arquivo
    rewind(arquivo);

    while (fread(&registro, sizeof(Registro), 1, arquivo)) {
        if (registro.id == id_busca) {
            encontrou = 1;

            // Mostra as informações do registro antes de oferecer as opções de alteração
            printf("Informacoes do registro com ID %d:\n", id_busca);
            mostrarInformacoes(registro);

            do {
                // Mostra os campos disponíveis para alteração
                printf("Escolha o campo que deseja alterar:\n");
                printf("1. Tema\n2. Obra_1\n3. Obra_2\n4. Obra_3\n5. Descricao_1\n6. Descricao_2\n7. Descricao_3\n");

                int opcao;
                scanf("%d", &opcao);

                // Chama a função para alterar o campo escolhido
                alterarCampo(&registro, opcao);

                printf("Deseja alterar mais algum campo? (S/N): ");
                scanf(" %c", &continuar);
            } while (continuar == 'S' || continuar == 's');

            // Volta para a posição do arquivo para escrever as alterações
            fseek(arquivo, -(long)sizeof(Registro), SEEK_CUR);
            fwrite(&registro, sizeof(Registro), 1, arquivo);
            printf("Registro alterado com sucesso!\n");
            break; // Finaliza o loop
        }
    }

    if (encontrou == 0) {
        printf("Nao ha registro com o valor pesquisado.\n");
    }
}

int main() {
    FILE *arquivo;
    int id_busca;

    arquivo = fopen("dadosobras.bin", "rb+");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Digite o ID para pesquisa: ");
    scanf("%d", &id_busca);

    alterarRegistro(arquivo, id_busca);

    fclose(arquivo);

    return 0;
}
