#ifndef CADASTROCLIENTES_H
#define CADASTROCLIENTES_H

#include <algorithm>


#include <string>

#include <vector>

using namespace std;


// Classes referentes ao Cadastro de Clientes


class CadastroClientes {
public:

    // classe interna
    class Cliente {

    public:
 Cliente(int cpf){}

        Cliente(int cpf, string nome);

        int checarCPF() const;

        string checarNOME() const;

        static bool compararPorCPF(const Cliente& a, const Cliente& b) ;






    protected:

        int cpf;

        string nome;

        vector<int> filmesAlugados;
    };

void CheckNomePorCPF( int cpf) ;
    void cadastrarCliente(int cpf, string nome);

    bool clienteExistente(int cpf) const;

    void removerCliente(int cpf);

    void listarClientes() ;

    void ordenarClientes();

    Cliente* encontrarCliente(int cpf);


protected:

    vector<Cliente> clientes;

};


#endif // CADASTROCLIENTES_H

