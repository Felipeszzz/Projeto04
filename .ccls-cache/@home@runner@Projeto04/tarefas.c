#include <stdio.h>
#include <string.h>
#include "tarefas.h"

void extermina_linha(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void novoCliente(struct Cliente lista[], int *numClientes) {
    if (*numClientes >= MAX_CLIENTES) {
        printf("A lista de clientes está cheia.\n");
        return;
    }

    printf("Digite o seu nome: ");
    scanf("%49s", lista[*numClientes].nome);
    clearBuffer();

    printf("Digite o seu sobrenome: ");
    scanf("%49s", lista[*numClientes].sobrenome);
    clearBuffer();

    printf("Tipo de conta (comum ou plus): ");
    scanf("%9s", lista[*numClientes].tipoConta);
    clearBuffer();

    printf("Digite o seu CPF: ");
    scanf("%14s", lista[*numClientes].cpf);
    clearBuffer();

    printf("Digite o seu valor: ");
    scanf("%9s", lista[*numClientes].valor);
    clearBuffer();

    printf("Digite a sua senha: ");
    scanf("%9s", lista[*numClientes].senha);
    clearBuffer();

    (*numClientes)++;
}

void listarClientes(struct Cliente lista[], int numClientes) {
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Lista de Clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("NOME: %s\n", lista[i].nome);
        printf("SOBRENOME: %s\n", lista[i].sobrenome);
        printf("CONTA: %s\n", lista[i].tipoConta);
        printf("CPF: %s\n", lista[i].cpf);
        printf("VALOR: %s\n", lista[i].valor);
        printf("SENHA: %s\n", lista[i].senha);
        printf("\n");
    }
}

void deletarCliente(struct Cliente lista[], int *numClientes) {
    if (*numClientes == 0) {
        printf("Não há clientes cadastrados para serem deletados.\n");
        return;
    }

    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente que deseja deletar: ");
    scanf("%14s", cpf);
    clearBuffer();

    int achouCliente = 0;
    for (int i = 0; i < *numClientes; i++) {
        if (strcmp(lista[i].cpf, cpf) == 0) {
            achouCliente = 1;

            // Movendo os clientes a serem mantidos para frente
            for (int j = i; j < *numClientes - 1; j++) {
                lista[j] = lista[j + 1];
            }
            (*numClientes)--;
            printf("O cliente foi deletado com sucesso!\n");
            break; // Sai do loop após encontrar e deletar o cliente
        }
    }

    if (!achouCliente) {
        printf("Esse cliente não foi cadastrado para ser deletado.\n");
    }
}



void debitar(struct Cliente lista[], int numClientes) {
    if (numClientes == 0) {
        printf("Não há clientes cadastrados para realizar o débito.\n");
        return;
    }

    char cpf[TAM_CPF];
    char senha[TAM_SENHA];
    printf("Digite o seu CPF: ");
    scanf("%14s", cpf);
    clearBuffer();

    printf("Digite a sua senha: ");
    scanf("%9s", senha);
    clearBuffer();

    int clienteEncontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(lista[i].cpf, cpf) == 0 && strcmp(lista[i].senha, senha) == 0) {
            clienteEncontrado = 1;
            float valor;
            printf("Digite o valor a ser debitado: ");
            scanf("%f", &valor);
            clearBuffer();

            // Serve para verifica se o cliente tem saldo suficiente para o débito.
            float saldo;
            sscanf(lista[i].valor, "%f", &saldo);
            if (valor > saldo) {
                printf("Saldo insuficiente para realizar o débito.\n");
            } else {
                saldo -= valor;
                sprintf(lista[i].valor, "%.2f", saldo);
                printf("Débito realizado com sucesso. Saldo atual: %.2f\n", saldo);
            }
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("CPF ou senha incorretos. Não foi possível realizar o débito.\n");
    }
}
