/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: *************
* Data - 20/09/2024                                             * 
* Autor: Giulia Diaz; Lucas Vinicius Silva*
*--------------------------------------------------------*/

#include <stdio.h>

#define MAX_PILHA 4

int pilha[MAX_PILHA];
int topo = -1;

// Funções auxiliares
void empilha(int valor) {
    if (topo == MAX_PILHA - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    pilha[++topo] = valor;
}

int desempilha() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return 0; // Retorna 0 em caso de erro
    }
    return pilha[topo--];
}

// Função principal
int main() {
    char entrada[100];
    int num1, num2, resultado;

    do {
        printf("Digite a expressão em RPN: ");
        fgets(entrada, 100, stdin);

        // Lógica de processamento da entrada (simplificada para fins didáticos)
        for (int i = 0; entrada[i] != '\0'; i++) {
            if (isdigit(entrada[i])) {
                // É um operando, empilha
                empilha(entrada[i] - '0');
            } else {
                // É um operador
                num2 = desempilha();
                num1 = desempilha();
                switch (entrada[i]) {
                    case '*':
                        resultado = num1 * num2;
                        break;
                    case '/':
                        resultado = num1 / num2;
                        break;
                    case '+':
                        resultado = num1 + num2;
                        break;
                    case '-':
                        resultado = num1 - num2;   

                        break;
                    default:
                        printf("Operador inválido!\n");
                        return   
 1;
                }
                empilha(resultado);
            }
        }

        // Resultado final está no topo da pilha
        printf("Resultado: %d\n", desempilha());

        printf("Deseja continuar? (s/n): ");
    } while (getchar() == 's');

    printf("Obrigado por usar nossa Calculadora Fatec-HP12c\n");
    return 0;
}