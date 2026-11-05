#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include <string>
#include <vector>

// Uma tarefa. "string" já cuida do tamanho sozinha, então não precisa de
// arrays como em C (nada de string data[10]).
struct Tarefa {
    int id;
    std::string descricao;
    std::string data;        // dd/mm/aaaa (formato livre por enquanto)
    bool concluida = false;
};

// Guarda e manipula as tarefas. O resto do programa só conversa com esta
// classe, sem saber que por baixo existe um vector. Isso permite trocar o
// vector pela sua lista encadeada na versão 2, sem mexer no menu.
class ListaTarefas {
public:
    // Cria uma tarefa nova com id automático.
    void adicionar(const std::string& descricao, const std::string& data);

    // Remove a tarefa com esse id. Retorna false se não existir.
    bool remover(int id);

    // Marca a tarefa como concluída. Retorna false se não existir.
    bool concluir(int id);

    // Retorna ponteiro para a tarefa, ou nullptr se não existir.
    const Tarefa* buscar(int id) const;

    // Imprime todas as tarefas no terminal.
    void listar() const;

    // Grava e lê as tarefas em arquivo. Retornam false em caso de erro.
    bool salvar(const std::string& caminho) const;
    bool carregar(const std::string& caminho);

    bool vazia() const;

private:
    std::vector<Tarefa> tarefas;
    int proximoId = 1;
};

#endif