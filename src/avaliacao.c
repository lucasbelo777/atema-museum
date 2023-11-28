#include "stdio.h"
#include "stdlib.h"

// Estrutura
typedef struct 
{
    char tema[50];
    int nota;
    char justificativa[255];
}Avaliacao;

// Variáveis Globais
int tam = 10;
Avaliacao lista[10];
int quant = 0;

// Protótipo de funções auxiliares
int CadastrarPessoa();
void SalvarEmArquivo();
void Relatorio_CSV();

int main(){
    int op;

    do
    {
        printf("Escolha uma das opcoes abaixo para continuar:\n1 - Avaliar Obras\n2 - Salvar e sair\n3 - Gerar relatorio csv\n0 - Apenas sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Saindo...");
            break;
        case 1:
            CadastrarPessoa();
            break;
        case 2:
            SalvarEmArquivo();
            break;
        case 3:
            Relatorio_CSV();
            break;
        
        default:
            printf("Opcao invalida.\n\n");
        }
    } while (op != 0);
    
    return 0;
}

// Desenvolvimento de Funções Auxiliares
int CadastrarPessoa(){
    system("cls");
    //variaveis
    int tema_selecionado;

    if(quant < tam){
        Avaliacao p;

        // Selecionar o Tema
        printf("Selecione o Tema para avaliacao dentre as opcoes abaixo:\n(1) Tema 1\n(2) Tema 2\n(3) Tema 3\n(4) Tema 4\n\n");
        scanf("%d", &tema_selecionado);

        // Enquanto não selecionar o Tema
        while (tema_selecionado <=0 || tema_selecionado>=5)
        {
            printf("Por favor, selecione um tema entre as opcoes 1 e 4!\n");
            scanf("%d", &tema_selecionado);
        }

        if (tema_selecionado == 1)
        {
            // Tema 1
            strcpy(p.tema,"Tema 1");
            printf("Selecionado: %s\n\n", p.tema);
        } else { 
            if (tema_selecionado == 2)
            {
                // Tema 2
                strcpy(p.tema, "Tema 2");
                printf("Selecionado: %s\n\n", p.tema);
                } else {
                    if (tema_selecionado == 3)
                    {
                        // Tema 3
                        strcpy(p.tema, "Tema 3");
                        printf("Selecionado: %s\n\n", p.tema);
                        } else {
                            // Tema 4
                            strcpy(p.tema, "Tema 4");
                            printf("Selecionado: %s\n\n", p.tema);
                    } 
            }
    
    }
        // Nota
        printf("Avalie a obra digitando de 1 a 5, sendo:\n1 para 'Nao gostei'\n5 para 'gostei muito'\n\n");
        scanf("%d", &p.nota);
        fflush(stdin);
        // Justificativa
        printf("\nDigite a justificativa para a nota: \n");
        fgets(p.justificativa, 255, stdin);
        fflush(stdin);
        system("cls");
        printf("Avaliacao anterior:\n\nTema: %s\nNota: %d\nJustificativa: %s\n\n", p.tema, p.nota, p.justificativa);

        lista[quant] = p;
        quant++;
        return 1;
    }
    else {
        printf("Erro: Vetor Cheio.\n\n");
        return 0;
    }
}

void SalvarEmArquivo(){
    system("cls");
    FILE *arq = fopen("avaliacoes.bin", "ab");
    if (arq)
    {
        fprintf(arq, "%d\n", quant); // Quantidade de registros no vetor 'quant'
        fwrite(lista, sizeof(Avaliacao), quant, arq); //
        fclose(arq);
    }
    else
        printf("ERRO: nao foi possivel abrir o arquivo.\n\n");
}

void Relatorio_CSV(){
    system("cls");
    int i;
    char arquivo_csv[50];

    sprintf(arquivo_csv, "relatorio_avaliacoes.csv"); // Criar arquivo.csv
    FILE *arq = fopen("avaliacoes.bin", "r"); // Abrir arquivo.bin
    FILE *arq_csv=fopen(arquivo_csv,"ab"); // Abrir arquivo.csv
    fputs("Tema, Nota, Justificativa\r\n", arq_csv); // Criando as colunas do arquivo.csv

    if (arq)
    {
        fscanf(arq, "%d\n", &quant);
        for (i = 0; i < quant; i++)
        {
            Avaliacao p;
            // Leitura das informações do arquivo.bin
            fgets(p.tema, 50, arq);
            fscanf(arq, "%d\n", &p.nota);
            fgets(p.justificativa, 255, arq);
            // Salvando as informações no arquivo.csv
            fprintf(arq_csv, "%s, ", lista[i].tema);
            fprintf(arq_csv, "%d, ", lista[i].nota);
            fprintf(arq_csv, "%s", lista[i].justificativa);
            lista[i] = p;
        }
        fclose(arq);
        fclose(arq_csv);
    }
    else
        printf("ERRO: nao foi possivel abrir o arquivo.\n\n");
    
}