// CadastroFilmes.cpp
#include "CadastroFilmes.h"
#include <fstream>
#include <algorithm>

Filme::Filme(const std::string& codigo, const std::string& titulo, int quantidade)
    : codigo(codigo), titulo(titulo), quantidade(quantidade) {}

const std::string& Filme::getCodigo() const {
    return codigo;
}

const std::string& Filme::getTitulo() const {
    return titulo;
}

int Filme::getQuantidade() const {
    return quantidade;
}

DVD::DVD(const std::string& codigo, const std::string& titulo, int quantidade, CategoriaDVD categoria)
    : Filme(codigo, titulo, quantidade), categoria(categoria) {}

TipoMidia DVD::getTipo() const {
    return TipoMidia::DVD;
}

double DVD::calcularValorLocacao(int dias) const {
    switch (categoria) {
        case CategoriaDVD::Lancamento:
            return 20.0 * dias;
        case CategoriaDVD::Estoque:
        case CategoriaDVD::Promocao:
            return 10.0 * dias;
    }
    return 0.0; // Categoria inválida
}

std::string DVD::getInfo() const {
    return codigo + " " + titulo + " " + std::to_string(quantidade) + " DVD";
}

Fita::Fita(const std::string& codigo, const std::string& titulo, int quantidade, bool rebobinada)
    : Filme(codigo, titulo, quantidade), rebobinada(rebobinada) {}

TipoMidia Fita::getTipo() const {
    return TipoMidia::Fita;
}

double Fita::calcularValorLocacao(int dias) const {
    double valor = 5.0 * dias;
    if (!rebobinada) {
        valor += 2.0; // Multa por fita não rebobinada
    }
    return valor;
}

std::string Fita::getInfo() const {
    return codigo + " " + titulo + " " + std::to_string(quantidade) + " Fita";
}

CadastroFilmes::CadastroFilmes() {}

CadastroFilmes::~CadastroFilmes() {
    // Limpar a memória alocada para os filmes
    for (auto& filme : filmes) {
        delete filme;
    }
}

bool CadastroFilmes::lerArquivoCadastro(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "ERRO: arquivo inexistente" << std::endl;
        return false;
    }

    TipoMidia tipo;
    int quantidade;
    std::string codigo, titulo, categoriaStr;

    while (arquivo >> codigo >> titulo >> quantidade >> categoriaStr) {
        std::transform(categoriaStr.begin(), categoriaStr.end(), categoriaStr.begin(), ::tolower);
        
        if (categoriaStr == "lancamento") {
            tipo = TipoMidia::DVD;
        } else if (categoriaStr == "estoque" || categoriaStr == "promocao") {
            tipo = TipoMidia::DVD;
        } else if (categoriaStr == "fita") {
            tipo = TipoMidia::Fita;
        } else {
            std::cerr << "ERRO: categoria inválida no arquivo de cadastro" << std::endl;
            return false;
        }

        if (!cadastrarFilme(tipo, quantidade, codigo, titulo, categoriaStr == "promocao")) {
            std::cerr << "ERRO: falha ao cadastrar filme do arquivo" << std::endl;
            return false;
        }
    }

    arquivo.close();
    return true;
}

bool CadastroFilmes::cadastrarFilme(TipoMidia tipo, int quantidade, const std::string& codigo, const std::string& titulo, CategoriaDVD categoria, bool rebobinada) {
    if (existeFilme(codigo)) {
        std::cerr << "ERRO: código repetido" << std::endl;
        return false;
    }

    Filme* novoFilme = nullptr;

    if (tipo == TipoMidia::DVD) {
        novoFilme = new DVD(codigo, titulo, quantidade, categoria);
    } else if (tipo == TipoMidia::Fita) {
        novoFilme = new Fita(codigo, titulo, quantidade, rebobinada);
    }

    if (novoFilme != nullptr) {
        filmes.push_back(novoFilme);
        std::cout << "Filme " << codigo << " cadastrado com sucesso" << std::endl;
        return true;
    } else {
        std::cerr << "ERRO: dados incorretos" << std::endl;
        return false;
    }
}

bool CadastroFilmes::removerFilme(const std::string& codigo) {
    auto it = std::remove_if(filmes.begin(), filmes.end(), [codigo](Filme* filme) {
        return filme->getCodigo() == codigo;
    });

    if (it != filmes.end()) {
        delete *it; // Libera a memória alocada para o filme
        filmes.erase(it, filmes.end());
        std::cout << "Filme " << codigo << " removido com sucesso" << std::endl;
        return true;
    } else {
        std::cerr << "ERRO: codigo inexistente" << std::endl;
        return false;
    }
}

void CadastroFilmes::listarFilmesOrdenadosPorCodigo() const {
    std::vector<Filme*> copiaFilmes = filmes;
    std::sort(copiaFilmes.begin(), copiaFilmes.end(), [](Filme* a, Filme* b) {
        return a->getCodigo() < b->getCodigo();
    });

    for (const auto& filme : copiaFilmes) {
        std::cout << filme->getInfo() << std::endl;
    }
}

void CadastroFilmes::listarFilmesOrdenadosPorTitulo() const {
    std::vector<Filme*> copiaFilmes = filmes;
    std::sort(copiaFilmes.begin(), copiaFilmes.end(), [](Filme* a, Filme* b) {
        return a->getTitulo() < b->getTitulo();
    });

    for (const auto& filme : copiaFilmes) {
        std::cout << filme->getInfo() << std::endl;
    }
}

bool CadastroFilmes::existeFilme(const std::string& codigo) const {
    return std::any_of(filmes.begin(), filmes.end(), [codigo](Filme* filme) {
        return filme->getCodigo() == codigo;
    });
}

double CadastroFilmes::calcularValorLocacao(const std::string& codigo, int dias) const {
    Filme* filme = buscarFilme(codigo);
    if (filme != nullptr) {
        return filme->calcularValorLocacao(dias);
    } else {
        std::cerr << "ERRO: Filme " << codigo << " inexistente" << std::endl;
        return 0.0;
    }
}

std::string CadastroFilmes::getInfoFilme(const std::string& codigo) const {
    Filme* filme = buscarFilme(codigo);
    if (filme != nullptr) {
        return filme->getInfo();
    } else {
        return "ERRO: Filme " + codigo + " inexistente";
    }
}

Filme* CadastroFilmes::buscarFilme(const std::string& codigo) const {
    auto it = std::find_if(filmes.begin(), filmes.end(), [codigo](Filme* filme) {
        return filme->getCodigo() == codigo;
    });

    return (it != filmes.end()) ? *it : nullptr;
}

