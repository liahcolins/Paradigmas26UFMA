### Alunos: Abraão Silva e Liah Renata Colins da Silva

Os dois paradigmas têm formas diferentes de pensar e organizar um programa.

### Paradigma Imperativo

O paradigma **imperativo** se baseia na ideia de dizer ao computador **como fazer algo**, passo a passo, alterando o estado do programa.

Os principais pilares são:

* **Sequência:** instruções são executadas em uma determinada ordem.
* **Estado:** o programa possui valores que podem mudar durante sua execução.
* **Atribuição:** variáveis recebem e têm seus valores alterados.
* **Controle de fluxo:** uso de `if`, `else`, `for`, `while`, `switch` etc.
* **Procedimentos/comandos:** o programa é estruturado em ações que modificam o estado.

Exemplo:

```javascript
let x = 10;
x = x + 5;
console.log(x);
```

Aqui, `x` começa com `10` e depois seu estado é **modificado** para `15`.

A ideia central é:

> **“Faça isso, depois isso, altere essa variável e então faça aquilo.”**

---

### Paradigma Funcional

O paradigma **funcional** se baseia na ideia de tratar a computação como uma **avaliação de funções**, procurando evitar alterações de estado.

Os principais pilares são:

* **Funções como primeira classe:** funções podem ser armazenadas em variáveis, passadas como argumentos e retornadas por outras funções.
* **Imutabilidade:** procura-se não alterar os valores existentes, mas produzir novos valores.
* **Funções puras:** uma função, para uma mesma entrada, produz a mesma saída e evita efeitos colaterais.
* **Composição de funções:** funções menores podem ser combinadas para formar operações mais complexas.
* **Recursão:** frequentemente utilizada no lugar de estruturas de repetição tradicionais.
* **Funções de alta ordem:** funções que recebem outras funções ou retornam funções.
* **Ausência ou redução de efeitos colaterais:** evita-se modificar variáveis externas, arquivos, objetos compartilhados etc.

Exemplo:

```javascript
const numeros = [1, 2, 3, 4];

const dobrados = numeros.map(x => x * 2);

console.log(dobrados);
```

Em vez de alterar `numeros`, o programa cria um **novo resultado**.

A ideia central é:

> **“Descreva o que deve ser calculado por meio de funções e transformação de valores.”**

### Comparação rápida

| Imperativo                    | Funcional                                       |
| ----------------------------- | ----------------------------------------------- |
| Foco em **como fazer**        | Foco em **o que calcular**                      |
| Altera estado                 | Busca evitar alteração de estado                |
| Usa atribuições               | Prefere valores imutáveis                       |
| Loops são comuns              | `map`, `filter`, `reduce` e recursão são comuns |
| Efeitos colaterais são comuns | Busca minimizar efeitos colaterais              |
| Sequência de comandos         | Composição de funções                           |

Uma forma fácil de memorizar:

**Imperativo → comandos + estado + mudanças**

**Funcional → funções + imutabilidade + composição**

Vale observar que uma linguagem pode suportar **mais de um paradigma**. JavaScript, Python, C++ e Java, por exemplo, permitem programação imperativa e também vários recursos funcionais.
