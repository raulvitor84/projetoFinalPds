#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include "Midia.h"

using namespace std;

class Filme
{
	public:
    /**
     * @brief Construtor da classe Filme.
     * @param codigo (Código do filme).
     * @param nome (Nome do filme).
     * @param tipos (Vetor de tipos de mídia).
     */
		Filme(string codigo, string nome, vector<Midia> *tipos = nullptr);

    /**
     * @brief Destrutor da classe Filme.
     */
		virtual ~Filme();

    /**
     * @brief Obtém o código do filme.
     * @return Código do filme.
     */
		string getCodigo();
	/**

     * @brief Obtém o nome do filme.
     * @return Nome do filme.
     */
        string getNome();

    /**
     * @brief Obtém os tipos de mídia do filme.
     * @return Vetor de tipos de mídia.
     */
        vector<Midia> getTipos();

    /**
     * @brief Obtém a quantidade total de mídias de um filme
     * @return Quantidade total de mídias
     */
        int getQuantidade();


    /**
     * @brief Define o código do filme
     * @param Código do filme
     */

		void setCodigo(string);

    /**
     * @brief Adiciona um tipo de midia ao filme
     * @param Tipo de mídia a ser adicionado
     * @note Função também atualiza a quantidade total de mídias do filme
     */
        void addTipos(Midia);


    /**
     * @brief Define o nome do filme.
     * @param Nome do filme.
     */
        void setNome(string);

    private:
        string _codigo; ///< Codigo do filme
        vector<Midia> _tipos;///< Vetor de tipos de mídia
        string _nome;///< Nome do Filme
        int _quantidade;///< Quantidade de midias do filme em estoque
};

#endif // FILME_H
