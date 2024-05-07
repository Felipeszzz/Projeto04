#include "tarefas.h"
#include <stdio.h>
#include <string.h>

// void extermina_linha(char *str) {
//     int len = strlen(str);
//     if (len > 0 && str[len - 1] == '\n') {
//         str[len - 1] = '\0';
//     }
// }

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
  scanf("%f", &lista[*numClientes].saldo);
  clearBuffer();

  printf("Digite a sua senha: ");
  scanf("%49s", lista[*numClientes].senha);
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
    printf("VALOR: %.2f\n", lista[i].saldo);
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

      for (int j = i; j < *numClientes - 1; j++) {
        lista[j] = lista[j + 1];
      }

      (*numClientes)--;
      printf("O cliente foi deletado com sucesso!\n");
      break;
    }
  }

  if (!achouCliente) {
    printf("Esse cliente não foi cadastrado para ser deletado.\n");
  }
}

float debitar(struct Cliente lista[], int numClientes) {
  if (numClientes == 0) {
    printf("Não há clientes para debitar.\n");
    return 0.0; // Retorna 0.0 se não houver clientes para debitar
  }

  char cpf[TAM_CPF];
  float valor;
  printf("Digite o CPF do cliente: ");
  scanf("%14s", cpf);
  clearBuffer();

  int clienteEncontrado = 0;
  for (int i = 0; i < numClientes; i++) {
    if (strcmp(lista[i].cpf, cpf) == 0) {
      clienteEncontrado = 1;
      printf("Digite o valor a ser debitado: ");
      scanf("%f", &valor);
      clearBuffer();

      if (valor <= 0) {
        printf("Valor inválido para débito.\n");
        return 0.0; // Retorna 0.0 se o valor for inválido
      }

      if (valor > lista[i].saldo) {
        printf("Saldo insuficiente para debitar esse valor.\n");
        return 0.0; // Retorna 0.0 se o saldo for insuficiente
      }

      lista[i].saldo -= valor;
      printf("Débito de %.2f realizado com sucesso.\n", valor);
      return valor; // Retorna o valor do débito realizado
    }
  }

  if (!clienteEncontrado) {
    printf("Cliente não encontrado.\n");
  }

  return 0.0; // Retorna 0.0 se o cliente não for encontrado
}


float depositoCliente(struct Cliente lista[], int numClientes) {
  if (numClientes == 0) {
    printf("Não há clientes para depositar.\n");
    return 0.0; // Retorna 0.0 se não houver clientes para depositar
  }

  char cpf[TAM_CPF];
  float valor;
  printf("Digite o CPF do cliente: ");
  scanf("%14s", cpf);
  clearBuffer();

  int clienteEncontrado = 0;
  for (int i = 0; i < numClientes; i++) {
    if (strcmp(lista[i].cpf, cpf) == 0) {
      clienteEncontrado = 1;
      printf("Digite o valor a ser depositado: ");
      scanf("%f", &valor);
      clearBuffer();

      if (valor <= 0) {
        printf("Valor inválido para depósito.\n");
        return 0.0; // Retorna 0.0 se o valor for inválido
      }

      lista[i].saldo += valor;
      printf("Depósito de %.2f realizado com sucesso.\n", valor);
      return valor; // Retorna o valor do depósito realizado
    }
  }

  if (!clienteEncontrado) {
    printf("Cliente não encontrado.\n");
  }

  return 0.0; // Retorna 0.0 se o cliente não for encontrado
}


