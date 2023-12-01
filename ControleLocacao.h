#include "ControleLocacao.h"
#include <iomanip>

ControleLocacao::ControleLocacao(CadastroFilmes& filmes, CadastroClientes& clientes)
    : cadastroFilmes(filmes), cadastroClientes(clientes) {}