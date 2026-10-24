def receber_notas(quantidade):
    notas = []

    for i in range(quantidade):
        nota = float(input(f"digite a nota {i + 1}: "))
        notas.append(nota)

    return tuple(notas)  #funcional: imutabilidade, pois a tupla não pode ser alterada depois de criada


def calcular_media(notas):
    return sum(notas) / len(notas)  #funcional: função pura, pois recebe dados e retorna um resultado sem alterar dados externos


def verificar_status(media):
    if media >= 7:
        return "aprovado"
    elif media >= 5:
        return "reposição"
    return "reprovado"  #funcional: função pura, pois depende apenas do valor recebido


def gerar_classificacao(media):
    if media >= 9:
        return "muito boa"
    elif media >= 7:
        return "boa"
    elif media >= 5:
        return "regular"
    return "insuficiente"  #funcional: função pura, pois transforma uma entrada em uma saída sem modificar o estado do programa


def main():
    historico = []
    opcao = 1

    while opcao != 3:
        print("\n- sistema academico -")
        print("1. cadastrar disciplina")
        print("2. consultar historico")
        print("3. sair")

        opcao = int(input("escolha uma opcao: "))

        if opcao == 1:  #imperativo: sequência de comandos e alteração de estado
            aluno = input("digite o nome do aluno: ")
            disciplina = input("digite o nome da disciplina: ")
            quantidade = int(input("digite a quantidade de notas: "))

            while quantidade < 2 or quantidade > 10:
                print("digite entre 0 a 10")
                quantidade = int(input("digite novamente: "))

            notas = receber_notas(quantidade)
            media = calcular_media(notas)
            status = verificar_status(media)
            classificacao = gerar_classificacao(media)

            historico.append((aluno, disciplina, media, classificacao, status))  #imperativo: estado mutável, pois a lista historico é alterada

            print("\n- resultado -")
            print("aluno:", aluno)
            print("disciplina:", disciplina)
            print("media:", round(media, 2))
            print("classificacao:", classificacao)
            print("situacao:", status)

        elif opcao == 2:  #imperativo: estrutura de decisão
            if not historico:
                print("\nainda nao existem disciplinas cadastradas.")
            else:
                print("\n- historico -")
                for aluno, disciplina, media, classificacao, status in historico:  #imperativo: estrutura de repetição
                    print("\naluno:", aluno)
                    print("disciplina:", disciplina)
                    print("media:", round(media, 2))
                    print("classificacao:", classificacao)
                    print("situacao:", status)

        elif opcao == 3:
            print("\nfim")
        else:
            print("\ninvalido")


main()
