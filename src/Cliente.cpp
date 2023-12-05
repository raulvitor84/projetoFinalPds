#include "Cliente.h"

#include <stdexcept>
#include <iostream>

Cliente::Cliente(string nome, string cpf){
	this->_nome = nome;
	this->_cpf = cpf;
}

Cliente::~Cliente() {}

string Cliente::getNome()
{
    return _nome;
}

string Cliente::getCPF()
{
    return _cpf;
}

void Cliente::setNome(string nome){
  try {
        if (nome.empty()) {
            throw invalid_argument("Nome nao pode ser vazio. ");
        }

	this->_nome = nome;
   } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;

}
}

void Cliente::setCPF(string cpf){
	this->_cpf = cpf;
}
