#include "stdio.h"
#include "stdlib.h"

typedef struct
{
  int id;
  char tema[50], obra_1[255], obra_2[255], obra_3[255], descricao_1[255], descricao_2[255], descricao_3[255];
}Registro;

int main()
{
  FILE *arquivo;
  Registro registro;

  arquivo = fopen("dadosobras.bin","ab");
  if(arquivo == NULL)
  {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  printf("Digite o ID da obra.....: ");
  scanf("%d", &registro.id);
  fflush(stdin);
  printf("Digite o tema...: ");
  fgets(registro.tema,sizeof(registro.tema),stdin);
  fflush(stdin);
  printf("Digite a 1 obra do tema...: ");
  fgets(registro.obra_1,sizeof(registro.obra_1),stdin);
  fflush(stdin);
  printf("Digite a descricao da 1 obra...: ");
  fgets(registro.descricao_1,sizeof(registro.descricao_1),stdin);
  fflush(stdin);
  printf("Digite a 2 obra do tema...: ");
  fgets(registro.obra_2,sizeof(registro.obra_2),stdin);
  fflush(stdin);
  printf("Digite a descricao da 2 obra...: ");
  fgets(registro.descricao_2,sizeof(registro.descricao_2),stdin);
  fflush(stdin);
  printf("Digite a 3 obra do tema...: ");
  fgets(registro.obra_3,sizeof(registro.obra_3),stdin);
  fflush(stdin);
  printf("Digite a descricao da 3 obra...: ");
  fgets(registro.descricao_3,sizeof(registro.descricao_3),stdin);
  fflush(stdin);


  fwrite(&registro, sizeof(Registro), 1, arquivo);

  fclose(arquivo);

  printf("Registro incluido com sucesso.");

  return 0;
}
