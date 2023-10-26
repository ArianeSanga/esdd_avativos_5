#include "pilha.h"

int main(int argc, char** argv){

    Pilha minhaPilha;
    Pilha auxiliar;
    int valor;

    printf("-----CONVERSAO DE BINARIOS-----\n\n");

    do{
        printf("Digite um valor a ser convertido: ");
        scanf("%d", &valor);

        if(valor < 0){
            printf("Digite um valor valido!!\n");
        }
    } while (valor < 0);

    init(&minhaPilha);

    int resto = 0;
    printf("RESTO: ");
    while (valor > 0){
        resto = valor % 2;
        valor = valor / 2;
        push(minhaPilha, resto);
        printf("%d, ", resto);
    }

    printf("\n");

    init(&auxiliar);

    int digito;
    printf("RESULTADO: ");
    while (!is_empty(minhaPilha)){
        pop(minhaPilha, &digito);
        push(auxiliar, digito);
        printf("%d", digito);
    }
    
    printf("\n");
}