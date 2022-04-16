/**
 * @file   data.h
 * @author Arthur Cordeiro
 */

#ifndef DATA_H
#define DATA_H

typedef struct data_s{

	int dia;
	int mes;
	int ano;

}data_t;

int valida_data(data_t data);

#endif
