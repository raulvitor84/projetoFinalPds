#include "Filme.h"

#include <stdexcept>

#include<iostream>

Filme::Filme(string codigo, string nome, int quantidade, vector<Midia> *tipos){
try {
    if (codigo.empty() || nome.empty() ){
        throw std::invalid_argument("Argumentos inválidos.");
	}

    this->_codigo = codigo;
    this->_nome = nome;
    this->_quantidade = quantidade;

} catch (const exception& e){
    cerr << "Erro ao criar filme: " << e.what() << endl;
    throw;
    }
}



Filme::~Filme() {}

string Filme::getCodigo(){
    return _codigo;
}

vector<Midia> Filme::getTipos(){
    return _tipos;
}

string Filme::getNome(){
    return _nome;
}

int Filme::getQuantidade(){
    return _quantidade;
}

void Filme::setCodigo(string codigo){
	this->_codigo = codigo;
}

void Filme::addTipos(Midia midia){
    this->_tipos.push_back(midia);
}

void Filme::setNome(string nome){
	this->_nome = nome;
}

void Filme::setQuantidade(int qtd){
	this->_quantidade = qtd;
}
