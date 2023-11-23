#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

#define TAMANHO_CPF 11

typedef struct {
    char nome[30];
    char cpf[TAMANHO_CPF + 1]; // Não é necessário espaço para pontos e traços aqui
    time_t data;
} Registro;

int main() {
    FILE *arquivo;
    Registro registro;
    int i = 0;

    setlocale(LC_TIME, "Portuguese_Brazil.1252"); // Definindo o idioma para português

    arquivo = fopen("dados.bin", "ab");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Digite o nome do visitante: ");
    fgets(registro.nome, sizeof(registro.nome), stdin);

    printf("Digite o CPF (apenas numeros): ");
    while (i < TAMANHO_CPF) {
        char c = getchar();

        // Verifica se é um dígito numérico
        if (isdigit(c)) {
            registro.cpf[i++] = c;
        }
    }

    registro.cpf[TAMANHO_CPF] = '\0'; // Garante que a string esteja terminada corretamente

    // Limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Obter a data e hora atuais
    time(&registro.data);

    fwrite(&registro, sizeof(Registro), 1, arquivo);

    fclose(arquivo);

    // Exibir a data em português
    struct tm *info;
    info = localtime(&registro.data);
    printf("CPF formatado: %.3s.%.3s.%.3s-%.2s\n", registro.cpf, registro.cpf + 3, registro.cpf + 6, registro.cpf + 9);
    printf("Data e Hora Atuais: %02d/%02d/%04d %02d:%02d:%02d\n", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900,
           info->tm_hour, info->tm_min, info->tm_sec);
    printf("Registro incluso com sucesso.\n");

    return 0;
}

