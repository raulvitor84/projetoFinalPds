#include "Filme.h"

Filme::Filme(string codigo, string nome, vector<Midia> *tipos){
	this->_codigo = codigo;
    //this->_tipos = tipos;
	this->_nome = nome;

    this->_quantidade = 0;
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
    //falta verificar se midia ja existe...
    this->_tipos.push_back(midia);
    this->_quantidade += midia.getQuantidade();
}

void Filme::setNome(string nome){
	this->_nome = nome;
}
