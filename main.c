/**
 * @file   main.c
 * @author Arthur Cordeiro
 */

 // Inclusões

#include <stdio.h>
#include "prontuario.h"
#include "menu.h"

// Definição de constantes

#define SUCESSO 0


int main(int argc, char** argv) {

    int escolha_de_menu;
    char lixo;

    Arvore* arvore = cria_arvore();


    //Estrutura de repetição do menu de opções até que o usuário escolha fechar o programa

    do {

        // Limpa toda a informação presente no sonsole no momento de sua execução 
        system("cls");

       printf("\t  _____________________________________________________________\n"
             "\t.'  __________________________________________________________ '.\n"
             "\t: .'                                                          '. :\n"
             "\t| |      ________________________________________________      | |\n"
             "\t| |    .:________________________________________________:.    | |\n"
             "\t| |    |        BEM-VINDO AO PRONTUARIO DIGITAL           |    | |\n"
             "\t| |    |                                                  |    | |\n"
             "\t| |    |    MENU PRINCIPAL:                               |    | |\n"
             "\t| |    |                                                  |    | |\n"
             "\t| |    |    1 - Consultar paciente                        |    | |\n"
             "\t| |    |    2 - Consultar data                            |    | |\n"
             "\t| |    |    3 - Inserir consulta                          |    | |\n"
             "\t| |    |    4 - Remover prontuario                        |    | |\n"
             "\t| |    |    0 - Fechar o programa                         |    | |\n"
             "\t| |    |                                                  |    | |\n"
             "\t| |    |                                                  |    | |\n"
             "\t| |    |            __________________________            |    | |\n"
             "\t| |    |           |  |  |  |  |  |  |  |  |  |           |    | |\n"
             "\t| |    '.__________|__|__|__|__|__|__|__|__|__|__________.'    | |\n"
             "\t| |                                                            | |\n"
             "\t| |                     Trabalho - AEDES                       | |\n"
             "\t: '.__________________________________________________________.' :\n"
             "\t'._____________________________/__ /____________________________.'\n\n\n\n");
             

        printf("Escolha o que deseja fazer: ");
        scanf("%d%c", &escolha_de_menu, &lixo);

        switch (escolha_de_menu){


         case 1:

            consultar_paciente(arvore);

            break;

         case 2:

            consultar_data(arvore);

            break;

         case 3:

            insere_consulta(arvore);

            break;

         case 4:

            remover_prontuario(arvore);

            break;

         case 0:

            fechar_programa(arvore);

            break;

         default:

            (void)fprintf(stderr, "O numero eh invalido\n");

            break;
        }

        /* Gera uma pause no sistema, fazendo com que o usuário
        precise pressionar alguma tecla para continuar
        */
        system("pause");

    } while (escolha_de_menu != 0);


    // Se chegar até aqui, ocorreu tudo certo
    return SUCESSO;
}
