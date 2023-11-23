#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char tema[50], obra_1[255], obra_2[255], obra_3[255], descricao_1[255], descricao_2[255], descricao_3[255];
} Registro;

void excluirObra(int id);

int main() {
    int id_exclusao;


    printf("====================\n");
    printf("EXCLUSAO DE OBRA\n");
    printf("====================\n\n");
    printf("Digite o ID da obra a ser excluida: ");
    scanf("%d", &id_exclusao);

    excluirObra(id_exclusao);

    return 0;
}

void exibirObra(Registro registro) {
    printf("Tema: %s\n", registro.tema);
    printf("Obra 1: %s\n", registro.obra_1);
    printf("Obra 2: %s\n", registro.obra_2);
    printf("Obra 3: %s\n", registro.obra_3);
}

void excluirObra(int id) {
    FILE *tempFile;
    FILE *arquivo;
    Registro registro;

    tempFile = fopen("tempfile.bin", "wb");
    if (tempFile == NULL) {
        perror("Erro ao criar o arquivo temporario");
        exit(1);
    }

    arquivo = fopen("dadosobras.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    int encontrou = 0;

    while (fread(&registro, sizeof(Registro), 1, arquivo)) {
        if (registro.id == id) {
            encontrou = 1;

            printf("\nInformacoes da obra a ser excluida:\n");
            exibirObra(registro);

            // Pergunta ao usuário se ele realmente deseja excluir a obra
            printf("\nVoce realmente deseja excluir esta obra? Digite 1 para SIM ou 2 para NAO: ");
            int escolha;
            scanf("%d", &escolha);

            if (escolha == 1) {
                printf("Obra excluida com sucesso.\n");
            } else {
                printf("Operacao de exclusao cancelada.\n");
                fwrite(&registro, sizeof(Registro), 1, tempFile);  // Se a exclusão for cancelada, escreva de volta no arquivo temporário
            }
        } else {
            fwrite(&registro, sizeof(Registro), 1, tempFile);
        }
    }

    fclose(arquivo);
    fclose(tempFile);

    remove("dadosobrast.bin");
    rename("tempfile.bin", "dadosobrast.bin");

    if (encontrou == 0) {
        printf("Nao ha registro com o valor pesquisado.\n");
    }
}
