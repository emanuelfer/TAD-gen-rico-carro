#ifndef COLECAO_H_INCLUDED
#define COLECAO_H_INCLUDED


struct _colecao_{
    int numItens;
    int maxItens;
    int cur;
    void **item;
};

typedef struct _colecao_ Colecao;

Colecao *create(int maxItens);
int destroy(Colecao *c);
int colInsert(Colecao *c, void *item);
void *query(Colecao *c, void *key, int(*cmp)(void *,void *));
void *colRemove(Colecao *c, void *key, int(*cmp)(void*, void*));
void *getFirst(Colecao *c);
void *getNext(Colecao *c);


#endif // COLECAO_H_INCLUDED
