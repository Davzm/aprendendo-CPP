#include <iostream>
#include <limits>
#include <string>

#include "gerenciador.hpp"

using namespace std;

static const string ARQUIVO = "tarefas.txt";

void mostrarMenu() {
    cout << "\n===== GERENCIADOR DE TAREFAS =====\n"
         << "1 - Adicionar tarefa\n"
         << "2 - Listar tarefas\n"
         << "3 - Concluir tarefa\n"
         << "4 - Remover tarefa\n"
         << "0 - Sair\n"
         << "Escolha: ";
}

// Lê um inteiro do teclado sem quebrar se o usuário digitar letras.
int lerInt() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor inválido, tente de novo: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // descarta o '\n'
    return x;
}

int main() {
    ListaTarefas lista;
    lista.carregar(ARQUIVO);  // se o arquivo não existir, só retorna false
    int opcao;
    do {
        mostrarMenu();
        opcao = lerInt();

        switch (opcao) {
            case 1: {
                string descricao, data;
                cout << "Descrição: ";
                getline(cin, descricao);
                cout << "Data (dd/mm/aaaa): ";
                getline(cin, data);
                lista.adicionar(descricao, data);
                break;
            }
            case 2:
                lista.listar();
                break;
            case 3:
                int id1;
                bool resultado1;
                cout << "id ";
                id1 = lerInt();
                resultado1 = lista.concluir(id1);
                if(resultado1 == false){
                    cout << "Tarefa não encontrada\n";
                }else{
                    cout << "Tarefa " << id1 << " concluída\n";
                }
                break;
            case 4:
                int id2;
                bool resultado2;
                cout << "id ";
                id2 = lerInt();
                resultado2 = lista.remover(id2);
                if(resultado2 == false){
                    cout << "Tarefa não encontrada\n";
                }else{
                    cout << "Tarefa " << id2 << " removida\n";
                }
                
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    lista.salvar(ARQUIVO);
    return 0;
}