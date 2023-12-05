#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

class Cliente
{
	public:
		Cliente(string nome, string cpf);
		virtual ~Cliente();

		string getNome();
		string getCPF();
		void setNome(string);
		void setCPF(string);

    private:
        string _nome;
        string _cpf;
};

#endif // CLIENTE_H
