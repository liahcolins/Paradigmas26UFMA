# ATIVIDADE 2 — SISTEMA DE MENU

**Nome:** Liah Renata Colins da Silva

## Descrição

Atividade simulando um sistema de menu bancário, com opções para consultar o saldo, realizar depósitos, realizar saques e encerrar o programa. O sistema atualiza o saldo de acordo com as operações realizadas e verifica se há saldo suficiente para efetuar um saque.

## Pseudocódigo

```text
início do programa

iniciar saldo

exibir menu com as opções:
    consultar saldo
    depositar
    sacar
    encerrar

solicitar opção desejada

se opção for consultar saldo, então
    exibir saldo disponível

senão se opção for depositar, então
    solicitar valor do depósito
    adicionar valor do depósito ao saldo
    exibir saldo atualizado

senão se opção for sacar, então
    solicitar valor do saque

    se saldo disponível for suficiente, então
        retirar valor do saque do saldo
        exibir saldo atualizado
    senão
        informar "Saldo insuficiente"

senão se opção for encerrar, então
    encerrar o programa

senão
    informar "Opção inválida"

fim do programa