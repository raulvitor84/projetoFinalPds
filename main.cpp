#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CadastroClientes.h"

using namespace std;



void leitura_arquivo (char nome_arquivo) {
 

}



int main() {


 string select;


        do {
               cin >> select;

        switch (select) {

         
         
            case 'CC':
         CadastroClientes cadastro;
         string cpf, nome;
            cadastro.cadastrarCliente(cpf, nome);

                break;
         
            case "LA": //Ler Arquivo de Cadastro: LA <Nome de Arquivo>
            string nome_arquivo;
            std::in >> nome_arquivo;
            leitura_arquivo(nome_arquivo);
            
                break;

            case 'CF': //Cadastrar Filme: CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD> 

                break;
                
            case 'RF': //Remover Filme: RF <código>

                break;

            case 'LF': //Listar Filmes Ordenados por Código ou Título: LF <CPF> <Nome>

                break;

            case 'RC': //Remover Cliente: RC <CPF>

                break;

            case 'LC': //Listar Clientes ordenados por Código ou Nome: LC [C|N]

                break;

            case 'AL': //Aluguel Filme: AL <CPF> <Código1> ... <Código N>

                break;

            case 'DV': //Devolução Filme: DV <CPF>

                break;

            default:

                cout<< endl;
        }


} while (select != 'FS');

    return 0;
}
