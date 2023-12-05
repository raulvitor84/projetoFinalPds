#include "ControleLocacao.h"
#include "CadastroClientes.h"
#include "CadastroFilmes.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Construtor para CPF
ControleLocacao::ControleLocacao(int cpf) : CadastroClientes::Cliente(to_string(cpf)) {}

// Construtor padrão
ControleLocacao::ControleLocacao() : CadastroClientes::Cliente("0", ""), CadastroFilmes('D', 0, 0, "", "") {}

// Construtor com parâmetros
ControleLocacao::ControleLocacao(int cpf, string nome, char tipoMidia, int quantidade, int codigoFilme, string titulo, string categoria)
    : CadastroClientes::Cliente(to_string(cpf), nome), CadastroFilmes(tipoMidia, quantidade, codigoFilme, titulo, categoria) {}

// Método para alugar um filme
void ControleLocacao::alugarFilme(int codigoFilme, int cpf) {
    CadastroFilmes filme = CadastroFilmes::obterFilmePorCodigo(codigoFilme);

    if (filme.checarCodigo() != 0) {
        filmesAlugados.push_back(filme);

        cout << "Cliente " << cpf << " alugou o filme: " << codigoFilme << endl;
    } else {
        cout << "ERRO: Filme com código " << codigoFilme << " não encontrado." << endl;
    }
}

// Método para devolver um filme
void ControleLocacao::devolverFilme(int codigoFilme, int cpf, int numeroDias) {
    auto it = find_if(filmesAlugados.begin(), filmesAlugados.end(),
                      [codigoFilme](const CadastroFilmes& filme) {
                          return filme.checarCodigo() == codigoFilme;
                      });

    if (it != filmesAlugados.end()) {
        CadastroFilmes& filme = *it;
        double valorFilme = 0.0;

        if (filme.checarTipoDeMidia() == 'D') { // DVD
            if (filme.checarCategoria() == "Lancamento") {
                valorFilme = 20.0 * numeroDias;
            } else if (filme.checarCategoria() == "Estoque") {
                valorFilme = 10.0 * numeroDias;
            } else if (filme.checarCategoria() == "Promocao") {
                valorFilme = 10.0;
            }
        } else if (filme.checarTipoDeMidia() == 'F') { // Fita de Vídeo
            valorFilme = 5.0;
            if (filme.checarCategoria() == "Rebobinada") {
                valorFilme += 2.0; // Multa por não rebobinar a fita
            }
        }

        cout << "Cliente " << cpf << " devolveu o filme " << codigoFilme << " após " << numeroDias << " dias." << endl;
        cout << "Valor a pagar: R$ " << valorFilme << endl;

        filmesAlugados.erase(it);
    } else {
        cout << "ERRO: Filme com código " << codigoFilme << " não encontrado." << endl;
    }
}
