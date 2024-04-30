
#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_CLIENTES 1000
#define TAM_NOME 50
#define TAM_SOBRENOME 50
#define TAM_CPF 15
#define TAM_VALOR 10
#define TAM_SENHA 10
#define TAM_TIPO_CONTA 10


struct Cliente {
    char nome[TAM_NOME];
    char sobrenome[TAM_SOBRENOME];
    char cpf[TAM_CPF];
    char valor[TAM_VALOR];
    char senha[TAM_SENHA];
    char tipoConta[TAM_TIPO_CONTA];
  
    
};

void novoCliente(struct Cliente lista[], int *numClientes);
void listarClientes(struct Cliente lista[], int numClientes);
void deletarCliente(struct Cliente lista[], int *numClientes);
void debitar(struct Cliente lista[], int numClientes);


#endif
