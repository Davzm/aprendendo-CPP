#include "gerenciador.hpp"
#include <iostream>
#include <string>
using namespace std;

void ListaTarefas::adicionar(const string& descricao, const string& data) {
    // TODO: criar uma Tarefa com id = proximoId, guardar no vector
    // e incrementar proximoId.
    Tarefa t;

    t.descricao = descricao;
    t.data = data;
    t.id = proximoId;
    tarefas.push_back(t);
    proximoId++;    
}

bool ListaTarefas::remover(int id) {
    // TODO: procurar a tarefa pelo id e apagá-la do vector.
    // Dica: percorra com índice e use tarefas.erase(tarefas.begin() + i).
    for(size_t i = 0; i < tarefas.size(); i++){
        if(tarefas[i].id == id){
            tarefas.erase(tarefas.begin() + i);
            return true;
        }
    }
    return false;
}

bool ListaTarefas::concluir(int id){
    // TODO: procurar pelo id e marcar concluida = true.
    for(size_t i = 0; i < tarefas.size(); i++){
        if(tarefas[i].id == id){
            tarefas[i].concluida = true;
            return true;
        }
    }
    return false;
}

const Tarefa* ListaTarefas::buscar(int id) const {
    // TODO: retornar &tarefas[i] se achar, nullptr se não achar.
    for(size_t i = 0; i < tarefas.size(); i++){
        if(tarefas[i].id == id){
            return &tarefas[i];
        }
    }
    return nullptr;
}

void ListaTarefas::listar() const {
    // TODO: se estiver vazia, avisar. Senão, imprimir uma linha por tarefa:
    // [x] 1 - Estudar C++ (10/11/2026)
    // Dica: for (const Tarefa& t : tarefas) { ... }
    if(vazia()){
        cout << "A lista de tarefas está vazia\n";
        return;
    }
    string concluida;
    for(Tarefa t : tarefas){
        if(t.concluida == true){
            concluida = "concluida";
        }else{
            concluida = "não concluida";
        }
        cout << "[" << t.id << "] - " << t.descricao << " " << t.data << " || (" << concluida << ")\n";
    }
}

bool ListaTarefas::salvar(const string& caminho) const {
    // TODO (etapa 4): abrir ofstream, gravar uma tarefa por linha.
    // Cuidado: a descrição pode ter espaços, então use um separador (';').
    (void)caminho;
    return false;
}

bool ListaTarefas::carregar(const string& caminho) {
    // TODO (etapa 4): abrir ifstream, ler linha a linha com getline
    // e reconstruir as tarefas. Lembre de atualizar proximoId.
    (void)caminho;
    return false;
}

bool ListaTarefas::vazia() const {
    return tarefas.empty();
}