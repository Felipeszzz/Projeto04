#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_CLIENTES 1000
#define TAM_NOME 50
#define TAM_SOBRENOME 50
#define TAM_CPF 15
//#define TAM_DESTINO 15
#define TAM_VALOR 10
#define TAM_SENHA 50
#define TAM_TIPO_CONTA 10

typedef enum {ABRIR, FECHAR, LER, ESCREVER} informacoesCode;

struct Cliente {
    char nome[TAM_NOME];
    char sobrenome[TAM_SOBRENOME];
    char cpf[TAM_CPF];
    //char cpfDestino[TAM_DESTINO];
    char senha[TAM_SENHA];
    char tipoConta[TAM_TIPO_CONTA];
    float saldo;
    float debito;
    float deposito;    
};

void novoCliente(struct Cliente lista[], int *numClientes);
void listarClientes(struct Cliente lista[], int numClientes);
informacoesCode salvarCliente(struct Cliente lista[], int *numClientes);
informacoesCode carregaCliente(struct Cliente lista[], int *numClientes);
void deletarCliente(struct Cliente lista[], int *numClientes);
float debitar(struct Cliente lista[], int numClientes);
float depositoCliente(struct Cliente lista[], int numClientes);
void extrato(struct Cliente lista[], int numClientes, float debito, float deposito);
void transferencia(struct Cliente lista[], int numClientes);

void clearBuffer();

#endif
