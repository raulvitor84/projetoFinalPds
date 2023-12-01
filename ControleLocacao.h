// ControleLocacao.h
#ifndef CONTROLELOCACAO_H
#define CONTROLELOCACAO_H

#include <string>
#include <vector>
#include <map>
#include "CadastroFilmes.h"
#include "CadastroClientes.h"

class ControleLocacao {
public:
    ControleLocacao(CadastroFilmes& filmes, CadastroClientes& clientes);

    void alugarFilme(const std::string& cpf, const std::vector<std::string>& codigosFilmes);
    void devolverFilme(const std::string& cpf);
    void imprimirReciboAluguel(const std::string& cpf);
    void imprimirReciboDevolucao(const std::string& cpf);
    void imprimirRelatorioLocacoesEmCurso();

private:
    using FilmeCodes = std::vector<std::string>;
    using LocacoesMap = std::map<std::string, FilmeCodes>;

    LocacoesMap locacoes; // CPF -> Lista de códigos de filmes alugados
    CadastroFilmes& cadastroFilmes;
    CadastroClientes& cadastroClientes;

    FilmeCodes obterFilmesValidos(const std::vector<std::string>& codigosFilmes) const;
    bool clienteExiste(const std::string& cpf) const;
    bool filmeExiste(const std::string& codigo) const;
    double calcularTotalPagar(const FilmeCodes& filmes) const;
    bool clienteTemLocacaoEmAndamento(const std::string& cpf) const;

    void exibirErro(const std::string& mensagem) const;
    void exibirMensagem(const std::string& mensagem, const FilmeCodes& filmes) const;
    void exibirMensagem(const std::string& mensagem, double valor) const;
    void exibirMensagemReciboAluguel(const std::string& cpf) const;
    void exibirMensagemReciboDevolucao(const std::string& cpf, const FilmeCodes& filmes) const;
    void exibirMensagemCliente(const std::string& cpf) const;
    void exibirSeparador() const;
    void exibirFilmes(const FilmeCodes& filmes) const;
};

#endif // CONTROLELOCACAO_H