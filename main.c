#include <stdio.h>
#include "tarefas.h"

int main() {
    struct Cliente listaclientes[MAX_CLIENTES];
    int numContatos = 0;
    char opcao;

    do {
        printf("\nMenu Principal:\n");
        printf("1- Novo Cliente\n");
        printf("2- Apagar Cliente\n");
        printf("3- Listar Clientes\n");
        printf("4- Débito\n");
        printf("5- Depósito\n");
        printf("6- Extrato\n");
        printf("7- Tranferência entre contas\n");
        printf("8- Salvar Clientes\n");
        printf("9- Carregar Clientes\n");
        printf("0- Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao); 

        switch (opcao) {
            case '1':
              novoCliente(listaclientes, &numContatos);
                break;

            case '2':
              deletarCliente(listaclientes, &numContatos);
                break;

            case '3':
              listarClientes(listaclientes, numContatos);
                break;

            case '4':
              debitar(listaclientes, numContatos);
            break;

            case '5':
              depositoCliente (listaclientes, numContatos);
                  break;

            case '6':
              extrato(listaclientes, numContatos, 0.0f, 0.0f);
                  break;

            case '7':
            transferencia(listaclientes, numContatos);
            break;


            case '8':
              salvarCliente(listaclientes, &numContatos);
              printf("Cliente salvo!\n");
                  break;

            case '9':
              carregaCliente(listaclientes, &numContatos);
              printf("Clientes carregados com sucesso!");
                  break;
          
            case '0':
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }

    } while (opcao != '0');

    return 0;
}