void extrato(struct Cliente lista[], int numClientes, float debito, float deposito) {
    if (numClientes == 0) {
        printf("Não foi possível realizar o extrato. Não há clientes cadastrados.\n");
        return;
    }

    char cpf[TAM_CPF];
    char senha[TAM_SENHA];
    printf("Digite o seu CPF: ");
    scanf("%14s", cpf);
    clearBuffer();

    printf("Digite a sua senha: ");
    scanf("%49s", senha);
    clearBuffer();

    int clienteEncontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(lista[i].cpf, cpf) == 0 && strcmp(lista[i].senha, senha) == 0) {
            clienteEncontrado = 1;

            FILE *arquivo = fopen("extrato.txt", "a");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo de extrato.\n");
                return;
            }

            fprintf(arquivo, "Extrato de Operações:\n");
            fprintf(arquivo, "Nome: %s\n", lista[i].nome);
            fprintf(arquivo, "Sobrenome: %s\n", lista[i].sobrenome);
            fprintf(arquivo, "CPF: %s\n", lista[i].cpf);
            fprintf(arquivo, "Saldo atual: %.2f\n", lista[i].saldo);
            fprintf(arquivo, "Tipo de conta: %s\n", lista[i].tipoConta);

            if (debito != 0) {
                fprintf(arquivo, "Débito: %.2f\n", debito);
                lista[i].saldo -= debito;
            } else {
                fprintf(arquivo, "Nenhum débito realizado.\n");
            }

            if (deposito != 0) {
                fprintf(arquivo, "Depósito: %.2f\n", deposito);
                lista[i].saldo += deposito;
            } else {
                fprintf(arquivo, "Nenhum depósito realizado.\n");
            }

            fprintf(arquivo, "\n");

            fclose(arquivo);
            printf("Extrato gerado com sucesso. Consulte o arquivo 'extrato.txt'.\n");
            return;
        }
    }

    if (!clienteEncontrado) {
        printf("CPF ou senha incorretos. Não foi possível gerar o extrato.\n");
    }
}

informacoesCode salvarCliente(struct Cliente lista[], int *numContatos) {
  FILE *arquivo = fopen("Informações", "ab");
  if (arquivo == NULL)
    return ABRIR;

  int qtd = fwrite(lista, sizeof(struct Cliente), 1000, arquivo);
  if (qtd == 0)
    return ESCREVER;

  qtd = fwrite(numContatos, sizeof(int), 1, arquivo);
  if (qtd == 0)
    return ESCREVER;

  if (fclose(arquivo) != 0)
    return FECHAR;

  return 0;
}

informacoesCode carregaCliente(struct Cliente lista[], int *numContatos) {
  FILE *arquivo = fopen("Informações", "rb");
  if (arquivo == NULL)
    return ABRIR;

  int qtd = fread(lista, sizeof(struct Cliente), MAX_CLIENTES, arquivo);
  if (qtd == 0)
    return LER;

  *numContatos += qtd;

  qtd = fread(numContatos, sizeof(int), 1, arquivo);
  if (qtd != 1)
    return LER;

  if (fclose(arquivo) != 0)
    return FECHAR;

  return 0;
}

void transferencia(struct Cliente lista[], int numClientes) {
    char cpfOrigem[TAM_CPF];
    char cpfDestino[TAM_CPF];
    float valor;

    printf("Digite o CPF do cliente de origem: ");
    scanf("%14s", cpfOrigem);
    clearBuffer();

    printf("Digite o CPF do cliente de destino: ");
    scanf("%14s", cpfDestino);
    clearBuffer();

    int clienteOrigemEncontrado = 0;
    int clienteDestinoEncontrado = 0;
    int indexClienteOrigem = -1;
    int indexClienteDestino = -1;

    // Verifica se o cliente de origem existe
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(lista[i].cpf, cpfOrigem) == 0) {
            clienteOrigemEncontrado = 1;
            indexClienteOrigem = i;
            break;
        }
    }

    // Verifica se o cliente de destino existe
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(lista[i].cpf, cpfDestino) == 0) {
            clienteDestinoEncontrado = 1;
            indexClienteDestino = i;
            break;
        }
    }

    if (!clienteOrigemEncontrado) {
        printf("Cliente de origem não encontrado.\n");
        return;
    }

    if (!clienteDestinoEncontrado) {
        printf("Cliente de destino não encontrado.\n");
        return;
    }

    // Solicita o valor a ser transferido
    printf("Digite o valor a ser transferido: ");
    scanf("%f", &valor);
    clearBuffer();

    // Verifica se o saldo do cliente de origem é suficiente
    if (valor > lista[indexClienteOrigem].saldo) {
        printf("Saldo insuficiente para realizar a transferência.\n");
        return;
    }

    // Realiza a transferência
    lista[indexClienteOrigem].saldo -= valor;
    lista[indexClienteDestino].saldo += valor;

    printf("Transferência de %.2f realizada com sucesso de %s para %s.\n", valor, lista[indexClienteOrigem].cpf, lista[indexClienteDestino].cpf);
}
