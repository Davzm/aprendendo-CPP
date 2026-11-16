#include "gerenciador.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void ListaTarefas::adicionar(const string& descricao, const string& data) {
    Tarefa t;

    t.descricao = descricao;
    t.data = data;
    t.id = proximoId;
    t.concluida = false;
    tarefas.push_back(t);
    proximoId++;    
}

bool ListaTarefas::remover(int id) {
    for(size_t i = 0; i < tarefas.size(); i++){
        if(tarefas[i].id == id){
            tarefas.erase(tarefas.begin() + i);
            return true;
        }
    }
    return false;
}

bool ListaTarefas::concluir(int id){
    for(size_t i = 0; i < tarefas.size(); i++){
        if(tarefas[i].id == id){
            tarefas[i].concluida = true;
            return true;
        }
    }
    return false;
}

const Tarefa* ListaTarefas::buscar(int id) const {
    for(size_t i = 0; i < tarefas.size(); i++){
        if(tarefas[i].id == id){
            return &tarefas[i];
        }
    }
    return nullptr;
}

void ListaTarefas::listar() const {
    if(vazia()){
        cout << "A lista de tarefas está vazia\n";
        return;
    }
    string concluida;
    for(const Tarefa& t : tarefas){
        if(t.concluida == true){
            concluida = "concluida";
        }else{
            concluida = "não concluida";
        }
        cout << "[" << t.id << "] - " << t.descricao << " - " << t.data << " || (" << concluida << ")\n";
    }
}

bool ListaTarefas::salvar(const string& caminho) const {
    ofstream arq(caminho);
    if(!arq) return false;


    for(const Tarefa& t : tarefas){
        arq << t.id << ";" << t.descricao << ";" << t.data << ";" << t.concluida << "\n";
    }

    return true;
}

bool ListaTarefas::carregar(const string& caminho) {
    ifstream arq(caminho);
    if(!arq) return false;

    tarefas.clear();
    proximoId = 1;
    string linha;

    while(getline(arq, linha)){
        if(linha.empty()) continue;
        Tarefa t;
        stringstream ss(linha);
        string campoID, descricao, data, campoConcluido;

        if (!getline(ss, campoID, ';') ||
            !getline(ss, descricao, ';') ||
            !getline(ss, data, ';') ||
            !getline(ss, campoConcluido, '\n')) {
            continue;
        }

        try{
            t.id = stoi(campoID);
        }catch(const exception&){
            continue;
        }

        t.descricao = descricao;
        t.data = data;
        t.concluida = (campoConcluido == "1");

        tarefas.push_back(t);
        if (t.id >= proximoId) {
            proximoId = t.id + 1;

        }

    
    }
    return true;

}

bool ListaTarefas::vazia() const {
    return tarefas.empty();
}