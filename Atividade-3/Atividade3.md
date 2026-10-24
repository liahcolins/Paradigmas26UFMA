início do programa

criar vetor para armazenar as disciplinas
criar vetor para armazenar as classificações
definir quantidade de disciplinas cadastradas como 0

enquanto o usuário quiser cadastrar uma disciplina:

    solicitar nome da disciplina

    solicitar quantidade de notas

    enquanto quantidade de notas for menor que 2 ou maior que 10:
        informar "A quantidade de notas deve estar entre 2 e 10"
        solicitar novamente a quantidade de notas

    notas = receber notas(quantidade de notas)

    média = calcular média(notas, quantidade de notas)

    classificação = gerar classificação(média)

    aproveitamento = gerar aproveitamento(classificação)

    armazenar nome da disciplina no vetor de disciplinas
    armazenar média no vetor de médias
    armazenar classificação no vetor de classificações

    exibir:
        disciplina
        classificação
        aproveitamento para o doutorado

    aumentar quantidade de disciplinas cadastradas

    perguntar se o usuário deseja verificar o histórico das disciplinas cadastradas

    se quiser verificar o histórico, então
        exibir todas as disciplinas cadastradas com:
            nome da disciplina
            média
            classificação
            aproveitamento para o doutorado

    perguntar se o usuário deseja cadastrar outra disciplina

    se não quiser cadastrar outra disciplina, então
        encerrar o cadastro

fim do programa