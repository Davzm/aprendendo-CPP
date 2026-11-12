#include "agenda.hpp"
#include <iostream>
#include <string>

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
