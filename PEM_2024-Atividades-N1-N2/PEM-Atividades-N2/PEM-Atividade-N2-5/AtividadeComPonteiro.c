/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: *************
* Data - 06/11/2024                                             * 
* Autor: Giulia Diaz; Lucas Vinicius Silva*
*--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Estrutura para armazenar dados de um produto
typedef struct {
    int id;
    char nome[50];
    int quantidadeEmEstoque;
    double valorDoProduto;
} Produto;

// Funções de CRUD
void incluirProduto(Produto produtos[], int *contador);
void consultarProduto(Produto produtos[], int contador, int id);
void alterarProduto(Produto produtos[], int contador, int id);
void excluirProduto(Produto produtos[], int *contador, int id);
void imprimirProduto(Produto produto);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int contador = 0;
    int opcao, id;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Incluir produto\n");
        printf("2. Consultar produto\n");
        printf("3. Alterar produto\n");
        printf("4. Excluir produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirProduto(produtos, &contador);
                break;
            case 2:
                printf("Informe o ID do produto a consultar: ");
                scanf("%d", &id);
                consultarProduto(produtos, contador, id);
                break;
            case 3:
                printf("Informe o ID do produto a alterar: ");
                scanf("%d", &id);
                alterarProduto(produtos, contador, id);
                break;
            case 4:
                printf("Informe o ID do produto a excluir: ");
                scanf("%d", &id);
                excluirProduto(produtos, &contador, id);
                break;
            case 5:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
}

void incluirProduto(Produto produtos[], int *contador) {
    if (*contador >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    printf("Informe o ID do produto: ");
    scanf("%d", &produtos[*contador].id);
    printf("Informe o nome do produto: ");
    scanf("%s", produtos[*contador].nome);
    printf("Informe a quantidade em estoque: ");
    scanf("%d", &produtos[*contador].quantidadeEmEstoque);
    printf("Informe o valor do produto: ");
    scanf("%lf", &produtos[*contador].valorDoProduto);

    (*contador)++;
    printf("Produto incluído com sucesso.\n");
}

void consultarProduto(Produto produtos[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (produtos[i].id == id) {
            imprimirProduto(produtos[i]);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void alterarProduto(Produto produtos[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (produtos[i].id == id) {
            printf("Informe o novo nome do produto: ");
            scanf("%s", produtos[i].nome);
            printf("Informe a nova quantidade em estoque: ");
            scanf("%d", &produtos[i].quantidadeEmEstoque);
            printf("Informe o novo valor do produto: ");
            scanf("%lf", &produtos[i].valorDoProduto);
            printf("Produto alterado com sucesso.\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void excluirProduto(Produto produtos[], int *contador, int id) {
    for (int i = 0; i < *contador; i++) {
        if (produtos[i].id == id) {
            for (int j = i; j < *contador - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*contador)--;
            printf("Produto excluído com sucesso.\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void imprimirProduto(Produto produto) {
    printf("ID: %d\n", produto.id);
    printf("Nome: %s\n", produto.nome);
    printf("Quantidade em Estoque: %d\n", produto.quantidadeEmEstoque);
    printf("Valor do Produto: %.2lf\n", produto.valorDoProduto);
}
