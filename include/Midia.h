#ifndef MIDIA_H
#define MIDIA_H

#include <string>

using namespace std;


/**
 * @brief Classe Midia representa a m�dia no programa.
 */
class Midia
{
	public:
    /**
    * @brief Construtor da classe Midia.
    * @param Tipo da m�dia (DVD, Fita).
    * @param Categoria da m�dia ( Lan�amento, Estoque, Promo��o).
    * @param Quantidade dispon�vel da m�dia.
    * @param rebobinada Indica se a m�dia est� rebobinada (apenas para Fitas).
    */
		Midia(string tipo, string categoria, int quantidade, bool rebobinada);


       /**
        *@brief Destrutor da classe Midia.
        */
		virtual ~Midia();

       /**
        * @brief Obt�m o tipo da m�dia.
        * @return Tipo da m�dia.
        */

		string getTipo();


       /**
        * @brief Obt�m a categoria da m�dia.
        * @return Categoria da m�dia.
        */
		string getCategoria();

       /**
        * @brief Obt�m a quantidade dispon�vel da m�dia.
        * @return Quantidade dispon�vel da m�dia.
        */
		int getQuantidade();

       /**
        * @brief Verifica se a m�dia est� rebobinada (apenas para Fitas).
        * @return Verdadeiro se a m�dia est� rebobinada, falso caso contr�rio.
        */
		bool getRebobinada();



       /**
        * @brief Define o tipo da m�dia.
        * @param tipo Novo tipo da m�dia.
        */
		void setTipo(string);

	   /**
        * @brief Define a categoria da m�dia.
        * @param categoria Nova categoria da m�dia.
        */
		void setCategoria(string);

       /**
        * @brief Define a quantidade dispon�vel da m�dia.
        * @param quantidade Nova quantidade dispon�vel da m�dia.
        */
		void setQuantidade(int);

       /**
        * @brief Define se a m�dia est� rebobinada (apenas para Fitas).
        * @param rebobinada Novo estado de rebobinada da m�dia.
        */

		void setRebobinada(bool);

    private:
        string _tipo; //< Tipo de m�dia.
        string _categoria;///< Categoria da m�dia.
        int _quantidade;///< Quantidade da m�dia.
        bool _rebobinada;///< Indica se a fita esta rebobinada.
};

#endif�//�MIDIA_H
