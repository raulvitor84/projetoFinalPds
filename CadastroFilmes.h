// CadastroFilmes.h
#ifndef CADASTROFILMES_H
#define CADASTROFILMES_H

#include <string>
#include <vector>
#include <iostream>

// Enum para representar os tipos de mídia
enum class TipoMidia { DVD, Fita };

// Enum para representar as categorias de DVD
enum class CategoriaDVD { Lancamento, Estoque, Promocao };

class Filme {
public:
    Filme(const std::string& codigo, const std::string& titulo, int quantidade);
    virtual ~Filme() = default;

    const std::string& getCodigo() const;
    const std::string& getTitulo() const;
    int getQuantidade() const;
    virtual TipoMidia getTipo() const = 0;
    virtual double calcularValorLocacao(int dias) const = 0;
    virtual std::string getInfo() const = 0;

private:
    std::string codigo;
    std::string titulo;
    int quantidade;
};

class DVD : public Filme {
public:
    DVD(const std::string& codigo, const std::string& titulo, int quantidade, CategoriaDVD categoria);
    TipoMidia getTipo() const override;
    double calcularValorLocacao(int dias) const override;
    std::string getInfo() const override;

private:
    CategoriaDVD categoria;
};

class Fita : public Filme {
public:
    Fita(const std::string& codigo, const std::string& titulo, int quantidade, bool rebobinada);
    TipoMidia getTipo() const override;
    double calcularValorLocacao(int dias) const override;
    std::string getInfo() const override;

private:
    bool rebobinada;
};

class CadastroFilmes {
public:
    CadastroFilmes();
    ~CadastroFilmes();

    bool lerArquivoCadastro(const std::string& nomeArquivo);
    bool cadastrarFilme(TipoMidia tipo, int quantidade, const std::string& codigo, const std::string& titulo, CategoriaDVD categoria = CategoriaDVD::Estoque, bool rebobinada = true);
    bool removerFilme(const std::string& codigo);
    void listarFilmesOrdenadosPorCodigo() const;
    void listarFilmesOrdenadosPorTitulo() const;
    bool existeFilme(const std::string& codigo) const;
    double calcularValorLocacao(const std::string& codigo, int dias) const;
    std::string getInfoFilme(const std::string& codigo) const;

private:
    std::vector<Filme*> filmes;

    Filme* buscarFilme(const std::string& codigo) const;
};

#endif // CADASTROFILMES_H

