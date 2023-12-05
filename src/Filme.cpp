#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include "Midia.h"

using namespace std;

class Filme
{
	public:
		Filme(string codigo, string nome, int quantidade, vector<Midia> *tipos = nullptr);
		virtual ~Filme();

		string getCodigo();
        string getNome();
        vector<Midia> getTipos();
        int getQuantidade();

		void setCodigo(string);
        void addTipos(Midia);
        void setNome(string);
        void setQuantidade(int);

    private:
        string _codigo;
        vector<Midia> _tipos;
        string _nome;
        int _quantidade;
};

#endif // FILME_H
