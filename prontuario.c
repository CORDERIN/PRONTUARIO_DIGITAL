/**
 * @file   prontuario.c
 * @author Arthur Cordeiro
 */

#include "prontuario.h"
#include "data.h"
#include "consulta.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ERRO 1
#define SUCESSO 0

Arvore* cria_arvore() {

    Arvore* raiz = malloc(sizeof(Arvore));

    if (raiz != NULL)*raiz = NULL;
    
    return raiz;
}

int arvore_vazia(Arvore* arvore) {

    if (arvore == NULL) return ERRO;
    if (*arvore == NULL) return ERRO;

    return SUCESSO;
}

void preOrdem_ArvBin(no_t* raiz, data_t data) {

    if (raiz == NULL) return;


    if (raiz != NULL) {

        percorre_lista(raiz, data);
        preOrdem_ArvBin(raiz->esquerda, data);
        preOrdem_ArvBin(raiz->direito, data);

    }

}

no_t* remove_no(no_t* no) {

    no_t* no_1;
    no_t* no_2;

    if (no->esquerda == NULL)
    {
        no_2 = no->direito;
        free(no);
        return no_2;
    }
    no_1 = no;
    no_2 = no->esquerda;
    while (no_2->direito != NULL){
        no_1 = no_2;
        no_2 = no_2->direito;
    }
    if (no_1 != no) {

        no_1->direito = no_2->esquerda;
        no_2->esquerda = no->esquerda;
    }
    no_2->direito = no->direito;
    free(no);
    return no_2;
}


void libera_no(no_t* no) {

    if (no == NULL) return;
    libera_lista(no->prontuario.inicio_lista_consulta);
    libera_no(no->esquerda);
    libera_no(no->direito);
    free(no);
    no = NULL;
}


void percorre_lista(no_t* no, data_t data) {

    if (no == NULL)return;

    no_t* no_aux = no;
    consulta_t* lista_aux = *(no->prontuario.inicio_lista_consulta);

    while (lista_aux != NULL) {

        if ((lista_aux->data.dia == data.dia) && (lista_aux->data.mes == data.mes) && (lista_aux->data.ano == data.ano)) {

            printf("\n--->%s\n", no->prontuario.nome);
            break;
        }

        lista_aux = lista_aux->proximo;

    }

    return;
}
