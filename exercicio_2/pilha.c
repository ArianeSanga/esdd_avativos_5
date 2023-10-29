#include "pilha.h"


struct stack{
    Tipo_Informacao itens[MAX_STACK_SIZE];
    int topo;
};

bool printa(Pilha pilha) {
    for(int i = 0; i <= pilha->topo; i++) {
    	printf("%d ", pilha->itens[i]);
	}
}

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

void to_empty(Pilha pilha){
    pilha->topo = -1;
}

bool insere(Pilha pilha, Tipo_Informacao numero) {
	if(procuraElemento(pilha, numero) || is_full(pilha)){
		return false;
	}

	if(is_empty(pilha) || numero > pilha->itens[pilha->topo]) {
		pilha->itens[++(pilha->topo)] = numero;
		return true;
	}

	int tempTopo = pilha->topo;
    while (tempTopo >= 0 && numero < pilha->itens[tempTopo]) {
        pilha->itens[tempTopo + 1] = pilha->itens[tempTopo];
        tempTopo--;
    }
    pilha->itens[tempTopo + 1] = numero;
    pilha->topo++;
	return true;
}

bool procuraElemento(Pilha pilha, Tipo_Informacao elemento) {
	for(int i = 0; i <= pilha->topo; i++) {
		if(pilha->itens[i] == elemento) {
			return true;
		}
	}

	return false;
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