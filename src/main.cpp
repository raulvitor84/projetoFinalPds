#include <iostream>

#include "Clientes.h"
#include "Filmes.h"
#include "Locacao.h"






int main() {

         CadastroClientes cadastro;
         int cpf;
         string nome;

         CadastroClientes cadastro;

         CadastroFilmes cadastrar;

         ControleLocacao locar;
         int codigoFilme, quantidade, diasLocacao, codigos;

        char tipoDeMidia;

        string titulo, categoria;

char select, select1;
int num;

        do {
               cin >> select >> select1;

         num = select + select1;


// 'LA' e 'AL' retornam o mesmo valor de num(soma dos caracteres select e select1), o if abaixo nao deixa q isso ocorra
if (num == 141 && select == 65){
    num = 142;
}


        switch (num) {







        //======================     NAO FINALIZADO =============================================**
            case 141:   // ● Ler Arquivo de Cadastro: LA <Nome do Arquivo>










                break;



      
            case 137:  // ● Cadastrar Filme:CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>

         
            cin >> tipoDeMidia >> quantidade >> codigoFilme >> titulo >> categoria;

              cadastrar.cadastrarFilme(tipoDeMidia, quantidade, codigoFilme, titulo, categoria);






                break;



        //======================     NAO FINALIZADO =============================================**
            case 152:  // ● Remover Filme: RF <código>

            cin >> codigoFilme ;


            cadastrar.removerFilme(codigoFilme);






                break;





   
            case 146:  // ● Listar Filmes ordenados por Código ou Título: LF [C|T]


                cadastrar.ordenarFilmes();
                cadastrar.listarFilmes();







                break;


        //=============================================================**

            case 142:  // ● Aluguel Filme: AL <CPF> <Código1> … <Código N>


                cin >> cpf;
                    if (!cadastro.clienteExistente(cpf)) {
                        cout << "ERRO: CPF inexistente" << endl;

                        }   else {

               do {
                    cin >> codigos;
                        if(codigos == 0){goto fim; }
                         if (!cadastrar.codigoExistente(codigos)) {
                            cout << "ERRO: Codigo do Filme inexistente" << endl;
                                goto fim;

            }




               locar.alugarFilme(codigos, cpf);

               }while(codigos != 0);

                        }

fim:







                break;



        //============================================================**


            case 154:  // ● Devolução Filme: DV <CPF>











                break;




//================================= OK (NÃO ALTERAR) =====================================================================================================================


            case 134:     // ● Cadastrar Cliente: CC <CPF> <Nome>

            cin>> cpf ;

            getline(cin, nome);

            cadastro.cadastrarCliente(cpf, nome);



                break;


//================================= OK (NÃO ALTERAR) =====================================================================================================================


            case 149:   // ● Remover Cliente: RC <CPF>


                 cin>> cpf;

                 cadastro.removerCliente(cpf);


                break;


//================================= OK (NÃO ALTERAR) =====================================================================================================================



            case 143:  // ● Listar Clientes ordenados por Código ou Nome: LC [C|N]


             cadastro.ordenarClientes();


             cadastro.listarClientes();


                break;





//================================= OK (NÃO ALTERAR) =====================================================================================================================


            case 153:   // ● Finalizar Sistema: FS
                goto exit;
                break;




        }


} while (num!= 153);
exit:
    return 0;
}

