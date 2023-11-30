#include <iostream>

#include "CadastroClientes.h"
#include "CadastroFilmes.h"
#include "ControleLocacao.h"






int main() {

         CadastroClientes cadastro;
         string cpf;
         string nome;



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



        //======================     NAO FINALIZADO =============================================**
            case 137:  // ● Cadastrar Filme:CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>




                break;



        //======================     NAO FINALIZADO =============================================**
            case 152:  // ● Remover Filme: RF <código>







                break;





        //======================     NAO FINALIZADO =============================================**
            case 146:  // ● Listar Filmes ordenados por Código ou Título: LF [C|T]








                break;


        //======================     NAO FINALIZADO =============================================**

            case 142:  // ● Aluguel Filme: AL <CPF> <Código1> … <Código N>









                break;



        //======================     NAO FINALIZADO =============================================**


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

