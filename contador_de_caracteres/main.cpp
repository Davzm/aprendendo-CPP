#include <iostream>
#include <string>
using namespace std;
#include "contador.hpp"
static const string ARQUIVO = "texto.txt";

int main(void){
    long long bytes = 0;
    long long total_caracteres = 0;

    if(contar_caracteres(ARQUIVO,bytes ,total_caracteres)){
        cout << "Total de caracteres: " << total_caracteres << "\n";
    }else{
        cout << "Não foi possível abrir " << ARQUIVO << "\n";
    }

    return 0;
}