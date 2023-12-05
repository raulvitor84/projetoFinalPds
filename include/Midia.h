#ifndef MIDIA_H
#define MIDIA_H

#include <string>

using namespace std;


/**
 * @brief Classe Midia representa a mídia no programa.
 */
class Midia
{
	public:
    /**
    * @brief Construtor da classe Midia.
    * @param Tipo da mídia (DVD, Fita).
    * @param Categoria da mídia ( Lançamento, Estoque, Promoção).
    * @param Quantidade disponível da mídia.
    * @param rebobinada Indica se a mídia está rebobinada (apenas para Fitas).
    */
		Midia(string tipo, string categoria, int quantidade, bool rebobinada);


       /**
        *@brief Destrutor da classe Midia.
        */
		virtual ~Midia();

       /**
        * @brief Obtém o tipo da mídia.
        * @return Tipo da mídia.
        */

		string getTipo();


       /**
        * @brief Obtém a categoria da mídia.
        * @return Categoria da mídia.
        */
		string getCategoria();

       /**
        * @brief Obtém a quantidade disponível da mídia.
        * @return Quantidade disponível da mídia.
        */
		int getQuantidade();

       /**
        * @brief Verifica se a mídia está rebobinada (apenas para Fitas).
        * @return Verdadeiro se a mídia está rebobinada, falso caso contrário.
        */
		bool getRebobinada();



       /**
        * @brief Define o tipo da mídia.
        * @param tipo Novo tipo da mídia.
        */
		void setTipo(string);

	   /**
        * @brief Define a categoria da mídia.
        * @param categoria Nova categoria da mídia.
        */
		void setCategoria(string);

       /**
        * @brief Define a quantidade disponível da mídia.
        * @param quantidade Nova quantidade disponível da mídia.
        */
		void setQuantidade(int);

       /**
        * @brief Define se a mídia está rebobinada (apenas para Fitas).
        * @param rebobinada Novo estado de rebobinada da mídia.
        */

		void setRebobinada(bool);

    private:
        string _tipo; //< Tipo de mídia.
        string _categoria;///< Categoria da mídia.
        int _quantidade;///< Quantidade da mídia.
        bool _rebobinada;///< Indica se a fita esta rebobinada.
};

#endif // MIDIA_H
