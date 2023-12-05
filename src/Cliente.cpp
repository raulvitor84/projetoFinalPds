#include "Cliente.h"

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
	this->_nome = nome;
}

void Cliente::setCPF(string cpf){
	this->_cpf = cpf;
}
