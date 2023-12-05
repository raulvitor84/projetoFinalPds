#include "Cliente.h"
#include "Filme.h"
#include "Midia.h"
#include "Aluguel.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

#define MAX_LEN 1000

void cadastraCliente(vector<Cliente>&, vector<string>&);
void removeCliente(vector<Cliente>&, vector<string>&);
void listaClientes(vector<Cliente>&);

void carregaFilmes(vector<Filme>&, vector<string>&);
void cadastraFilme(vector<Filme>&, vector<string>&);
void removeFilme(vector<Filme>&, vector<string>&);
void listaFilmes(vector<Filme>&, vector<string>&);

int main()
{
    vector<Filme> filmes;
    Aluguel *sistema_aluguel = new Aluguel(filmes);
	vector<string> info_entrada;
	vector<Cliente> clientes;

    char entrada[MAX_LEN], *p, *ss_comando;

	// Loop de entrada
	while (1) {
		cout << "Digite um comando:";
		cin.getline(entrada, MAX_LEN);

		ss_comando = strtok(entrada, " ");
		p = ss_comando;


  		while (ss_comando != NULL) {
        	info_entrada.push_back(ss_comando);
        	ss_comando = strtok(NULL, " ");
	  	}

		if(!strcmp(p,"LA")) carregaFilmes(filmes, info_entrada);
        else if(!strcmp(p,"CF")) cadastraFilme(filmes, info_entrada);
        else if(!strcmp(p,"RF")) removeFilme(filmes, info_entrada);
        else if(!strcmp(p,"LF")) listaFilmes(filmes, info_entrada);
        else if(!strcmp(p,"CC")) cadastraCliente(clientes, info_entrada);
        else if(!strcmp(p,"RC")) removeCliente(clientes, info_entrada);
        else if(!strcmp(p,"LC")) listaClientes(clientes);
        else if(!strcmp(p,"AL")){
                string cpf = info_entrada[1];
                bool cpf_existe = false;
                for(unsigned int j = 0; j < clientes.size(); j++){
                    cpf_existe = (clientes[j].getCPF() == info_entrada[1]) ? true : false;
                }
                if(!cpf_existe){
                    cout << "CPF inexistente." << endl;
                }else{

                auto it = find_if(clientes.begin(), clientes.end(), [cpf](Cliente& obj) {return obj.getCPF() == cpf;});
                string nome = clientes[distance(clientes.begin(), it)].getNome();


                vector<Filme> filmes_alugados;
                for(unsigned int i = 2; i < info_entrada.size(); i++){
                string codigo = info_entrada[i];
                    auto it = find_if(filmes.begin(), filmes.end(), [codigo](Filme& obj) {return obj.getCodigo() == codigo;});
                    if (it != filmes.end()){
                        filmes[distance(filmes.begin(), it)].getNome();
                        filmes_alugados.push_back(filmes[distance(filmes.begin(), it)]);
                    }else{
                        cout << "Filme "<< info_entrada[i] << " inexistente." << endl;
                    }
                }
                if(filmes_alugados.size() > 0){
                    sistema_aluguel->alugaFilmes(info_entrada[1], filmes_alugados);
                    cout << "Cliente " << info_entrada[1] << " " << nome << " alugou os filmes: " << endl;
                    for(unsigned int i = 0; i < filmes_alugados.size(); i++){
                        string tipo = (filmes_alugados[i].getTipos()[0].getTipo() == "D") ? "DVD" : "FITA";
                        cout << filmes_alugados[i].getCodigo() << " " << filmes_alugados[i].getNome() << " " << tipo << endl;
                    }
                }


                }
        }
        else if(!strcmp(p,"DV")){
           sistema_aluguel->devolveFilmes(info_entrada[1], clientes, stoi(info_entrada[2]));
        }
        else if(!strcmp(p,"FS")) break;
		info_entrada.clear();
	}
    return 0;
}

void cadastraCliente(vector<Cliente> &clientes, vector<string> &info_entrada){
    auto it = find_if(clientes.begin(), clientes.end(), [&info_entrada](Cliente& obj) {return obj.getCPF() == info_entrada[1];});
    if (it != clientes.end()){
        cout << "CPF repetido" << endl;
    }else{
        clientes.push_back(Cliente(info_entrada[2],info_entrada[1]));
        cout << "Cliente " << clientes.back().getCPF() << " cadastrado com sucesso!" << endl;
    }
}

void removeCliente(vector<Cliente> &clientes, vector<string> &info_entrada){
    auto it = find_if(clientes.begin(), clientes.end(), [&info_entrada](Cliente& obj) {return obj.getCPF() == info_entrada[1];});
    if (it != clientes.end()){
        clientes.erase(it);
        cout << "Cliente " << info_entrada[1] << " removido com sucesso!" << endl;
    }else{
        cout << "CPF inexistente." << endl;
    }
}

void listaClientes(vector<Cliente> &clientes){
	for(unsigned int i = 0; i < clientes.size(); i++){
		cout << clientes[i].getCPF() << " " << clientes[i].getNome() << endl;
	}
}

