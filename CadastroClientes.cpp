#include "CadastroClientes.h"

 CadastroClientes CadastroClientes::Cliente( string cpf,  string nome) {}

string CadastroClientes::getCPF()  {
    return cpf;
}

string CadastroClientes::getNome()  {
    return nome;
}





void CadastroClientes::cadastrarCliente( string cpf,  string nome) {

        if (clienteExistente(cpf)) {
            cout <<"okk"<< endl;
        } else {

                clientes.push_back(Cliente(cpf, nome));
               cout << cpf << nome <<  endl;
            }

}


bool CadastroClientes::clienteExistente( string cpf)  {
        for ( auto cliente : clientes) {
            if (cliente.getCPF() == cpf) {
                return true;
            }
        }
        return false;
}

