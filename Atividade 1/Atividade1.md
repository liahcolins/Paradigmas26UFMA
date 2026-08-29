# ATIVIDADE 1: Compra de bebidas

**Nome:** Liah Renata Colins da Silva

## Descrição

Atividade simulando compras de produtos para maiores de idade, com quatro cenários possíveis que consideram a idade do cliente e o saldo disponível.

## Pseudocódigo

```text
início do programa

solicitar nome do cliente
solicitar idade
solicitar saldo disponível

produto = "bebida"
preço do produto = 15 reais

solicitar quantidade desejada

valor final = preço do produto × quantidade desejada

se idade maior ou igual a 18 e saldo disponível maior ou igual ao valor final, então
    saldo após a compra = saldo disponível - valor final

    gerar comprovante com:
        nome do cliente
        idade
        produto
        preço do produto
        quantidade desejada
        valor final
        saldo disponível
        saldo após a compra

senão se idade maior ou igual a 18 e saldo disponível menor que o valor final, então
    gerar comprovante com:
        "Cliente maior de 18 anos, mas sem saldo suficiente"

senão se idade menor que 18 e saldo disponível maior ou igual ao valor final, então
    gerar comprovante com:
        "Cliente menor de 18 anos"

senão
    gerar comprovante com:
        "Cliente menor de 18 anos e sem saldo suficiente"

fim do programa
```
