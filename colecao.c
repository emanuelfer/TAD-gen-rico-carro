#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"

Colecao *create(int maxItens){
    if(maxItens > 0){
        Colecao *colecao = (Colecao*)malloc(sizeof(Colecao));
        if(colecao != NULL){
            colecao->item = (void**)malloc(sizeof(void*)*maxItens);
            if(colecao->item != NULL){
                colecao->maxItens = maxItens;
                colecao->numItens = 0;
                colecao->cur = -1;
                return colecao;
            }
        }
    }

    return NULL;
}

int destroy(Colecao *c){
    if(c != NULL){
        if(c->item != NULL){
            if(c->numItens == 0){
                free(c->item);
                free(c);
                return 1;
            }
        }
    }
    return 0;
}

int colInsert(Colecao *c, void *item){
    if(c != NULL){
        if(c->numItens < c->maxItens){
            c->item[c->numItens] = item;
            c->numItens++;
            return 1;
        }
    }
    return 0;
}

void *query(Colecao *c, void *key, int(*cmp)(void *,void *)){
    if(c != NULL){
        if(c->numItens > 0){
            for(int i = 0; i < c->numItens; i++){
                if(cmp(key, (void*)c->item[i]) == 1){
                    return c->item[i];
                }
            }
        }

    }
    return NULL;
}

void *colRemove(Colecao *c, void *key, int(*cmp)(void*, void*)){
    void * elem;
    if(c != NULL){
        if(c->numItens > 0){
            for(int i = 0; i < c->numItens; i++){
                if(cmp(key, c->item[i]) == 1){
                    elem = c->item[i];
                    while(i < c->numItens-1){
                        c->item[i] = c->item[i+1];
                        i++;
                    }
                    c->numItens--;
                    return elem;
                }
            }
        }
    }

    return NULL;
}

void *getFirst(Colecao *c){
    if(c != NULL){
        if(c->numItens > 0){
            c->cur = 0;
            return c->item[c->cur];
        }
    }
    return NULL;
}

void *getNext(Colecao *c){
    if(c != NULL){
        if(c->numItens > 0){
            c->cur++;
            if(c->numItens > c->cur){
                return c->item[c->cur];
            }

        }
    }
    return NULL;
}










