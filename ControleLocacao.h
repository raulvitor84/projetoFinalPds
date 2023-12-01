#ifndef CONTROLELOCACAO_H
#define CONTROLELOCACAO_H

#include <iostream>
#include <vector>
#include <map>
#include "CadastroFilmes.h"
#include "CadastroClientes.h"

class ControleLocacao {
private:
    std::map<std::string, std::vector<std::string>> locacoes; // CPF -> Lista de códigos de filmes alugados
    CadastroFilmes& cadastroFilmes;
    CadastroClientes& cadastroClientes;

public:
    ControleLocacao(CadastroFilmes& filmes, CadastroClientes& clientes);

    void alugarFilme(const std::string& cpf, const std::vector<std::string>& codigosFilmes);
    void devolverFilme(const std::string& cpf);
    void imprimirReciboAluguel(const std::string& cpf);
    void imprimirReciboDevolucao(const std::string& cpf);
    void imprimirRelatorioLocacoesEmCurso();
};

#endif // CONTROLELOCACAO_H