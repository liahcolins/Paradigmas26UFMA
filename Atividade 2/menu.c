#include <stdio.h>
#include <stdbool.h>

int main() {
    float saldo = 0;
    float valor;
    int opcao;
    bool encerrar = false;

    while (!encerrar) {
        printf("\n--- MENU ---\n");
        printf("1 - Consultar saldo\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Saldo disponivel: R$ %.2f\n", saldo);
        }
        else if (opcao == 2) {
            printf("Digite o valor do deposito: R$ ");
            scanf("%f", &valor);

            saldo = saldo + valor;

            printf("Deposito realizado\n");
            printf("Saldo atualizado: R$ %.2f\n", saldo);
        }
        else if (opcao == 3) {
            printf("Digite o valor do saque: R$ ");
            scanf("%f", &valor);

            if (valor <= saldo) {
                saldo = saldo - valor;

                printf("Saque realizado\n");
                printf("Saldo atualizado: R$ %.2f\n", saldo);
            }
            else {
                printf("Saldo insuficiente.\n");
            }
        }
        else if (opcao == 4) {
            encerrar = true;
            printf("Fim do programa.\n");
        }
        else {
            printf("Opção invalida.\n");
        }
    }

    return 0;
}