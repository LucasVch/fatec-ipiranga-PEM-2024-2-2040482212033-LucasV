/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: *************
* Data - 25/10/2024                                             * 
* Autor: Giulia Diaz; Lucas Vinicius Silva*
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

void inserirProduto(Produto *produtos, int *cont);
void listarProdutos(Produto *produtos, int cont);
void comprarProduto(Produto *produtos, int cont);
void bubbleSort(Produto *produtos, int cont);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int cont = 0;
    int opcao;

    do {
        printf("\n--- Loja de Produtos Eletrônicos ---\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Comprar produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &cont);
                break;
            case 2:
                listarProdutos(produtos, cont);
                break;
            case 3:
                comprarProduto(produtos, cont);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

void inserirProduto(Produto *produtos, int *cont) {
    if (*cont >= MAX_PRODUTOS) {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }

    Produto p;
    printf("Digite o ID do produto: ");
    scanf("%d", &p.id);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Digite a descrição do produto: ");
    scanf(" %[^\n]", p.descricao);
    printf("Digite o preço do produto: ");
    scanf("%f", &p.preco);
    printf("Digite a quantidade disponível: ");
    scanf("%d", &p.quantidade);

    produtos[*cont] = p;
    (*cont)++;
    bubbleSort(produtos, *cont); // Ordena a lista após a inserção
}

void listarProdutos(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < cont; i++) {
        printf("ID: %d, Nome: %s, Descrição: %s, Preço: %.2f, Estoque: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].descricao, produtos[i].preco, produtos[i].quantidade);
    }
}

void comprarProduto(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto disponível para compra.\n");
        return;
    }

    int id, quantidade;
    printf("Digite o ID do produto que deseja comprar: ");
    scanf("%d", &id);

    // Busca o produto pelo ID
    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == id) {
            printf("Produto encontrado: %s\n", produtos[i].nome);
            printf("Digite a quantidade que deseja comprar: ");
            scanf("%d", &quantidade);

            if (quantidade > produtos[i].quantidade) {
                printf("Quantidade em estoque insuficiente!\n");
            } else {
                produtos[i].quantidade -= quantidade;
                printf("Compra realizada com sucesso!\n");
            }
            return;
        }
    }

    printf("Produto inexistente.\n");
}

void bubbleSort(Produto *produtos, int cont) {
    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}