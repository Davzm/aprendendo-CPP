#include "gerenciador.h++"
#include <iostream>
using namespace std;

void ListaTarefas::adicionar(const string& descricao, const string& data) {
    // TODO: criar uma Tarefa com id = proximoId, guardar no vector
    // e incrementar proximoId.
    (void)descricao;
    (void)data;
}

bool ListaTarefas::remover(int id) {
    // TODO: procurar a tarefa pelo id e apagá-la do vector.
    // Dica: percorra com índice e use tarefas.erase(tarefas.begin() + i).
    (void)id;
    return false;
}

bool ListaTarefas::concluir(int id) {
    // TODO: procurar pelo id e marcar concluida = true.
    (void)id;
    return false;
}

const Tarefa* ListaTarefas::buscar(int id) const {
    // TODO: retornar &tarefas[i] se achar, nullptr se não achar.
    (void)id;
    return nullptr;
}

void ListaTarefas::listar() const {
    // TODO: se estiver vazia, avisar. Senão, imprimir uma linha por tarefa:
    // [x] 1 - Estudar C++ (10/11/2026)
    // Dica: for (const Tarefa& t : tarefas) { ... }
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