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

void inverte(Pilha* pilha) {
    if (pilha == NULL || is_empty(pilha)) {
       printf("Pilha Invalida");
       return; 
    }

    Tipo_Informacao aux[MAX_STACK_SIZE];
    int topo_aux = -1;


    while (!is_empty(pilha)) {
        Tipo_Informacao elemento;
        pop(pilha, &elemento);
        topo_aux++;
        aux[topo_aux] = elemento;
    }

    while (topo_aux >= 0) {
        push(pilha,aux[topo_aux]);
        topo_aux--;
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