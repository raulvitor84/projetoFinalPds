#ifndef CADASTROFILMES_H
#define CADASTROFILMES_H


#include <algorithm>


#include <string>

#include <vector>

using namespace std;


// Classes referentes ao Cadastro de Filmes


class CadastroFilmes {
public:


    CadastroFilmes();

    CadastroFilmes(char tipoMidia, int quantidade, int codigoFilme, string titulo, string categoria);

    virtual ~CadastroFilmes();


    void cadastrarFilme(char tipoDeMidia, int quantidade, int codigoFilme, string titulo, string categoria);

    bool codigoExistente(int codigoFilme);

    void removerFilme(int codigoFilme);

    void listarFilmes() ;







        int checarCodigo() const;

        string checarTitulo() const;

        int checarQuantidade() const;


        char checarTipoDeMidia()const;

        string checarCategoria()const;

        static bool compararPorCodigo(const CadastroFilmes& a, const CadastroFilmes& b) ;
        void ordenarFilmes();

protected:


    vector<CadastroFilmes> filmes;

    int codigoFilme, quantidade;

    char tipoDeMidia;

    string titulo, categoria;
};



#endif // CADASTROFILMES_H
