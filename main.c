#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#define MAX 100

typedef struct _carro_{
    char nome[30];
    char placa[8];
    char chassi[20];
    char modelo[60];
    float preco;
    int ano;
}Carro;

void exibirCarro(Carro *carro){
    printf("Nome: %s\n", carro->nome);
    printf("Placa: %s\n", carro->placa);
    printf("Modelo: %s\n", carro->modelo);
    printf("Ano: %i\n", carro->ano);
    printf("Preco: R$ %.2f\n", carro->preco);
    system("pause");
    system("cls");
}

int comparaPlaca(void *a, void *b){
    char *pa = (char*)a;
    Carro *pb = (Carro*)b;
    if(strcmp(pa, pb->placa) == 0 ){
        return 1;
    }else{
        return 0;
    }
}

int comparaPreco(void *a, void *b){
    float *pa = (float*)a;
    Carro *pb = (Carro*)b;
    if(*pa == pb->preco){
        return 1;
    }else{
        return 0;
    }
}

int comparaAno(void *a, void *b){
    int *pa = (int*)a;
    Carro *pb = (Carro*)b;
    if(*pa == pb->ano ){
        return 1;
    }else{
        return 0;
    }
}

int verificaColecao(Colecao *c){
    if(c == NULL){
        printf("Voce precisa criar uma colecao!\n");
        system("pause");
        system("cls");
        return 0;
    }
    return 1;
}

int main()
{
    Colecao *colecao = NULL;
    Carro *carro;
    char placa[8];
    int op=1, retorno = 0, ano;
    float preco;

    while(op != 0){
        printf("1 - Criar colecao\n");
        printf("2 - Cadastrar carro\n");
        printf("3 - Buscar carro pela placa\n");
        printf("4 - Buscar carro pelo ano\n");
        printf("5 - Buscar carro pelo preco\n");
        printf("6 - Remover carro pela placa\n");
        printf("7 - Remover carro pelo ano\n");
        printf("8 - Remover carro pelo preco\n");
        printf("9 - Listar carros\n");
        printf("10 - Destruir colecao\n");
        printf("0 - Sair\n");
        scanf("%i", &op);
        system("cls");

        switch(op){
        case 1:
                colecao = create(MAX);
                if(colecao != NULL){
                    printf("Colecao criada com sucesso!\n");
                }else{
                    printf("Erro ao criar colecao!\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                if(!verificaColecao(colecao)){
                    break;
                }
                setbuf(stdin, NULL);

                carro = (Carro*)malloc(sizeof(Carro));

                printf("Digite o nome do carro:\n");
                gets(carro->nome);
                setbuf(stdin, NULL);

                printf("Digite a placa do carro:\n");
                gets(carro->placa);
                setbuf(stdin, NULL);

                printf("Digite modelo do carro:\n");
                gets(carro->modelo);
                setbuf(stdin, NULL);

                printf("Digite o ano do carro:\n");
                scanf("%i", &carro->ano);

                printf("Digite o preco do carro:\n");
                scanf("%f", &carro->preco);

                retorno = colInsert(colecao, carro);

                if(retorno == 1){
                    printf("Carro cadastro com sucesso!\n");
                }else{
                    printf("Erro ao cadastrar!\n");
                }
                system("pause");
                system("cls");
                break;
            case 3:
                if(!verificaColecao(colecao)){
                    break;
                }
                if(colecao->numItens == 0){
                    printf("Nenhum carro cadastrado!\n");
                    break;
                }

                setbuf(stdin, NULL);
                printf("Digite a placa do carro:\n");
                gets(placa);


                carro = query(colecao, (void*)placa, comparaPlaca);

                if(carro == NULL){
                    printf("Placa nao encontrada!\n");
                    break;
                }else{
                    exibirCarro(carro);
                }

                break;
            case 4:
                if(!verificaColecao(colecao)){
                    break;
                }
                if(colecao->numItens == 0){
                    printf("Nenhum carro cadastrado!\n");
                    break;
                }

                setbuf(stdin, NULL);
                printf("Digite o ano do carro:\n");
                scanf("%i", &ano);

                carro = query(colecao, (void*)&ano, comparaAno);

                if(carro == NULL){
                    printf("Ano nao encontrado!\n");
                    break;
                }else{
                    exibirCarro(carro);
                }

                break;
            case 5:
                if(!verificaColecao(colecao)){
                    break;
                }
                if(colecao->numItens == 0){
                    printf("Nenhum carro cadastrado!\n");
                    break;
                }

                setbuf(stdin, NULL);
                printf("Digite o preco do carro:\n");
                scanf("%f", &preco);

                carro = query(colecao, (void*)&preco, comparaPreco);

                if(carro == NULL){
                    printf("Preco nao encontrado!\n");
                    break;
                }else{
                    exibirCarro(carro);
                }

                break;
            case 6:
                if(!verificaColecao(colecao)){
                    break;
                }
                if(colecao->numItens == 0){
                    printf("Nenhum carro cadastrado!\n");
                    break;
                }

                setbuf(stdin, NULL);
                printf("Digite a placa do carro:\n");
                gets(placa);

                carro = colRemove(colecao, (void*)placa, comparaPlaca);

                if(carro == NULL){
                    printf("Placa nao encontrada!\n");
                    break;
                }else{
                    exibirCarro(carro);
                }
                break;
            case 7:
                if(!verificaColecao(colecao)){
                    break;
                }
                if(colecao->numItens == 0){
                    printf("Nenhum carro cadastrado!\n");
                    break;
                }

                setbuf(stdin, NULL);
                printf("Digite o ano do carro:\n");
                scanf("%i", &ano);

                carro = colRemove(colecao, (void*)&ano, comparaAno);

                if(carro == NULL){
                    printf("Ano nao encontrado!\n");
                    break;
                }else{
                    exibirCarro(carro);
                }
                break;
            case 8:
                if(!verificaColecao(colecao)){
                    break;
                }
                if(colecao->numItens == 0){
                    printf("Nenhum carro cadastrado!\n");
                    break;
                }

                setbuf(stdin, NULL);
                printf("Digite o preco do carro:\n");
                scanf("%f", &preco);

                carro = colRemove(colecao, (void*)&preco, comparaPreco);

                if(carro == NULL){
                    printf("Preco nao encontrado!\n");
                    break;
                }else{
                    exibirCarro(carro);
                }
                break;
            case 9:
                if(colecao == NULL){
                    printf("Voce precisa criar uma colecao!\n");
                    system("pause");
                    system("cls");
                    break;
                }

                carro = getFirst(colecao);
                if(carro == NULL){
                    printf("Nenhum carro cadastrado!\n");
                    system("pause");
                    system("cls");
                    break;
                }

                exibirCarro(carro);
                if(carro != NULL){
                    while(carro != NULL){
                        carro = getNext(colecao);
                        if(carro != NULL)
                            exibirCarro(carro);
                    }
                }
                break;
            case 10:
                if(destroy(colecao)==1){
                    printf("Colecao destruida com sucesso!\n");
                    colecao = NULL;
                }else{
                    printf("Erro ao destruir colecao!\n");
                }
                system("pause");
                system("cls");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }

    return 0;
}
