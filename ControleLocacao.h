#include "ControleLocacao.h"
#include "CadastroClientes.h"
#include "CadastroFilmes.h"
#include <iostream>






ControleLocacao::ControleLocacao(int cpf) : CadastroClientes::Cliente(cpf) {}

 ControleLocacao::ControleLocacao() : CadastroClientes::Cliente(0, ""), CadastroFilmes('D', 0, 0, "", "") {}



ControleLocacao::ControleLocacao(int cpf, string nome, char tipoMidia, int quantidade, int codigoFilme, string titulo, string categoria)
        : CadastroClientes::Cliente(cpf, nome), CadastroFilmes(tipoMidia, quantidade, codigoFilme, titulo, categoria) {}












void ControleLocacao::alugarFilme(  int codigoFilme, int cpf)  {


        filmesAlugados.push_back(ControleLocacao( cpf, "", 'D', 0, codigoFilme,  "",  ""));


        cout << "Cliente " << cpf << " alugou o filme: " << codigoFilme << endl;



    for (const auto& testand : filmesAlugados) {
        cout << testand.cpf<< " " << testand.codigoFilme  << endl;
    }
}



void ControleLocacao::devolverFilme(int cpf) {

}
