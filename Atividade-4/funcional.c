#include <stdio.h>

typedef struct {
    char nome[100];
    float media;
    char classificacao;
} Disciplina;

void receberNotas(float notas[], int quantidade, int indice) {
    if (indice < quantidade) {
        printf("digite a nota %d: ", indice + 1);
        scanf("%f", &notas[indice]);

        receberNotas(notas, quantidade, indice + 1);
    }
}

int receberQuantidadeNotas() {
    int quantidade;

    printf("digite a quantidade de notas (2 a 10): ");
    scanf("%d", &quantidade);

    if (quantidade < 2 || quantidade > 10) {
        printf("a quantidade de notas deve estar entre 2 e 10.\n");
        return receberQuantidadeNotas();
    }

    return quantidade;
}

float somarNotas(const float notas[], int quantidade, int indice) {
    if (indice == quantidade) {
        return 0;
    }

    return notas[indice] + somarNotas(notas, quantidade, indice + 1);
}

float calcularMedia(const float notas[], int quantidade) {
    return somarNotas(notas, quantidade, 0) / quantidade;
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

    return 0;
}

Disciplina cadastrarDisciplina() {
    Disciplina disciplina;
    float notas[10];
    int quantidadeNotas;

    printf("\ndigite o nome da disciplina: ");
    scanf(" %[^\n]", disciplina.nome);

    quantidadeNotas = receberQuantidadeNotas();

    receberNotas(notas, quantidadeNotas, 0);

    disciplina.media = calcularMedia(notas, quantidadeNotas);

    disciplina.classificacao =
        gerarClassificacao(disciplina.media);

    return disciplina;
}

void mostrarResultado(const Disciplina *disciplina) {
    printf("\nresultado:\n");
    printf("disciplina: %s\n", disciplina->nome);
    printf("media: %.2f\n", disciplina->media);
    printf("classificacao: %c\n", disciplina->classificacao);

    if (gerarAproveitamento(disciplina->classificacao)) {
        printf("aproveitamento para o doutorado: sim\n");
    }
    else {
        printf("aproveitamento para o doutorado: nao\n");
    }
}

void mostrarHistorico(const Disciplina historico[], int quantidade, int indice) {
    if (indice < quantidade) {
        printf("\ndisciplina: %s\n", historico[indice].nome);
        printf("media: %.2f\n", historico[indice].media);
        printf("classificacao: %c\n", historico[indice].classificacao);

        if (gerarAproveitamento(historico[indice].classificacao)) {
            printf("aproveitamento para o doutorado: sim\n");
        }
        else {
            printf("aproveitamento para o doutorado: nao\n");
        }

        mostrarHistorico(historico, quantidade, indice + 1);
    }
}

void executarMenu(Disciplina historico[], int quantidadeDisciplinas) {
    int opcao;

    printf("\nmenu:\n");
    printf("1 - cadastrar nova disciplina\n");
    printf("2 - consultar historico\n");
    printf("3 - encerrar\n");
    printf("escolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        historico[quantidadeDisciplinas] = cadastrarDisciplina();

        mostrarResultado(&historico[quantidadeDisciplinas]);

        executarMenu(historico, quantidadeDisciplinas + 1);
    }
    else if (opcao == 2) {
        if (quantidadeDisciplinas == 0) {
            printf("\nainda nao existem disciplinas cadastradas.\n");
        }
        else {
            printf("\nhistorico:\n");
            mostrarHistorico(historico, quantidadeDisciplinas, 0);
        }

        executarMenu(historico, quantidadeDisciplinas);
    }
    else if (opcao == 3) {
        printf("\nprograma encerrado.\n");
    }
    else {
        printf("\nopcao invalida.\n");

        executarMenu(historico, quantidadeDisciplinas);
    }
}

int main() {
    Disciplina historico[100];

    executarMenu(historico, 0);

    return 0;
}