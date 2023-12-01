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
};

#endif // CONTROLELOCACAO_H