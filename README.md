# Projeto Final PDS 2 "Locadora"

`Universidade Federal de Minas Gerais`

`Projeto: Desenvolvimento de um sistema de locadora de filmes`


Nosso projeto surgiu com o intuito de recriarmos um sistema de locação de filmes para uma locadora, sendo de certa forma
nostálgico, já que esse tipo de sistema foi substituido pelas plataformas de streaming.
Diante disso, esse projeto busca desenvolver esse mecanismo utilizando a linguagem c++, assim como as ferramentas aprendidas
ao longo do semestre, entre elas, programação orientada a objetos, modelagem, programação defensiva e desenvolvimente voltado a testes.

## Integrantes

* Esdras Framone Reis Neves
* Leonardo Felipe Donato Pires
* Pedro Nogueira Passos Moreira
* Raul Vitor de Resende

## Orientador

* Luiz Chaimowicz

# Visão Geral
O sistema proposto deve permitir cadastrar e remover clientes, diferentes tipos de mídias de filmes, além de realizar o controle por emissão de relatórios de locações de Fitas e Dvd's.
O projeto utiliza três classes principais: "Clientes", "Filmes", e "Locacao". Cada uma delas possui métodos específicos pautados pelos princípios da responsabilidade única.

# Dificuldades Encontradas
A maior dificuldade encontrada ocorreu na iminência da entrega do projeto, quando definimos ser necessário uma grande refatoração no código. 
As principais dificuldades foram: 

- Classes fortemente acopladas, tornando difícil a reutilização, testes e utilização de conceitos de OO.
  
- Presença de códigos duplicados em diferentes partes do sistema que dificultavam seu entendimento.
  
- Organização do código-fonte confusa e com métodos não convencionais.
  
- Uso excessivo de variáveis globais.

- Grande dificuldade na implementação de tratamentos de exceções e testes de unidade.

- Ausência de reusabilidade.

## Estrutura

CRC CARDS



[
  {
    "name": "Cliente",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Cadastrar novos clientes com CPF e nome",
      "Remover clientes existentes pelo CPF",
      "Verificar cadastro prévio do CPF",
      "Listar clientes ordenados \t",
      ""
    ],
    "collaborators": [
      "cpf",
      "nome"
    ]
  },
  {
    "name": "Filmes",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Cadastrar filmes com tipo de mídia (VHS ou DVD), quantidade, código, título e categoria (DVD's)",
      "Verificar a utilização prévia do código informado",
      "Remover filmes através do código",
      "Listar filmes de forma ordenada"
    ],
    "collaborators": [
      "_codigo",
      "_tipos",
      "_nome",
      "_quantidade",
      ""
    ]
  },
  {
    "name": "Midia ",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "definir o tipo de Mídia (D/F) e atributos privados ",
      "ler através de parêmetros informados",
      ""
    ],
    "collaborators": [
      ""
    ]
  },
  {
    "name": "Aluguel ",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Alugar filmes em estoque para clientes cadastrados ",
      "Armazenar locações realizadas de clientes e subtração de estoque",
      "Devolver filmes locados e reinseri-lo em estoque",
      "Gerar relatórios de locacao ",
      "Gerar relatórios de devolução e valores a serem pagos",
      "Listar o estoque de filmes disponíveis",
      ""
    ],
    "collaborators": [
      ""
    ]
  }
]
## Funcionamento
O correto funcionamento se dá através de inserção manual ou através de arquivos.txt de estruturas padronizadas:

* LA <Nome_do_Arquivo.txt>  : Lê um arquivo.txt de cadastro sequencial de filmes 
* CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD> : Cadastra um filme de características informadas
* RF <código> : Remove filme através do código 
* LF : Lista filmes por código cadastrado e suas características 
* CC <CPF> <Nome> : Cadastra um novo cliente através do CPF e Nome informado
* RC <CPF> : Remove um cliente através do CPF
* LC  : Lista Clientes ordenados por CPF
* AL <CPF> <Código1> … <Código N> :  Aluga (n)filmes para o cliente de CPF informado e imprime um relatório
* DV <CPF> : Realiza a devolução dos filmes previamente alugados
* FS : Finaliza sistema





# Documentação

<li> Clique aqui: <a href="Link do Doxygen"> </a></li>


# Conclusão

<li> O projeto prático da disciplina de PDSII envolveu a aplicação de conhecimentos aprendidos ao longo do semestre, incluindo o uso integral do GitHub, resolução de desafios de programação, e organização eficiente. O trabalho em equipe resultou em um sistema de controle para o problema proposto, destacando boas práticas de desenvolvimento de software.</li>


