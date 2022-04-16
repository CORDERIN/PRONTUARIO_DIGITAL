/**
 * @file   prontuario.h
 * @author Arthur Cordeiro
 */


#ifndef PRONTUARIO_H
#define PRONTUARIO_H
#define TAMANHO_MAXIMO_STRING 50
#include "consulta.h"

typedef struct prontuario_s {

	char nome[TAMANHO_MAXIMO_STRING];
	Lista_consulta* inicio_lista_consulta;

}prontuario_t;

typedef struct no_s {

	struct no_s* esquerda;
	prontuario_t prontuario;
	struct no_s* direito;

}no_t;

typedef no_t* Arvore;

Arvore* cria_arvore();
int arvore_vazia(Arvore* arvore);
void preOrdem_ArvBin(no_t* raiz, data_t data);
no_t* remove_no(no_t* no);
void libera_no(no_t* no);
void percorre_lista(no_t* no, data_t data);

#endif