Alunos: Abraão Silva e Liah Renata Colins da Silva

Os dois paradigmas têm formas diferentes de pensar e organizar um programa.

---

# Documentação do Projeto: Sistema Académico em Orientação a Objetos

## 1. Contextualização e Objetivo

O presente trabalho consiste na refatoração de um sistema de gestão de notas académicas, originalmente estruturado sob os paradigmas imperativo e funcional (`prova.py`), para o paradigma da **Programação Orientada a Objetos (POO)** em Python. O objetivo principal é aumentar a organização, a segurança dos dados (encapsulamento) e a reutilização de código através da modelagem de entidades reais do domínio académico.

---

## 2. Arquitetura do Sistema (Diagrama de Classes)

A aplicação foi dividida em duas classes com responsabilidades bem definidas: uma para representar os dados e regras de negócio de cada avaliação (`AvaliacaoDisciplina`) e outra para gerir o fluxo de execução e armazenamento em memória (`SistemaAcademico`).

```text
+---------------------------------------------------+
|                SistemaAcademico                   |
+---------------------------------------------------+
| - __historico: list[AvaliacaoDisciplina]          |
+---------------------------------------------------+
| + __init__()                                      |
| - _receber_notas(quantidade: int): list[float]    |
| + cadastrar_disciplina(): void                    |
| + consultar_historico(): void                     |
| + iniciar(): void                                 |
+---------------------------------------------------+
                          | 1
                          | armazena e gere
                          | 0..*
                          v
+---------------------------------------------------+
|               AvaliacaoDisciplina                 |
+---------------------------------------------------+
| + aluno: str                                      |
| + disciplina: str                                 |
| - __notas: tuple[float, ...]                      |
+---------------------------------------------------+
| + __init__(aluno, disciplina, notas)              |
| + notas: tuple[float, ...]  <<property>>          |
| + calcular_media(): float                         |
| + verificar_status(): str                         |
| + gerar_classificacao(): str                      |
| + exibir_resumo(): void                           |
+---------------------------------------------------+

```

*(Legenda: `+` indica membros públicos; `-` indica membros privados/protegidos).*

---

## 3. Conceitos de POO Aplicados

* **Abstração:** O domínio do problema foi simplificado para representar apenas os atributos indispensáveis ao cálculo de rendimento escolar (`aluno`, `disciplina` e `notas`), ignorando informações irrelevantes para este contexto.
* **Classes e Objetos:** A classe `AvaliacaoDisciplina` atua como o molde estrutural. A cada novo registo efetuado no menu, o sistema instancia um objeto independente na memória (`avaliacao = AvaliacaoDisciplina(...)`), mantendo os dados de cada disciplina isolados.
* **Coesão (Atributos e Métodos):** As funções que antes recebiam variáveis externas (`calcular_media`, `verificar_status` e `gerar_classificacao`) foram integradas como métodos dentro da classe `AvaliacaoDisciplina`, passando a operar diretamente sobre o estado interno do próprio objeto através da referência `self`.
* **Encapsulamento e Imutabilidade:**
* Os atributos críticos (`self.__notas` e `self.__historico`) foram definidos como privados (prefixo `__`), impedindo alterações diretas e acidentais fora das suas respetivas classes.
* As notas são armazenadas internamente como uma tupla imutável (`tuple`) e expostas apenas para leitura controlada através do decorador `@property`.


* **Reutilização de Código (Princípio DRY):** A lógica de apresentação dos dados na consola foi centralizada no método `exibir_resumo()`, eliminando a duplicação de instruções `print()` que ocorria anteriormente entre as rotinas de cadastro e de consulta de histórico.

---

## 4. Comparativo Estrutural

| Critério | Abordagem Anterior (Procedural/Funcional) | Abordagem Atual (Orientada a Objetos) |
| --- | --- | --- |
| **Estrutura de Dados** | Tuplas genéricas armazenadas numa lista local dentro da função `main()`. | Instâncias tipadas da classe `AvaliacaoDisciplina` geridas por `SistemaAcademico`. |
| **Acoplamento** | Funções dependentes da passagem manual de parâmetros a cada chamada. | Métodos coesos que acedem diretamente aos atributos da própria instância (`self`). |
| **Integridade dos Dados** | Estado exposto no escopo de execução principal. | Estado protegido por modificadores de acesso privado e propriedades de leitura. |
| **Manutenção** | Alterações no formato de saída exigiam edição em múltiplos pontos do código. | Alterações no formato de exibição são feitas num único local (`exibir_resumo`). |