void carregaFilmes(vector<Filme> &filmes, vector<string> &info_entrada){
    ifstream arquivo(info_entrada[1]);
    string linha;
    string separador = " ";
    int n = 0, m = 0;

    // Tenta abrir o arquivo
    if (arquivo.is_open()) {
    while (!arquivo.eof() ) {
        getline (arquivo, linha);
        cout << linha << endl;
        n++;

        // Separa cada linha do arquivo em itens e salva no vector dados_filmes.
        size_t pos = 0;
        string item_linha;
        string nome = "";
        string categoria = "";
        string tipo = linha.substr(3,1);
        string codigo = "";
        bool rebobinada = true;
        int quantidade;

        if(tipo == "D"){
            categoria = linha.substr(linha.find_last_of(' ') + 1);
        }else if(tipo == "F"){
            categoria = "fita";
        }else{
            categoria = "erro";
        }


        while ((pos = linha.find(separador)) != string::npos) {
            item_linha = linha.substr(0, pos);
            // Concatena o nome do filme
            if(m > 3){
                nome += item_linha + " ";
            }
            // Salva a quantidade de filmes
            if(m == 3){
                codigo = item_linha;
            }
            if(m == 2){
                quantidade = stoi(item_linha);
            }
            m++;
            linha.erase(0, pos + separador.length());
        }


        // Dados disponiveis a partir daqui para serem registrados
        //cout << "Nome do filme: " << nome << endl;
        //cout << "Codigo: " << codigo << endl;
        //cout << "Quantidade: " << quantidade << endl;
        //cout << "Tipo: " << tipo << endl;
        //cout << "Categoria: " << categoria << endl;


        // Insercao dos dados do filme na estrutura de armazenamento
        // Antes de inserir, verifica se o filme já está cadastrado
        // Se estiver, apenas incrementa as suas midias com seus respectivos tipos
        // Se nao estiver, cria uma Midia e salva em um Filme

            unsigned int tamanho = filmes.size();
            bool contem = false;

            if(tamanho > 0){
                for(unsigned int i = 0; i < tamanho; i++){
                    if(filmes[i].getCodigo() == codigo){
                        contem = true;
                    }
                }
                if(contem){
                    cout << "ERRO: codigo " << codigo << " repetido." << endl;
                }else{
                // Adiciona um novo Filme
                Filme* filme = new Filme(codigo, nome, quantidade);
                filme->addTipos(Midia(tipo, categoria, quantidade, rebobinada));
                filmes.push_back(*filme);
                delete filme;
                }

            }else{
                Filme* filme = new Filme(codigo, nome, quantidade);
                filme->addTipos(Midia(tipo, categoria, quantidade, rebobinada));
                filmes.push_back(*filme);
                delete filme;
            }

        m = 0;
        nome = " ";
    }
    cout << "["<< n << "] Filmes cadastrados com sucesso" << endl;
    arquivo.close();
    } else {
        cout << "ERRO: arquivo inexistente." << endl;
    }
}

void cadastraFilme(vector<Filme> &filmes, vector<string> &info_entrada){

    string categoria = "";
    string nome = "";
    string codigo = info_entrada[3];
    int quantidade = stoi(info_entrada[2]);
    string tipo = info_entrada[1];
    bool rebobinada = true;

    if(tipo == "D"){
        categoria = info_entrada.back();
        for(unsigned int i = 4; i < info_entrada.size()-1; i++){
            nome += info_entrada[i] + " ";
        }
    }else if(tipo == "F"){
        categoria = "fita";
        for(unsigned int i = 4; i < info_entrada.size(); i++){
            nome += info_entrada[i] + " ";
        }
    }else{
        categoria = "erro";
        nome = "erro";
    }

    unsigned int tamanho = filmes.size();
    bool contem = false;

    if(tamanho > 0){
        for(unsigned int i = 0; i < tamanho; i++){
            if(filmes[i].getCodigo() == codigo){
                contem = true;
            }
        }
        if(contem){
            cout << "ERRO: codigo " << codigo << " repetido." << endl;
        }else{
            // Adiciona um novo Filme
            Filme* filme = new Filme(codigo, nome, quantidade);
            filme->addTipos(Midia(tipo, categoria, quantidade, rebobinada));
            filmes.push_back(*filme);
            delete filme;
        }

    }else{
        Filme* filme = new Filme(codigo, nome, quantidade);
        filme->addTipos(Midia(tipo, categoria, quantidade, rebobinada));
        filmes.push_back(*filme);
        delete filme;
    }
}

void removeFilme(vector<Filme> &filmes, vector<string> &info_entrada){
    auto it = find_if(filmes.begin(), filmes.end(), [&info_entrada](Filme& obj) {return obj.getCodigo() == info_entrada[1];});
    if (it != filmes.end()){
        filmes.erase(it);
        cout << "Filme " << info_entrada[1] << " removido com sucesso!" << endl;
    }else{
        cout << "Codigo inexistente" << endl;
    }
}

void listaFilmes(vector<Filme> &filmes, vector<string> &info_entrada){
    if(info_entrada[1] == "C"){
        sort( filmes.begin( ), filmes.end( ), [ ](Filme& lhs, Filme& rhs ){
            return lhs.getCodigo() < rhs.getCodigo();
        });
    }else{
        sort( filmes.begin( ), filmes.end( ), [ ](Filme& lhs, Filme& rhs ){
            return lhs.getNome() < rhs.getNome();
        });
    }
	for(unsigned int i = 0; i < filmes.size(); i++){
        vector<Midia> midia = filmes[i].getTipos();
        for(unsigned int j = 0; j < midia.size(); j++){
            string tipo = (midia[j].getTipo() == "D") ? "DVD" : "FITA";
            cout << filmes[i].getCodigo() << " " << filmes[i].getNome() << " " << filmes[i].getQuantidade() << " " << tipo << endl;
        }
	}
}
