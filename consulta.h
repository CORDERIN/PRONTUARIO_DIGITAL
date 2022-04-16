/**
 * @file   consulta.h
 * @author Arthur Cordeiro
 */

#ifndef CONSULTA_H
#define CONSULTA_H
#define TAMANHO_MAXIMO_TEXTO 100
#include "data.h"

typedef struct consulta_s {

	data_t data;
	char texto_de_observacao[TAMANHO_MAXIMO_TEXTO];
	struct consulta_s* proximo;

}consulta_t;

typedef consulta_t* Lista_consulta;

Lista_consulta* cria_lista();
int insere_lista_final(Lista_consulta* lista, data_t data, char texto[]);
void mostra_lista(Lista_consulta* lista);
int lista_vazia(Lista_consulta* lista);
void libera_lista(Lista_consulta* lista);


#endif 