#ifndef CONTROLELOCACAO_H
#define CONTROLELOCACAO_H

#include <string>
#include <vector>
#include <map>
#include "CadastroFilmes.h"
#include "CadastroClientes.h"

ControleLocacao::ControleLocacao(CadastroFilmes& filmes, CadastroClientes& clientes)
    : cadastroFilmes(filmes), cadastroClientes(clientes) {}

void ControleLocacao::alugarFilme(const std::string& cpf, const std::vector<std::string>& codigosFilmes) {
    if (!clienteExiste(cpf)) {
        exibirErro("CPF inexistente");
        return;
    }

    FilmeCodes filmesAlugados;
    std::string nomeCliente = cadastroClientes.getNomeCliente(cpf);

    for (const auto& codigo : codigosFilmes) {
        if (!filmeExiste(codigo)) {
            exibirErro("Filme inexistente: " + codigo);
        } else {
            filmesAlugados.push_back(codigo);
        }
    }

    locacoes[cpf] = filmesAlugados;

    exibirMensagem("Cliente " + cpf + " " + nomeCliente + " alugou os filmes:", filmesAlugados);
}