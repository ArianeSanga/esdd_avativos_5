/*
 * File:   pilha.h
 * Author: Ednilson Rossi
 *
 * Created on 02 de outubro de 2023
 */

#include "pilha.h"

struct stack{
    Tipo_Informacao itens[MAX_STACK_SIZE];
    int topo;
};


void init(Pilha* pilha){

	*pilha = malloc(sizeof(struct stack));

	if(*pilha != NULL){
		(*pilha)->topo = -1;
	}
}


bool is_full(Pilha pilha){

	if(pilha->topo == MAX_STACK_SIZE - 1){
		return true;
    }else{
	    return false;
    }
}

bool is_empty(Pilha pilha){
	
    return pilha->topo == -1 ? true : false;

}


bool push(Pilha pilha, Tipo_Informacao elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_full(pilha) ){
            pilha->topo += 1;
            pilha->itens[pilha->topo] = elemento;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_empty(pilha) ){
			*elemento = pilha->itens[pilha->topo];
			pilha->topo -= 1;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool eh_igual(Pilha pilha1, Pilha pilha2){
		Pilha aux1;
		Pilha aux2;
    int numero1, numero2;
		bool saoIguais = true;

		init(&aux1);
    init(&aux2);

    while (!is_empty(pilha1) && !is_empty(pilha2)) {
        pop(pilha1, &numero1);
        pop(pilha2, &numero2);

        if (numero1 != numero2) {
            saoIguais = false;
        }
        push(aux1, numero1);
        push(aux2, numero2);
    }

    while (!is_empty(aux1) && !is_empty(aux2)) {
        pop(aux1, &numero1);
        pop(aux2, &numero2);
        push(pilha1, numero1);
        push(pilha2, numero2);
    }

    return saoIguais;
}