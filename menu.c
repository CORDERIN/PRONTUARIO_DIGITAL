/**
 * @file   menu.c
 * @author Arthur Cordeiro
 */


#include "consulta.h"
#include "prontuario.h"
#include "data.h"
#include "menu.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCESSO 0
#define ERRO 1

int insere_consulta(Arvore* arvore) {

    if (arvore == NULL) return ERRO;
    no_t* novo = malloc(sizeof(no_t));
    if (novo == NULL) return ERRO;

    data_t data;
    char lixo;
    char texto_de_observacao[TAMANHO_MAXIMO_TEXTO];
    char nome[TAMANHO_MAXIMO_STRING];

    printf("\nInsira a data da consulta (DD/MM/AAAA): ");
    scanf("%d/%d/%d%c", &data.dia, &data.mes, &data.ano, &lixo);

    if (valida_data(data) == ERRO) {

        (void)fprintf(stderr, "Essa data eh impossivel! Tente novamente.\n");

        return ERRO;
    }

    printf("\nNome do paciente: ");
    fgets(nome, TAMANHO_MAXIMO_STRING, stdin);
    printf("\nComentario de observacao: ");
    fgets(texto_de_observacao, TAMANHO_MAXIMO_TEXTO, stdin);

    strcpy(novo->prontuario.nome, nome);
    novo->direito = NULL;
    novo->esquerda = NULL;
    novo->prontuario.inicio_lista_consulta = cria_lista();

    if (*arvore == NULL) {

        insere_lista_final(novo->prontuario.inicio_lista_consulta, data, texto_de_observacao);
        *arvore = novo;
        return SUCESSO;
    }

    no_t* atual = *arvore;
    no_t* pai = NULL;


    while (atual != NULL) {

        pai = atual;

        if (strcmp(nome, atual->prontuario.nome) == 0) {

            insere_lista_final(atual->prontuario.inicio_lista_consulta, data, texto_de_observacao);

            return SUCESSO;
        }

        if (strcmp(nome, atual->prontuario.nome) > 0) atual = atual->direito;
        else atual = atual->esquerda;
    }

    insere_lista_final(novo->prontuario.inicio_lista_consulta, data, texto_de_observacao);

    if (strcmp(novo->prontuario.nome, pai->prontuario.nome) > 0) pai->direito = novo;
    else pai->esquerda = novo;

    return SUCESSO;
}


int consultar_paciente(Arvore* arvore) {


    if (arvore_vazia(arvore)) {

        fprintf(stderr, "Ainda nao existem pacientes registrados.\n\n");

        return ERRO;
    }

    char nome[TAMANHO_MAXIMO_STRING];
    char lixo;

    printf("\nDigite um nome: ");
    fgets(nome, TAMANHO_MAXIMO_STRING, stdin);

    no_t* atual = *arvore;

    while (atual != NULL) {

        if (strcmp(nome, atual->prontuario.nome) == 0) {

            printf("\nOlha o que encontramos sobre %s\n", atual->prontuario.nome);
            mostra_lista(atual->prontuario.inicio_lista_consulta);

            return SUCESSO;
        }

        if (strcmp(nome, atual->prontuario.nome) > 0) atual = atual->direito;
        else atual = atual->esquerda;
    }

    printf("O nome ainda nao foi registrado ou foi removido.\n");

    return SUCESSO;

}

int consultar_data(Arvore* arvore) {

    if (arvore_vazia(arvore)) {

        (void)fprintf(stderr, "Nehum prontuario foi inserido\n");

        return ERRO;
    }

    data_t data;
    char lixo;

    printf("\nInsira uma data [DD/MM/AAAA]: ");
    scanf("%d/%d/%d%c", &data.dia, &data.mes, &data.ano, &lixo);

    if (valida_data(data) == ERRO) {

        (void)fprintf(stderr, "Essa data eh impossivel! Tente novamente.\n");

        return ERRO;
    }

    preOrdem_ArvBin(*arvore, data);

    printf("Funcao realizada com sucesso!\n");

    return SUCESSO;

}


int remover_prontuario(Arvore* arvore) {

    char nome[TAMANHO_MAXIMO_STRING];

    if (*arvore == NULL) {

        fprintf(stderr, "Ainda nao existem prontuarios inseridos.\n");
        return ERRO;
    }

    printf("\nInsira um nome:");
    fgets(nome, TAMANHO_MAXIMO_STRING, stdin);

    no_t* pai = NULL;
    no_t* atual = *arvore;

    while (atual != NULL) {

        if (strcmp(nome, atual->prontuario.nome) == 0) {

            if (atual == *arvore) {

                libera_lista(atual->prontuario.inicio_lista_consulta);
                *arvore = remove_no(atual);
            }

            else {

                if (pai->direito == atual) {
                    libera_lista((pai->direito)->prontuario.inicio_lista_consulta);
                    pai->direito = remove_no(atual);
                }
                else {

                    libera_lista((pai->esquerda)->prontuario.inicio_lista_consulta);
                    pai->esquerda = remove_no(atual);
                }
            }

            return SUCESSO;

        }

        pai = atual;
        if (strcmp(nome, atual->prontuario.nome) > 0) atual = atual->direito;
        else atual = atual->esquerda;

    }

    printf("Esse nome ainda nao foi inserido\n");

    return SUCESSO;
}


int fechar_programa(Arvore* arvore) {

    if (arvore == NULL) return ERRO;
    libera_no((*arvore));
    free(arvore);
}
