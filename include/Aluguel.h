#ifndef ALUGUEL_H
#define ALUGUEL_H

#include "Filme.h"

#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Classe que gerencia operações de aluguel e devolução dos filmes.
 */



class Aluguel
{
	public:
    /**
     * @brief Construtor da classe Aluguel.
     * @param filmes_disponiveis Ponteiro para o vetor de filmes disponíveis.
     */
		Aluguel(vector<Filme>& filmes_disponiveis);


    /**
     * @brief Destrutor da classe Aluguel.
     */
		virtual ~Aluguel();


    /**
     * @brief Aluga um filme para um cliente.
     * @param cpf CPF do cliente.
     * @param filmes_alugados Vetor de (n)filmes a serem alugados.
     */

		void alugaFilmes(string cpf, vector<Filme> filmes_alugados);


    /**
     * @brief Devolução de filmes por um cliente.
     * @param cpf CPF do cliente.
     */

		void devolveFilmes(string cpf, vector<Cliente>, int);

    private:
        map<string, vector<Filme>> _alugueis; /**< Mapa que armazena os filmes alugados por cada cliente. */
        vector<Filme> *_filmes_disponiveis; /**< Vetor de filmes disponíveis para aluguel. */
};

#endif // ALUGUEL_H
