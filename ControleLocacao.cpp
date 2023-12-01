// ControleLocacao.cpp
#include "ControleLocacao.h"
#include <iomanip> // Para formatar a saída monetária

ControleLocacao::ControleLocacao(CadastroFilmes& filmes, CadastroClientes& clientes)
    : cadastroFilmes(filmes), cadastroClientes(clientes) {}

void ControleLocacao::alugarFilme(const std::string& cpf, const std::vector<std::string>& codigosFilmes) {
    if (!cadastroClientes.existeCliente(cpf)) {
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return;
    }

    std::vector<std::string> filmesAlugados;
    std::string nomeCliente = cadastroClientes.getNomeCliente(cpf);

    for (const auto& codigo : codigosFilmes) {
        if (!cadastroFilmes.existeFilme(codigo)) {
            std::cout << "ERRO: Filme " << codigo << " inexistente" << std::endl;
        } else {
            filmesAlugados.push_back(codigo);
        }
    }

    locacoes[cpf] = filmesAlugados;

    std::cout << "Cliente " << cpf << " " << nomeCliente << " alugou os filmes:" << std::endl;
    for (const auto& codigo : filmesAlugados) {
        std::cout << cadastroFilmes.getInfoFilme(codigo) << std::endl;
    }
}

void ControleLocacao::devolverFilme(const std::string& cpf) {
    if (!cadastroClientes.existeCliente(cpf)) {
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return;
    }

    std::vector<std::string> filmesDevolvidos = locacoes[cpf];
    std::string nomeCliente = cadastroClientes.getNomeCliente(cpf);

    std::cout << "Cliente " << cpf << " " << nomeCliente << " devolveu os filmes:" << std::endl;
    double totalPagar = 0.0;

    for (const auto& codigo : filmesDevolvidos) {
        std::cout << cadastroFilmes.getInfoFilme(codigo) << " [" << cadastroFilmes.calcularValorLocacao(codigo) << "]" << std::endl;
        totalPagar += cadastroFilmes.calcularValorLocacao(codigo);
    }

    std::cout << "Total a pagar: " << std::fixed << std::setprecision(2) << totalPagar << std::endl;

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