#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <map>
#include <string>

//cada Contato contém um nome e um numero de telefone
struct Contato{
   std :: string nome;
   std :: string numero;
};

class Agenda{
   public:
      bool adicionar_contato(const std :: string& nome, const std :: string& numero);
      bool remover_contato_nome(const std :: string& nome);
      const Contato* buscar_contato_nome(const std :: string& nome) const;
      void listar_contatos() const;
      bool salvar(const std::string& caminho) const;
      bool carregar(const std::string& caminho);
      bool vazia()const;


   private:
      std::map< std :: string, Contato> contatos;   
};

#endif