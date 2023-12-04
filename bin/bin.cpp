
#include "CadastroClientes.h"
#include <iostream>




// construtor da classe interna 'Cliente' q pertence a classe 'CadastroClientes'
CadastroClientes::Cliente::Cliente(int cpf, string nome) : cpf(cpf), nome(nome) {}



CadastroClientes::Cliente* CadastroClientes::encontrarCliente(int cpf) {
    for (auto& cliente : clientes) {
        if (cliente.checarCPF() == cpf) {
            return &cliente;
        }
    }
    return nullptr;
}







void CadastroClientes::cadastrarCliente(int cpf, string nome) {

    if (clienteExistente(cpf)) {

        cout << "ERRO: CPF repetido" << endl;

    } else {

        clientes.push_back(Cliente(cpf, nome));
        cout << "Cliente " << cpf << " cadastrado com sucesso" << endl;
    }
}





// A funcao verifica se um CPF fornecido (passado como parametro) ja existe no vetor (vector clientes). Ela é passada como "const" pois nao modifica o estado do objeto "CadastroClientes"
bool CadastroClientes::clienteExistente(int cpf) const {

    for (const auto& cliente : clientes) {
        if (cliente.checarCPF() == cpf) {
            return true;
        }
    }
    return false;
}


 void CadastroClientes::CheckNomePorCPF( int cpf)    {

    for (const auto& cliente : clientes) {
        if (cliente.checarCPF() == cpf) {

            cout << "Cliente " << cliente.checarCPF() << " " << cliente.checarNOME() << " " << "alugou os filmes: ";
        }
    }

}



void CadastroClientes::removerCliente(int cpf) {

    //A função remove_if() é usada para remover todos os valores do vector que correspondem a true para o predicado
    //o predicado verifica se o CPF do cliente é igual ao CPF passado como
    //argumento da funçao lambda exemplo:    ** Atribuindo o retorno da Lambda à uma variável =[variáveis já existentes](parametro para Lambda){ conteúdo no corpo da lambada} **

    auto it = remove_if(clientes.begin(), clientes.end(),[cpf](const Cliente& cliente) { return cliente.checarCPF() == cpf; });


    if (it != clientes.end()) { // checa se remove_if encontrou algum elemento para ser removido
        clientes.erase(it, clientes.end()); // remove os elementos a partir de it

        cout << "Cliente " << cpf << " removido com sucesso" << endl;

    } else {

        cout << "ERRO: CPF inexistente" << endl;
    }
}






int CadastroClientes::Cliente::checarCPF() const {
    return cpf;
}

string CadastroClientes::Cliente::checarNOME() const {
    return nome;
}

bool CadastroClientes::Cliente::compararPorCPF(const Cliente& a, const Cliente& b) {
        return a.checarCPF() < b.checarCPF();
}



// A  funcao exibe todos os clientes armazenados no vector 'clientes'
// utiliza um loop for que percorre todos os elementos de 'clientes' e declara uma referencia constante 'cliente' (não modifica o objeto CC)

void CadastroClientes::listarClientes()  {



    //sort(clientes.begin(), clientes.end(), compararPorCPF);



    for (const auto& cliente : clientes) {
        cout << cliente.checarCPF() << " " << cliente.checarNOME() << endl;
    }

}

void CadastroClientes::ordenarClientes() {
    sort(clientes.begin(), clientes.end(), Cliente::compararPorCPF);
}
