#include "pilha.h"

int main(int argc, char** argv) {
    Pilha minhaPilha;
    int menu;
    Tipo_Informacao valor;

    init(&minhaPilha);

    do{
        printf("\n1 - Empilha");
        printf("\n2 - Desempilha");
        printf("\n3 - Esvaziar");
        printf("\n4 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("\nEmpilha\n\n\tValor: ");
                scanf("%d", &valor);
                if(push(minhaPilha, valor)){
                    printf("\nEmpilhado com sucesso\n");
                }else{
                    printf("\nEstouro de pilha\n");
                }
                break;
            case 2:
                if(pop(minhaPilha, &valor)){
                    printf("\nDesempilha\n\n\tValor: %d", valor);
                }else{
                    printf("\nPilha vazia\n");
                }
                break;
            case 3:
                to_empty(minhaPilha);
                break;
        }
    }while(menu != 4);
    return 0;
}


void insere(Pilha Pilha){
    int valor;
    printf("digite valor:");
    scanf("%d",&valor);
    if(valor==valor){
        return FALSE;
    }else{
        push(Pilha,valor);
    }
    int aux;
    init(&aux);
    while( ! is_empty(Pilha)){
        valor = pop(Pilha);
        if(valor->topo > valor->base){
            push(aux, valor);
        }
    }

    while( ! is_empty(aux) ){
        valor = pop(aux);
        printf("%d, ", valor);
        push(Pilha, valor);
    }
}