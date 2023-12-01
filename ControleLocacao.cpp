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

void ControleLocacao::devolverFilme(const std::string& cpf) {
    if (!clienteExiste(cpf)) {
        exibirErro("CPF inexistente");
        return;
    }

    FilmeCodes filmesDevolvidos = locacoes[cpf];
    std::string nomeCliente = cadastroClientes.getNomeCliente(cpf);

    exibirMensagem("Cliente " + cpf + " " + nomeCliente + " devolveu os filmes:", filmesDevolvidos);

    double totalPagar = calcularTotalPagar(filmesDevolvidos);
    exibirMensagem("Total a pagar: ", totalPagar);

    locacoes.erase(cpf);
}

void ControleLocacao::imprimirReciboAluguel(const std::string& cpf) {
    // Implemente a lógica para imprimir o recibo de aluguel
}

void ControleLocacao::imprimirReciboDevolucao(const std::string& cpf) {
    // Implemente a lógica para imprimir o recibo de devolução
}

void ControleLocacao::imprimirRelatorioLocacoesEmCurso() {
    // Implemente a lógica para imprimir o relatório de todas as locações em curso
}

// Métodos auxiliares
bool ControleLocacao::clienteExiste(const std::string& cpf) const {
    return cadastroClientes.existeCliente(cpf);
}

bool ControleLocacao::filmeExiste(const std::string& codigo) const {
    return cadastroFilmes.existeFilme(codigo);
}

void ControleLocacao::exibirErro(const std::string& mensagem) const {
    std::cout << "ERRO: " << mensagem << std::endl;
}

void ControleLocacao::exibirMensagem(const std::string& mensagem, const FilmeCodes& filmes) const {
    std::cout << mensagem << std::endl;
    for (const auto& codigo : filmes) {
        std::cout << cadastroFilmes.getInfoFilme(codigo) << std::endl;
    }
}

void ControleLocacao::exibirMensagem(const std::string& mensagem, double valor) const {
    std::cout << mensagem << std::fixed << std::setprecision(2) << valor << std::endl;
}

double ControleLocacao::calcularTotalPagar(const FilmeCodes& filmes) const {
    double totalPagar = 0.0;
    for (const auto& codigo : filmes) {
        totalPagar += cadastroFilmes.calcularValorLocacao(codigo);
    }
    return totalPagar;
}