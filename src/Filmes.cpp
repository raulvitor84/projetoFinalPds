#include "CadastroFilmes.h"
#include <iostream>

CadastroFilmes::CadastroFilmes() {}

CadastroFilmes::CadastroFilmes(char tipoMidia, int quantidade, int codigoFilme, string titulo, string categoria)
    : tipoDeMidia(tipoMidia), quantidade(quantidade), codigoFilme(codigoFilme), titulo(titulo), categoria(categoria) {}

CadastroFilmes::~CadastroFilmes() {}

void CadastroFilmes::listarFilmes() {
    for (const auto& filme : filmes) {
        cout << filme.checarCodigo() << " " << filme.checarTitulo() << " " << filme.checarQuantidade() << endl;
    }
}

bool CadastroFilmes::codigoExistente(int codigoFilme) {
    for (const auto& filme : filmes) {
        if (filme.checarCodigo() == codigoFilme) {
            return true;
        }
    }
    return false;
}

void CadastroFilmes::removerFilme(int codigoFilme) {
    filmes.erase(remove_if(filmes.begin(), filmes.end(),
                           [codigoFilme](const CadastroFilmes& filme) {
                               return filme.checarCodigo() == codigoFilme;
                           }),
                 filmes.end());
}

int CadastroFilmes::checarCodigo() const {
    return codigoFilme;
}

string CadastroFilmes::checarTitulo() const {
    return titulo;
}

int CadastroFilmes::checarQuantidade() const {
    return quantidade;
}

char CadastroFilmes::checarTipoDeMidia() const {
    return tipoDeMidia;
}

string CadastroFilmes::checarCategoria() const {
    return categoria;
}

bool CadastroFilmes::compararPorCodigo(const CadastroFilmes& a, const CadastroFilmes& b) {
    return a.checarCodigo() < b.checarCodigo();
}

void CadastroFilmes::cadastrarFilme(char tipoDeMidia, int quantidade, int codigoFilme, string titulo, string categoria) {
    if (codigoExistente(codigoFilme)) {
        cout << "ERRO: Código repetido" << endl;
    } else {
        filmes.push_back(CadastroFilmes(tipoDeMidia, quantidade, codigoFilme, titulo, categoria));
        cout << "Filme " << codigoFilme << " cadastrado com sucesso" << endl;
    }
}

void CadastroFilmes::ordenarFilmes() {
    sort(filmes.begin(), filmes.end(), CadastroFilmes::compararPorCodigo);
}

CadastroFilmes CadastroFilmes::obterFilmePorCodigo(int codigoFilme) const {
    auto it = find_if(filmes.begin(), filmes.end(),
                      [codigoFilme](const CadastroFilmes& filme) {
                          return filme.checarCodigo() == codigoFilme;
                      });

    if (it != filmes.end()) {
        return *it;
    } else {
        // Retornar um filme com código 0 indicando que nenhum filme foi encontrado
        return CadastroFilmes('0', 0, 0, "", "");
    }
}
