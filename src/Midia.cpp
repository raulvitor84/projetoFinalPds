#include "Midia.h"

Midia::Midia(string tipo, string categoria, int quantidade, bool rebobinada){
	this->_tipo = tipo;
	this->_categoria = categoria;
    this->_quantidade = quantidade;
	this->_rebobinada = rebobinada;
}

Midia::~Midia() {}

string Midia::getTipo(){
    return _tipo;
}

string Midia::getCategoria(){
    return _categoria;
}

int Midia::getQuantidade(){
    return _quantidade;
}

bool Midia::getRebobinada(){
    return _rebobinada;
}

void Midia::setTipo(string tipo){
	this->_tipo = tipo;
}

void Midia::setCategoria(string categoria){
	this->_categoria = categoria;
}

void Midia::setQuantidade(int quantidade){
	this->_quantidade = quantidade;
}

void Midia::setRebobinada(bool rebobinada){
	this->_rebobinada = rebobinada;
}
