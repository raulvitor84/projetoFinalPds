#ifndef CONTROLELOCACAO_H
#define CONTROLELOCACAO_H

#include "CadastroClientes.h"
#include "CadastroFilmes.h"

class ControleLocacao : public CadastroClientes::Cliente, public CadastroFilmes {
public:
    ControleLocacao(int cpf);
    ControleLocacao();
    ControleLocacao(int cpf, string nome, char tipoMidia, int quantidade, int codigoFilme, string titulo, string categoria);

    void alugarFilme(int codigoFilme, int cpf);
    void devolverFilme(int codigoFilme, int cpf, int numeroDias);

private:
    vector<CadastroFilmes> filmesAlugados;
};

#endif // CONTROLELOCACAO_H