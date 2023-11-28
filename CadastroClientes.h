#ifndef CADASTROCLIENTES_H
#define CADASTROCLIENTES_H

#include <algorithm>


#include <string>

#include <vector>

using namespace std;


// Classes referentes ao Cadastro de Clientes pela separacao de 1/3 informada


class CadastroClientes {
public:

    // classe interna
    class Cliente {

    public:


        Cliente(string cpf, string nome);

        string checarCPF() const;

        string checarNOME() const;




    private:

        string cpf;

        string nome;


    };


    void cadastrarCliente(string cpf, string nome);

    bool clienteExistente(string cpf);

    void removerCliente(string cpf);

    void listarClientes() const;





private:

    vector<Cliente> clientes;

};


#endif // CADASTROCLIENTES_H

