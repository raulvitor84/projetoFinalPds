// arquivo de teste (testes.cpp)
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Cliente.h"
#include "Filme.h"
#include "Aluguel.h"


TEST_CASE("Teste de Cliente") {
    Cliente cadastro;

    cadastro.Cliente(911222, "Raul Vitor");
    CHECK(cadastro.getCPF() == 911222);

    cadastro.Cliente(25896, "Lucas Moura");
    CHECK(cadastro.getCPF() == 25896);

    cadastro.Cliente(1010, "Esdras silva");
    CHECK(cadastro.getCPF() != 0000);

    cadastro.Cliente(101011, "Leonardo Alves");
    CHECK(cadastro.getCPF() == 101011);


    cadastro.removeCliente(911222);
    CHECK(cadastro.getCPF() != 911222);

    cadastro.removeCliente(25896);
    CHECK(cadastro.getCPF() != 25896);


 
}






TEST_CASE("Teste de Filme") {
    Filme cadastro;

    cadastro.Filme('D', 12, 0000010, "O Rei Leao", "lancamentos");
    CHECK(cadastro.getCodigo() == true);


    cadastro.Filme('D', 7, 202020, "O Lobo de Wall Street", "estoque");
    CHECK(cadastro.getCodigo() == true);


    cadastro.Filme('D', 8, 202021, "Wall-E", "estoque");
    CHECK(cadastro.getCodigo() == true);


    cadastro.Filme('F', 2, 10101, "Mercenarios", "estoque");
    CHECK(cadastro.getCodigo() == false);

    cadastro.removeFilme(10100);
    CHECK(cadastro.getCodigo() == false);

    cadastro.removeFilme(202020);
    CHECK(cadastro.getCodigo() == false);

    cadastro.removeFilme(000);
    CHECK(cadastro.getCodigo() == true);

}


TEST_CASE("Teste de Aluguel") {
    Aluguel locacao;


    locacao.alugaFilme(1010, {10101, 0000010, 202021});
    CHECK(locacao._alugueis.size() == 3);


    locacao.alugaFilme(101011, {0000010, 202021});
    CHECK(locacao._alugueis.size() == 2);

    locacao.devolveFilme(101011);
    CHECK(locacao._alugueis.empty() == true);

    locacao.devolveFilme(1010);
    CHECK(locacao._alugueis.empty() == true);

}






int main() {

    doctest::Context context;

    context.addFilter("TEST-CASE", "---------------TESTES DE FUNCIONALIDADE----------------");

return context.run();
}
