// ControleLocacao.cpp
#include "ControleLocacao.h"
#include <iostream>
#include <iomanip>

ControleLocacao::ControleLocacao(CadastroFilmes& filmes, CadastroClientes& clientes)
    : cadastroFilmes(filmes), cadastroClientes(clientes) {}

ControleLocacao::FilmeCodes ControleLocacao::obterFilmesValidos(const std::vector<std::string>& codigosFilmes) const {
    FilmeCodes filmesValidos;
    for (const auto& codigo : codigosFilmes) {
        if (filmeExiste(codigo)) {
            filmesValidos.push_back(codigo);
        } else {
            exibirErro("Filme inexistente: " + codigo);
        }
    }
    return filmesValidos;
}

bool ControleLocacao::clienteExiste(const std::string& cpf) const {
    return cadastroClientes.existeCliente(cpf);
}

bool ControleLocacao::filmeExiste(const std::string& codigo) const {
    return cadastroFilmes.existeFilme(codigo);
}

double ControleLocacao::calcularTotalPagar(const FilmeCodes& filmes) const {
    double totalPagar = 0.0;
    for (const auto& codigo : filmes) {
        totalPagar += cadastroFilmes.calcularValorLocacao(codigo);
    }
    return totalPagar;
}

bool ControleLocacao::clienteTemLocacaoEmAndamento(const std::string& cpf) const {
    return locacoes.find(cpf) != locacoes.end();
}

void ControleLocacao::exibirErro(const std::string& mensagem) const {
    std::cout << "ERRO: " << mensagem << std::endl;
}

void ControleLocacao::exibirErro(const char* mensagem) const {
    std::cout << "ERRO: " << mensagem << std::endl;
}

void ControleLocacao::exibirMensagem(const char* mensagem) const {
    std::cout << mensagem << std::endl;
}

void ControleLocacao::exibirMensagem(const char* mensagem, const FilmeCodes& filmes) const {
    std::cout << mensagem << std::endl;
    exibirFilmes(filmes);
}

void ControleLocacao::exibirMensagem(const char* mensagem, double valor) const {
    std::cout << mensagem << std::fixed << std::setprecision(2) << valor << std::endl;
}

void ControleLocacao::exibirMensagemReciboAluguel(const std::string& cpf) const {
    std::string nomeCliente = cadastroClientes.getNomeCliente(cpf);
    FilmeCodes filmesAlugados = locacoes.at(cpf);

    std::cout << "Recibo de Aluguel para Cliente: " << nomeCliente << " (CPF: " << cpf << ")\n";
    exibirFilmes(filmesAlugados);

    double totalPagar = calcularTotalPagar(filmesAlugados);
    exibirMensagem("Total a Pagar: ", totalPagar);
    exibirSeparador();
}

void ControleLocacao::exibirMensagemReciboDevolucao(const std::string& cpf, const FilmeCodes& filmes) const {
    std::string nomeCliente = cadastroClientes.getNomeCliente(cpf);

    std::cout << "Recibo de Devolução para Cliente: " << nomeCliente << " (CPF: " << cpf << ")\n";
    exibirFilmes(filmes);
    exibirSeparador();
}

void ControleLocacao::exibirMensagemCliente(const std::string& cpf) const {
    std::string nomeCliente = cadastroClientes.getNomeCliente(cpf);
    std::cout << "Cliente: " << nomeCliente << " (CPF: " << cpf << ")\n";
}

void ControleLocacao::exibirSeparador() const {
    std::cout << "--------------------------\n";
}

void ControleLocacao::exibirFilmes(const FilmeCodes& filmes) const {
    for (const auto& codigo : filmes) {
        std::cout << cadastroFilmes.getInfoFilme(codigo) << std::endl;
    }
}

bool ControleLocacao::validarEstoque(const FilmeCodes& filmes) const {
    for (const auto& codigo : filmes) {
        if (cadastroFilmes.calcularQuantidadeDisponivel(codigo) <= 0) {
            return false; // Estoque insuficiente para pelo menos um filme
        }
    }
    return true; // Estoque suficiente para todos os filmes
}

void ControleLocacao::atualizarEstoque(const FilmeCodes& filmes) {
    for (const auto& codigo : filmes) {
        cadastroFilmes.decrementarQuantidadeDisponivel(codigo);
    }
}

void ControleLocacao::alugarFilme(const std::string& cpf, const std::vector<std::string>& codigosFilmes) {
    if (!clienteExiste(cpf)) {
        exibirErro("Cliente inexistente");
        return;
    }

    FilmeCodes filmesAlugados = obterFilmesValidos(codigosFilmes);

    if (!validarEstoque(filmesAlugados)) {
        exibirErro("Estoque insuficiente para algum filme");
        return;
    }

    locacoes[cpf] = filmesAlugados;
    atualizarEstoque(filmesAlugados);

    exibirMensagemReciboAluguel(cpf);
}

void ControleLocacao::devolverFilme(const std::string& cpf) {
    if (!clienteExiste(cpf)) {
        exibirErro("Cliente inexistente");
        return;
    }

    if (!clienteTemLocacaoEmAndamento(cpf)) {
        exibirErro("Cliente não tem locação em andamento");
        return;
    }

    FilmeCodes filmesDevolvidos = locacoes[cpf];
    atualizarEstoque(filmesDevolvidos);

    exibirMensagemReciboDevolucao(cpf, filmesDevolvidos);

    double totalPagar = calcularTotalPagar(filmesDevolvidos);
    exibirMensagem("Total Pago: ", totalPagar);

    locacoes.erase(cpf);
}

void ControleLocacao::imprimirReciboAluguel(const std::string& cpf) {
    if (!clienteExiste(cpf) || !clienteTemLocacaoEmAndamento(cpf)) {
        exibirErro("Cliente inexistente ou sem locação em andamento");
        return;
    }

    exibirMensagemReciboAluguel(cpf);
}

void ControleLocacao::imprimirReciboDevolucao(const std::string& cpf) {
    if (!clienteExiste(cpf) || !clienteTemLocacaoEmAndamento(cpf)) {
        exibirErro("Cliente inexistente ou sem locação em andamento");
        return;
    }

    FilmeCodes filmesDevolvidos = locacoes[cpf];
    atualizarEstoque(filmesDevolvidos);

    exibirMensagemReciboDevolucao(cpf, filmesDevolvidos);
}

void ControleLocacao::exibirMenu() {
    // Implement your menu display logic here
}

// ... (rest of the class implementation)