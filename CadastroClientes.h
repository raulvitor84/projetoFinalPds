#ifndef CADASTROCLIENTES_H
#define CADASTROCLIENTES_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class CadastroClientes {
public:

    CadastroClientes Cliente( string cpf,  string nome);

     string getCPF();

     string getNome();

    void cadastrarCliente( string cpf,  string nome);


    bool clienteExistente( string cpf);


private:

  vector<CadastroClientes> clientes;

  string cpf;

  string nome;

};


#endif // CADASTROCLIENTES_H
