/**
 * @file   data.c
 * @author Arthur Cordeiro
 */


#include "data.h"
#define ANO_MINIMO 1900
#define ERRO 1
#define SUCESSO 0


int valida_data(data_t data) {


    if (data.ano <= ANO_MINIMO){

       return ERRO;
    }

    if (data.mes > 12 || data.mes < 1) {

        return ERRO;
    }

    if (data.mes == 2) {
        
        if (data.dia > 28 || data.dia < 1) {

            return ERRO;

        }

    }

    if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12) {

        if (data.dia > 31 || data.dia < 1) {

            return ERRO;

        }

    }

    if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {

        if (data.dia > 30 || data.dia < 1) {

            return ERRO;

        }

    }

    return SUCESSO;
}


