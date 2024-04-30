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
        printf("5- Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao); // Adicionado um espaço antes de %c para consumir o caractere de nova linha

        switch (opcao) {
            case '1':
                novoCliente(listaclientes, &numContatos); // Corrigido para chamar a função novoCliente
                break;

            case '2':
                deletarCliente(listaclientes, &numContatos); // Corrigido para chamar a função deletarCliente
                break;

            case '3':
                listarClientes(listaclientes, numContatos); // Corrigido para chamar a função listarClientes
                break;

            case '4':
            debitar(listaclientes, numContatos);
            break;


            case '5':
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }

    } while (opcao != '5');

    return 0;
}


