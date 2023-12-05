#include "Aluguel.h"

Aluguel::Aluguel(vector<Filme>& filmes_disponiveis){
    this-> _filmes_disponiveis = &filmes_disponiveis;
}

Aluguel::~Aluguel() {}

void Aluguel::alugaFilmes(string cpf, vector<Filme> filmes_alugados){
    for(unsigned int i = 0; i < filmes_alugados.size(); i++){
        string codigo = filmes_alugados[i].getCodigo();
        auto it = find_if(_filmes_disponiveis->begin(), _filmes_disponiveis->end(), [codigo](Filme& obj) {return obj.getCodigo() == codigo;});
        if (it != _filmes_disponiveis->end()){
            int qtd = (_filmes_disponiveis->at(distance(_filmes_disponiveis->begin(), it))).getTipos()[0].getQuantidade();
            _filmes_disponiveis->at(distance(_filmes_disponiveis->begin(), it)).setQuantidade(qtd-1);
            _alugueis[cpf].push_back(filmes_alugados[i]);
         }else{
          cout << "filme inexistente" << endl;
         }
    }
}

void Aluguel::devolveFilmes(string cpf, vector<Cliente> clientes, int dias_locacao){

    auto it = find_if(clientes.begin(), clientes.end(), [cpf](Cliente& obj) {return obj.getCPF() == cpf;});
    if (it != clientes.end()){
        string codigo = "";
        int valor_total = 0;
        string nome = clientes[distance(clientes.begin(), it)].getNome();
        cout << "Cliente " << cpf << " " <<nome << " devolveu os filmes alugados por " << dias_locacao << " dia(s):" <<endl;

        for(unsigned int i = 0; i < _alugueis[cpf].size(); i++){
            codigo = _alugueis[cpf][i].getCodigo();
                    auto it = find_if(_filmes_disponiveis->begin(), _filmes_disponiveis->end(), [codigo](Filme& obj) {return obj.getCodigo() == codigo;});
                    if (it != _filmes_disponiveis->end()){
                        string categoria = _filmes_disponiveis->at(distance(_filmes_disponiveis->begin(), it)).getTipos()[0].getCategoria();
                        string tipo = _filmes_disponiveis->at(distance(_filmes_disponiveis->begin(), it)).getTipos()[0].getTipo();
                        int qtd = _filmes_disponiveis->at(distance(_filmes_disponiveis->begin(), it)).getQuantidade();
                        _filmes_disponiveis->at(distance(_filmes_disponiveis->begin(), it)).setQuantidade(qtd+1);
                        if(tipo == "D"){
                            if(categoria == "lancamentos"){
                                valor_total += 20*dias_locacao;
                                cout << codigo << " R$" << 20*dias_locacao << endl;
                            }else if(categoria == "estoque"){
                                valor_total += 10*dias_locacao;
                                cout << codigo << " R$" << 10*dias_locacao << endl;
                            }else{
                                valor_total+= 10*dias_locacao;
                                cout << codigo << " R$" << 10*dias_locacao << endl;
                            }
                        }else{
                            int randRebob = rand()%(1-0 + 1) + 0;
                            int valor_fita = 5 + 2*randRebob;
                            valor_total += valor_fita;
                            cout << codigo << " R$" << valor_fita << endl;
                        }
                    }else{
                        cout << "Filme "<< codigo << " inexistente." << endl;
                    }
        }

                   cout << "R$" << valor_total << endl;

            }else{
                cout << "CPF inexistente." << endl;
            }
    _alugueis[cpf].clear();
}
