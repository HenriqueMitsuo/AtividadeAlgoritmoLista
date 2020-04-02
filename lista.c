#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void criaLista(C *cabeca) {

    cabeca->prox = NULL;
}

C* criaCliente(C *cabeca) {

    C *novoCliente;

    novoCliente = malloc(sizeof(C));

    printf("Digite o codigo do paciente: ");
    scanf("%i", &novoCliente->codigo);

    printf("Digite o nome do paciente: ");
    scanf("%s", &novoCliente->nome);

    novoCliente->prox = NULL;

    return novoCliente;
}

//! PRIORIDADE 2
void insereInicio(C *cabeca) {

    C *novoCliente;

    novoCliente = criaCliente(cabeca);

    novoCliente->prioridade = 2;
    novoCliente->prox = cabeca->prox;

    cabeca->prox = novoCliente;

    Controle++;
}

//! PRIORIDADE 1
void insereMeio(C *cabeca) {

    C *novoCliente;
    C *temp = cabeca;

    novoCliente = criaCliente(cabeca);

    novoCliente->prioridade = 1;

    if((Controle % 2) == 0) {

        int i = 0;
        int meio = Controle / 2;

        while (i < meio) {

            temp = temp->prox;
            i++;
        }

        novoCliente->prox = temp->prox;
        temp->prox = novoCliente;
    }
    else {

        int i = 0;
        int Impar = Controle - 1;
        int meio = Impar / 2;

        while (i <= meio){

            temp = temp->prox;
            i++;
        }

        novoCliente->prox = temp->prox;
        temp->prox = novoCliente;
    }

    Controle++;
}

//! PRIORIDADE 0
void insereFim(C *cabeca) {

    C *novoCliente;

    novoCliente = criaCliente(cabeca);

    novoCliente->prioridade = 0;

    if (cabeca->prox == NULL)
    {

        cabeca->prox = novoCliente;
    }
    else
    {

        C *temp = cabeca->prox;

        while (temp->prox != NULL)
        {

            temp = temp->prox;
        }

        temp->prox = novoCliente;
    }

    Controle++;
}

void removeInicio(C *cabeca) {

    printf("Paciente (%i) (%s) REMOVIDO\n\n", cabeca->prox->codigo, cabeca->prox->nome);
    cabeca->prox = cabeca->prox->prox;

    Controle--;
}

void removeMeio(C *cabeca) {

    if ((Controle % 2) == 0) {

        int i = 0;
        int meio = Controle / 2;

        while (i < meio) {

            cabeca = cabeca->prox;
            i++;
        }
        printf("Paciente (%i) (%s) REMOVIDO\n\n", cabeca->prox->codigo, cabeca->prox->nome);
        cabeca->prox = cabeca->prox->prox;
    }
    else {

        int i = 0;
        int Impar = Controle - 1;
        int meio = Impar / 2;

        while (i < meio) {

            cabeca = cabeca->prox;
            i++;
        }
        printf("Paciente (%i) (%s) REMOVIDO\n\n", cabeca->prox->codigo, cabeca->prox->nome);
        cabeca->prox = cabeca->prox->prox;
    }

    Controle--;
}

void removeFim(C *cabeca) {

    if(cabeca->prox == NULL) {

        printf("Lista vazia\n\n");
    }
    else {

        C *ultimo = cabeca->prox;
        C *penultimo = cabeca;

        while (ultimo->prox != NULL)
        {

            penultimo = ultimo;
            ultimo = ultimo->prox;
        }

        penultimo->prox = NULL;

        printf("Paciente (%i) (%s) REMOVIDO\n\n", ultimo->codigo, ultimo->nome);
    }

    Controle--;
}

void mostraLista(C *cabeca) {

    system("cls");
    if (cabeca->prox != NULL) {

        C *temp;
        temp = cabeca->prox;

        printf("Pacientes Cadastrados:\n");
        printf("Prioridade:\n");
        printf("(2) Maxima\n");
        printf("(1) Media\n");
        printf("(0) Baixa\n\n");
        while (temp != NULL) {

            printf("Codigo: (%i) - Nome: (%s) - Prioridade: (%i)\n", temp->codigo, temp->nome, temp->prioridade);
            temp = temp->prox;
        }
    }
    else {

        printf("Lista vazia\n\n");
    }
}

void menu(C *cabeca) {

    int opcao;

    do {
        printf("==========## MENU - CADASTRO DE PACIENTES (LISTA) ##==========\n");
        printf("1 - Registrar Prioridade ALTA (INICIO)\n");
        printf("2 - Registrar Prioridade MEDIA (MEIO)\n");
        printf("3 - Registrar Prioridade BAIXA (FIM)\n");
        printf("4 - Remover (INICIO)\n");
        printf("5 - Remover (MEIO)\n");
        printf("6 - Remover (FIM)\n");
        printf("7 - Mostrar Lista\n");
        printf("8 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%i", &opcao);

        switch (opcao) {

        case 1:
            system("cls");
            insereInicio(cabeca);
            system("cls");
            break;

        case 2:
            system("cls");
            insereMeio(cabeca);
            system("cls");
            break;

        case 3:
            system("cls");
            insereFim(cabeca);
            system("cls");
            break;

        case 4:
            system("cls");
            removeInicio(cabeca);
            printf("\n");
            break;

        case 5:
            system("cls");
            removeMeio(cabeca);
            printf("\n");
            break;

        case 6:
            system("cls");
            removeFim(cabeca);
            printf("\n");
            break;

        case 7:
            system("cls");
            mostraLista(cabeca);
            printf("\n");
            break;

        case 8:
            printf("\nPrograma finalizado!\n");
            break;

        default:
            system("cls");
            printf("Escolha uma opcao valida!\n");
        }
    } while (opcao != 8);
}