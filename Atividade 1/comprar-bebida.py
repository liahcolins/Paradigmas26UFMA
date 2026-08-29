nome_cliente = input("Digite o nome do cliente: ")
idade = int(input("Digite a idade: "))
saldo_disponivel = float(input("Digite o saldo disponível: R$ "))

produto = "bebida"
preco_produto = 15

quantidade_desejada = int(input("Digite a quantidade desejada: "))
valor_final = preco_produto * quantidade_desejada

if idade >= 18 and saldo_disponivel >= valor_final:
    saldo_final = saldo_disponivel - valor_final
    print("\n--- comprovante ---")
    print("Nome do cliente:", nome_cliente)
    print("Idade:", idade)
    print("Produto:", produto)
    print("Preço do produto: R$", preco_produto)
    print("Quantidade desejada:", quantidade_desejada)
    print("Valor final: R$", valor_final)
    print("Saldo disponível:", saldo_disponivel)
    print("Saldo após a compra:", saldo_final)

elif idade >= 18 and saldo_disponivel < valor_final:
    print("\n--- comprovante ---")
    print("Cliente maior de 18 anos, mas sem saldo suficiente")

elif idade < 18 and saldo_disponivel >= valor_final:
    print("\n--- comprovante ---")
    print("Cliente menor de 18 anos")

else:
    print("\n--- comprovante ---")
    print("Cliente menor de 18 anos e sem saldo suficiente")