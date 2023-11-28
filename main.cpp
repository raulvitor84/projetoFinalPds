#include <iostream>
#include <string>
#include <vector>
#include "CadastroClientes.h"

using namespace std;





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
            case 'R':

             //   minhaLista.remover();
                break;
            case 'C':
            //    minhaLista.contador();

                break;
            case 'P':
             //   int n;
             //   cin >> n;
              //  if (n >=1){
               // minhaLista.imprimirN(n-1);}

             //   else{
              //      cout <<"ERRO"<< endl;
              //  }



                break;

            case 'L':
         //       minhaLista.exibirLista();
                break;


            case 'E':
                break;



            default:

                cout<< endl;
        }


} while (select != 'E');

    return 0;
}
