/**
 * @file   consulta.c
 * @author Arthur Cordeiro
 */

#include "consulta.h"
#include "prontuario.h"
#include "data.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ERRO 1
#define SUCESSO 0

Lista_consulta* cria_lista() {

    Lista_consulta* lista = malloc(sizeof(Lista_consulta));
    if (lista != NULL) *lista = NULL;
    return lista;
}

int lista_vazia(Lista_consulta* lista) {

    return (lista == NULL || *lista == NULL);
}

int insere_lista_final(Lista_consulta* lista, data_t data, char texto[]) {


    if (lista == NULL) return ERRO;
    consulta_t* elem = malloc(sizeof(consulta_t));
    if (elem == NULL) return ERRO;

    elem->data.dia = data.dia;
    elem->data.mes = data.mes;
    elem->data.ano = data.ano;
    strcpy(elem->texto_de_observacao, texto);
    elem->proximo = NULL;

    if (*lista != NULL) {

        consulta_t* aux = *lista;
        while (aux->proximo != NULL) aux = aux->proximo;
        aux->proximo = elem;

        return SUCESSO;
    }


    if (*lista == NULL) {

        *lista = elem;

        return SUCESSO;
    }

}



void mostra_lista(Lista_consulta* lista) {

    if (lista_vazia(lista)) return;

    consulta_t* elem = *lista;

    printf("-------------------------------\n");

    while (elem != NULL) {

        printf("Data de consulta: %d/%d/%d\n"
            "Registros: %s"
            "--------------------------------\n", elem->data.dia, elem->data.mes, elem->data.ano, elem->texto_de_observacao);

        elem = elem->proximo;
    }

}



void libera_lista(Lista_consulta* lista) {

    if (lista == NULL) return;

    consulta_t* aux;

    while (*lista != NULL) {

        aux = *lista;
        *lista = (*lista)->proximo;
        free(aux);
    }

    free(lista);
}
