#include "Filme.h"

Filme::Filme(string codigo, string nome, int quantidade, vector<Midia> *tipos){
	this->_codigo = codigo;
	this->_nome = nome;
    this->_quantidade = quantidade;
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
