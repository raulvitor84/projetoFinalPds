#include <iostream>
#include <string>
#include <vector>
#include "CadastroClientes.h"

using namespace std;





/*int main() {
    CadastroClientes cadastro;


    cadastro.cadastrarCliente("000.000.000-22", "Carlos Magno Rezende");
   // cadastro.cadastrarCliente("111.111.111-00", "Helder Barbalho Pires");


return 0;
}
*/
int main() {

 MinhaLista minhaLista;
 char select;
 int i =1;

        do {
               cin >> select;

        switch (select) {
            case 'CC':


                minhaLista.inserir(i);

                i++;
                break;
            case 'R':

                minhaLista.remover();
                break;
            case 'C':
                minhaLista.contador();

                break;
            case 'P':
                int n;
                cin >> n;
                if (n >=1){
                minhaLista.imprimirN(n-1);}

                else{
                    cout <<"ERRO"<< endl;
                }



                break;

            case 'L':
                minhaLista.exibirLista();
                break;


            case 'E':
                break;



            default:

                cout<< endl;
        }


} while (select != 'E');

    return 0;
}
