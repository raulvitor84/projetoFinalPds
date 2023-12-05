#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

/**
 * @brief Classe Cliente representa um cliente no sistema
 */
 
class Cliente
{
	public:
    /**
     * @brief Construtor da classe Cliente.
     * @param Nome do cliente.
     * @param CPF do cliente.
     */
		Cliente(string nome, string cpf);
		
    /**
     * @brief Destrutor da classe Cliente.
     */
    	virtual ~Cliente();

    /**
     * @brief Obtém o nome do cliente.
     * @return Nome 
     */
    	string getNome();
    	
    /**
     * @brief Obtém o CPF do cliente.
     * @return CPF 
     */    	
		string getCPF();
		
		
    /**
     * @brief Insere o nome do cliente.
     * @param Nome 
     */
		void setNome(string);
		
    /**
     * @brief Insere o CPF do cliente.
     * @param CPF 
     */		
		void setCPF(string);

    private:
        string _nome;///< Nome do Cliente
        string _cpf;///< CPF do Cliente
};

#endif // CLIENTE_H

