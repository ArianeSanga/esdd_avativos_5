#include "pilha.h"

bool VerificaExpressao(char *expressao);

int main(){
  char *expressao = "1 + (2 * [3])";
  /*
  * Outros possíveis casos de teste: 
  * 1 + (2 * [3] -> falso
  * 1 * 2 (3 + [4 / 5]) -> verdadeiro
  * 9 / [(8 + 7] - 6) -> falso
  */

  if (VerificaExpressao(expressao)){
    printf("Contém parênteses, colchetes e chaves bem formados.\n");
  }else{
    printf("NÃO contém parênteses, colchetes e chaves bem formados.\n");
  }

  return 0;
}

bool VerificaExpressao(char *expressao) {
  Pilha pilha;
  Tipo_Informacao apice;

  init(&pilha);
  for (int index = 0; expressao[index] != '\0'; index++) {

    if (expressao[index] == '(' || expressao[index] == '[' || expressao[index] == '{') {
      push(pilha, expressao[index]);
    } else if (expressao[index] == ')' || expressao[index] == ']' || expressao[index] == '}') {
      if (is_empty(pilha)) {
        return false;
      }
      pop(pilha, &apice);

      if ((expressao[index] == ')' && apice != '(') ||
          (expressao[index] == ']' && apice != '[') ||
          (expressao[index] == '}' && apice != '{')) {
        return false;
      }
    }
  }

  return is_empty(pilha);
}
