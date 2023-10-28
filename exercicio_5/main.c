#include "pilha.h"

int main(int argc, char **argv){
  Pilha pilha1;
  Pilha pilha2;
  Tipo_Informacao valor;
  int menu;

  init(&pilha1);
  init(&pilha2);

  do{
    printf("\n1 - Empilhar pilha1");
    printf("\n2 - Empilhar pilha2");
    printf("\n3 - Desempilhar pilha 1");
    printf("\n4 - Desempilhar pilha 2");
    printf("\n5 - Verificar se as pilhas sao iguais");
    printf("\n6 - Sair");
    printf("\nOpcao: ");
    scanf("%d", &menu);

    switch (menu){
    case 1:
      printf("\nEmpilha\n\n\tValor: ");
      scanf("%d", &valor);
      if (push(pilha1, valor)){
        printf("\nEmpilhado com sucesso\n");
      }else{
        printf("\nEstouro de pilha\n");
      }
      break;
    case 2:
      printf("\nEmpilha\n\n\tValor: ");
      scanf("%d", &valor);
      if (push(pilha2, valor)){
        printf("\nEmpilhado com sucesso\n");
      }else{
        printf("\nEstouro de pilha\n");
      }
      break;
    case 3:
      if(pop(pilha1, &valor)){
        printf("\nDesempilha\n\n\tValor: %d", valor);
      }else{
        printf("\nPilha 1 esta vazia\n");
      }
      break;
    case 4:
      if(pop(pilha2, &valor)){
        printf("\nDesempilha\n\n\tValor: %d", valor);
      }else{
        printf("\nPilha 2 esta vazia\n");
      }
      break;
    case 5:
      if (eh_igual(pilha1, pilha2)) {
        printf("As pilhas sao iguais\n");
      } else {
        printf("As pilhas nao sao iguais\n");
      }
      break;
    }
  } while (menu != 5);

  return 0;
}