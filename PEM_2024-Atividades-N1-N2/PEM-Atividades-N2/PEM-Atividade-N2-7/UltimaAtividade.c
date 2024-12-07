/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: *************
* Data - 06/12/2024                                             * 
* Autor: Giulia Diaz; Lucas Vinicius Silva*
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

// Estrutura de produtos
typedef struct {
    int id;
    char nome[50];
    double valor;
    int quantidade;
} Produto;

// Função auxiliar para limpar buffer
void limparBuffer() {
    while (getchar() != '\n');
}

// Função para adicionar produtos
void incluirProduto(Produto *produtos, int *quantidade) {
    if (*quantidade >= MAX) {
        printf("Capacidade máxima atingida.\n");
        return;
    }

    Produto *novoProduto = &produtos[*quantidade];
    novoProduto->id = *quantidade + 1;

    printf("Nome do produto: ");
    scanf(" %[^\n]", novoProduto->nome);

    printf("Valor do produto: ");
    scanf("%lf", &novoProduto->valor);

    printf("Quantidade em estoque: ");
    scanf("%d", &novoProduto->quantidade);
    limparBuffer();

    (*quantidade)++;
    printf("Produto adicionado com sucesso! ID: %d\n", novoProduto->id);
}

// Função para consultar produto
void consultarProduto(Produto *produtos, int quantidade) {
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);
    limparBuffer();

    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].id == id) {
            printf("Produto encontrado:\n");
            printf("ID: %d\nNome: %s\nValor: %.2f\nQuantidade: %d\n",
                   produtos[i].id, produtos[i].nome, produtos[i].valor, produtos[i].quantidade);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para alterar produto
void alterarProduto(Produto *produtos, int quantidade) {
    int id;
    printf("Digite o ID do produto a ser alterado: ");
    scanf("%d", &id);
    limparBuffer();

    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].id == id) {
            printf("Novo nome do produto: ");
            scanf(" %[^\n]", produtos[i].nome);

            printf("Novo valor do produto: ");
            scanf("%lf", &produtos[i].valor);

            printf("Nova quantidade em estoque: ");
            scanf("%d", &produtos[i].quantidade);
            limparBuffer();

            printf("Produto atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para excluir produto
void excluirProduto(Produto *produtos, int *quantidade) {
    int id;
    printf("Digite o ID do produto a ser excluído: ");
    scanf("%d", &id);
    limparBuffer();

    for (int i = 0; i < *quantidade; i++) {
        if (produtos[i].id == id) {
            for (int j = i; j < *quantidade - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*quantidade)--;
            printf("Produto excluído com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para vender produto
void venderProduto(Produto *produtos, int quantidade) {
    int id, qtdVendida;
    printf("Digite o ID do produto vendido: ");
    scanf("%d", &id);

    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].id == id) {
            printf("Digite a quantidade vendida: ");
            scanf("%d", &qtdVendida);

            if (produtos[i].quantidade < qtdVendida) {
                printf("Estoque insuficiente.\n");
                return;
            }

            produtos[i].quantidade -= qtdVendida;
            printf("Venda realizada com sucesso! Estoque atualizado.\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

// Função para listar produtos
void listarProdutos(Produto *produtos, int quantidade) {
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("ID: %d\nNome: %s\nValor: %.2f\nQuantidade: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].valor, produtos[i].quantidade);
    }
}

// Função principal
int main() {
    Produto produtos[MAX];
    int quantidade = 0, opcao;

    do {
        printf("\nMenu:\n1. Incluir Produto\n2. Consultar Produto\n3. Alterar Produto\n4. Excluir Produto\n5. Vender Produto\n6. Listar Produtos\n7. Sair\nEscolha: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                incluirProduto(produtos, &quantidade);
                break;
            case 2:
                consultarProduto(produtos, quantidade);
                break;
            case 3:
                alterarProduto(produtos, quantidade);
                break;
            case 4:
                excluirProduto(produtos, &quantidade);
                break;
            case 5:
                venderProduto(produtos, quantidade);
                break;
            case 6:
                listarProdutos(produtos, quantidade);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 7);

    return 0;
}
