/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   moedas.cpp
 * Author: vinicius
 */

#include <stdlib.h>
#include <stdio.h>

int insere(struct no** raiz, int valor);
int insere(struct no** raiz, int valor);
struct no** inicia();

struct no{
    int valor;
    struct no *dir;
    struct no *esq;
};

int main() {

    struct no** raiz;
    raiz = inicia();

    insere(raiz,4);
    insere(raiz,2);
    insere(raiz,1);
    insere(raiz,3);


    if (insere(raiz, 15)) printf("Valor encontrado\n");
    else printf("valor não encontrado \n");


}

int insere(struct no** raiz, int valor){
    if(raiz == NULL){
       printf("Árvore não inicializada\n");
        return 0;
    }
    if(*raiz == NULL){
        struct no* ptrAux = (struct no*)malloc(sizeof(struct no));
        ptrAux->dir = NULL;
        ptrAux->esq = NULL;
        ptrAux->valor = valor;
        *raiz = ptrAux;

        return 1;
    }
    else{
        if(valor == (*raiz)->valor) return 0;

        else if(valor > (*raiz)->valor){
           return insere(&((*raiz)->dir), valor);
       }
        else if(valor < (*raiz)->valor){
           return insere(&((*raiz)->esq), valor);
       }
    }

}
struct no** inicia(){
    struct no** ptrAux = (struct no**)malloc(sizeof(struct no*));
    if(ptrAux != NULL){ *ptrAux = NULL;}

    return ptrAux;
}

int vazia(struct no** raiz){

    if(raiz == NULL || *raiz == NULL){
       printf("Árvore vazia!\n");
        return 1;
    }
    printf("Árvore não vazia!\n");
    return 0;
}

int insere(struct no** raiz, int valor){
    if(*raiz == NULL){
        return 0;
    }
    if((*raiz)->valor == valor) return 1;
    else if((*raiz)->valor > valor) return insere(&((*raiz)->esq), valor );
    else return (insere(&((*raiz)->dir), valor));
}

