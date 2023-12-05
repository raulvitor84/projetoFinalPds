// arquivo de teste (testes.cpp)
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Clientes.h"
#include "Filmes.h"
#include "Locacao.h"


TEST_CASE("Teste de Clientes") {
    Clientes cadastro;

    cadastro.Cliente(911222, "Raul Vitor");
    CHECK(cadastro.getCPF() == 911222);

    cadastro.Cliente(25896, "Lucas Moura");
    CHECK(cadastro.getCPF() == 25896);

    cadastro.Cliente(1010, "Esdras silva");
    CHECK(cadastro.getCPF() != 0000);

    cadastro.Cliente(101011, "Leonardo Alves");
    CHECK(cadastro.getCPF() == 101011);


    cadastro.Cliente(911222);
    CHECK(cadastro.//clienteExistente(911222) == false);

    cadastro.removeCliente(25896);
    CHECK(cadastro.//clienteExistente(25896) == false);


    cadastro.removeCliente(000145);
    CHECK(cadastro.//clienteExistente(1010) == true);

}






TEST_CASE("Teste de Filmes") {
    Filmes cadastro;

    cadastro.cadastraFilme('D', 12, 0000010, "O Rei Leao", "lancamentos");
    CHECK(cadastro.//codigoDeFilmeExistente(0000010) == true);


    cadastro.cadastraFilme('D', 7, 202020, "O Lobo de Wall Street", "estoque");
    CHECK(cadastro.//codigoDeFilmeExistente(202020) == true);


    cadastro.cadastraFilme('D', 8, 202021, "Wall-E", "estoque");
    CHECK(cadastro.//codigoDeFilmeExistente(202020) == true);


    cadastro.cadastraFilme('F', 2, 10101, "Mercenarios", "estoque");
    CHECK(cadastro.//codigoDeFilmeExistente(0101) == false);

    cadastro.removeFilme(10100);
    CHECK(cadastro.//codigoExistente(10100) == false);

    cadastro.removeFilme(202020);
    CHECK(cadastro.//codigoExistente(202020) == false);

    cadastro.removeFilme(000);
    CHECK(cadastro.//codigoExistente(0000010) == true);

}


TEST_CASE("Teste de Locacao") {
    Locacao locacao;


    locacao.alugaFilme(1010, {10101, 0000010, 202021});
    CHECK(locacao.//filmesAlugados.size() == 3);


    locacao.alugaFilme(101011, {0000010, 202021});
    CHECK(locacao.//filmesAlugados.size() == 2);

    locacao.devolveFilme(101011);
    CHECK(locadora.filmesAlugados.empty() == true);

    locacao.devolveFilme(1010);
    CHECK(locadora.filmesAlugados.empty() == true);

}






int main() {

    doctest::Context context;

    context.addFilter("TEST-CASE", "---------------TESTES DE FUNCIONALIDADE----------------");

return context.run();
}
