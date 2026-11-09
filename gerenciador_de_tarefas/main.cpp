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
    int id;
    bool resultado;
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
                cout << "id ";
                cin >> id;
                resultado = lista.concluir(id);
                if(resultado == false){
                    cout << "Tarefa não encontrada\n";
                }else{
                    cout << "Tarefa " << id << " concluída\n";
                }
                break;
            case 4:
                cout << "id ";
                cin >> id;
                resultado = lista.remover(id);
                if(resultado == false){
                    cout << "Tarefa não encontrada\n";
                }else{
                    cout << "Tarefa " << id << "removida\n";
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