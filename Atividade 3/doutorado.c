#include <stdio.h>

void receberNotas(float notas[], int quantidade) {
    int i;

    for (i = 0; i < quantidade; i++) {
        printf("digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
}

float calcularMedia(float notas[], int quantidade) {
    float soma = 0;
    int i;

    for (i = 0; i < quantidade; i++) {
        soma = soma + notas[i];
    }

    return soma / quantidade;
}

char gerarClassificacao(float media) {
    if (media >= 9.5 && media <= 10) {
        return 'A';
    }
    else if (media >= 8) {
        return 'B';
    }
    else if (media >= 7) {
        return 'C';
    }
    else if (media >= 6) {
        return 'D';
    }
    else {
        return 'E';
    }
}

int gerarAproveitamento(char classificacao) {
    if (classificacao == 'A' ||
        classificacao == 'B' ||
        classificacao == 'C') {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char disciplinas[100][100];
    char classificacoes[100];
    float medias[100];

    int quantidadeDisciplinas = 0;
    int quantidadeNotas;
    int opcao;
    int aproveitamento;

    do {
        printf("\nmenu:\n");
        printf("1 - cadastrar nova disciplina\n");
        printf("2 - consultar historico\n");
        printf("3 - encerrar\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {

            printf("\ndigite o nome da disciplina: ");
            scanf(" %[^\n]", disciplinas[quantidadeDisciplinas]);

            printf("digite a quantidade de notas (2 a 10): ");
            scanf("%d", &quantidadeNotas);

            while (quantidadeNotas < 2 || quantidadeNotas > 10) {
                printf("a quantidade de notas deve estar entre 2 e 10.\n");
                printf("digite novamente a quantidade de notas: ");
                scanf("%d", &quantidadeNotas);
            }

            float notas[10];

            receberNotas(notas, quantidadeNotas);

            medias[quantidadeDisciplinas] =
                calcularMedia(notas, quantidadeNotas);

            classificacoes[quantidadeDisciplinas] =
                gerarClassificacao(medias[quantidadeDisciplinas]);

            aproveitamento =
                gerarAproveitamento(classificacoes[quantidadeDisciplinas]);

            printf("\nresultado:\n");
            printf("disciplina: %s\n",
                   disciplinas[quantidadeDisciplinas]);
            printf("media: %.2f\n",
                   medias[quantidadeDisciplinas]);
            printf("classificacao: %c\n",
                   classificacoes[quantidadeDisciplinas]);

            if (aproveitamento == 1) {
                printf("aproveitamento para o doutorado: sim\n");
            }
            else {
                printf("aproveitamento para o doutorado: nao\n");
            }

            quantidadeDisciplinas++;
        }

        else if (opcao == 2) {

            if (quantidadeDisciplinas == 0) {
                printf("\nainda nao existem disciplinas cadastradas.\n");
            }
            else {
                printf("\nhistorico:\n");

                for (int i = 0; i < quantidadeDisciplinas; i++) {

                    printf("\ndisciplina: %s\n", disciplinas[i]);
                    printf("media: %.2f\n", medias[i]);
                    printf("classificacao: %c\n", classificacoes[i]);

                    if (gerarAproveitamento(classificacoes[i]) == 1) {
                        printf("aproveitamento para o doutorado: sim\n");
                    }
                    else {
                        printf("aproveitamento para o doutorado: nao\n");
                    }
                }
            }
        }

        else if (opcao == 3) {
            printf("\nprograma encerrado.\n");
        }

        else {
            printf("\nopcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}