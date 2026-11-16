#include <iostream>
#include "agenda.hpp"
using namespace std;

int main(void){
    Agenda ag;

    int decisao;

    do{
        cout << 
        "[1] - Adcionar contato\n" <<
        "[2] - Listar contatos\n" <<
        "[3] - Remover contato\n" << 
        "[4] - Buscar contato\n" <<
        "[0] - Encerrar\n" << 
        "Decisão: ";
        cin >> decisao;
        cin.ignore();  // descarta o '\n'

        switch(decisao){
            case 1:{
                string nome, numero;
                cout << "Nome: ";
                getline(cin, nome);
                cout << "DDD + número: ";
                getline(cin, numero);

                bool deu_certo;
                deu_certo = ag.adicionar_contato(nome, numero);

                if(deu_certo){
                    cout << "\nContato adicionado!\n";
                }else{
                    cout << "\nAlgo deu errado...\n";
                }
                break;
            }
            case 2:
                cout << "/-----------------------------------------------/\n";
                cout << "Lista de contatos:\n";
                ag.listar_contatos();
                cout << "\n/-----------------------------------------------/\n\n";
                break;
            case 3:{
                string nome;
                cout << "Nome: ";
                getline(cin, nome);
                bool deu_certo = ag.remover_contato_nome(nome);

                if(deu_certo){
                    cout << "\nContato removido!\n";
                }else{
                    cout << "\nAlgo deu errado...";
                }
                break;
            }
            case 4:{
                string nome;
                cout << "Nome: ";
                getline(cin, nome);
                ag.buscar_contato_nome(nome);
                break;
            }
            case 0:
                cout << "\nEncerrado...\n";
                break;
        }   


    }while(decisao != 0);


    return 0;
}