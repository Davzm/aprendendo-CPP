#include "agenda.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


bool Agenda :: adicionar_contato(const string& nome, const string& numero){
    Contato ctt;

    ctt.nome = nome;
    ctt.numero = numero;
    auto [it, inseriu] = contatos.insert({nome, ctt});
    return inseriu;

}

bool Agenda :: remover_contato_nome(const string& nome){
    /*erase() retorna o número de elementos removidos, então, se o contato for encontrado e removido,
    o programa retornará 1(true), se não o retorno é 0(false)*/
    return contatos.erase(nome) > 0; 
}

const Contato* Agenda :: buscar_contato_nome(const string& nome) const{
    /*it eh um iterador que desce pela árvore do map comparando as chaves.
    Ele retorna o iterador end(fim do map) caso não encontre o elemento*/
    auto it = contatos.find(nome); 
    if (it == contatos.end()) return nullptr;

    return &it -> second; 
    //second representa o segundo elemento do map, nesse caso, o contato:
    //map<nome, contato> it->second = contato
}

void Agenda :: listar_contatos() const {
    /*auto deduz o tipo de elemento presente no map
    & pega a referência do elemento, então nenhum dado é copiado
    const garante apenas leitura dos dados
    [nome, contato] determina o par de valores acessados*/
    for(const auto& [nome, contato] : contatos){
        cout << nome << " || " << contato.numero << "\n";
    }
}

bool Agenda :: salvar(const std::string& caminho) const {
    ofstream arq(caminho);
    if(!arq) return false;

    for(const auto& [nome, contato] : contatos){
        arq << nome << ";" << contato.numero << "\n";
    }
    return true;
}



bool Agenda ::carregar(const string& caminho) {
    ifstream arq(caminho);
    if(!arq) return false;

    contatos.clear();
    string linha;

    while(getline(arq, linha)){
        if(linha.empty()) continue;
        Contato ctt;
        stringstream ss(linha);
        string nome, numero;

        if (!getline(ss, nome, ';') ||
            !getline(ss, numero, '\n')){
            continue;
        }

        ctt.nome = nome;
        ctt.numero = numero;

        auto [it, inseriu] = contatos.insert({nome, ctt});
        if(!inseriu){
            cout << "Arquivo corrompido\n";
        }
    
    }
    return true;

}