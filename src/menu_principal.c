#include <stdio.h>
#include <string.h>

int verifica_login_senha(const char *login, const char *senha) {
    const char *user_admin = "admin";
    const char *senha_admin = "admin123";

    if (strcmp(login, user_admin) == 0 && strcmp(senha, senha_admin) == 0) {
        return 1;
    }

    return 0;
}

int login_admin() {
    char login[50], senha[50];

    while (1) {
        printf("Digite o login: ");
        scanf("%s", login);

        printf("Digite a senha: ");
        scanf("%s", senha);

        if (verifica_login_senha(login, senha)) {
            printf("Acesso concedido!");
            return 1;
        } else {
            printf("Acesso negado! Tente novamente.\n");
        }
    }
}

void menu_principal() {
    int opcao;

    do {
        login_admin();

        printf("O que você quer fazer?\n");
        printf("  1 - Cadastrar tema/obras\n");
        printf("  2 - Consultar temas\n");
        printf("  3 - Cadastrar visitantes\n");
        printf("  4 - Avaliar visita\n");
        printf("  5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Aguardando função de cadastro de temas.\n");
                break;

            case 2:
                printf("Aguardando função de consulta de temas.\n");
                break;

            case 3:
                printf("Aguardando função de cadastro de visitantes.\n");
                break;

            case 4:
                printf("Aguardando função de avaliar visita.\n");
                break;

            case 5:
                printf("Saindo do programa. Até logo!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5);
}


int main() {
    menu_principal();
}
