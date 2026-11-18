#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <sstream>
#include "contador.hpp"


bool contar_caracteres(const string& texto, long long& bytes,long long& caracteres){
    ifstream arq(texto);
    if(!arq) return false;

    bytes = 0;
    caracteres = 0;
    char c;
   while (arq.get(c)) {
        bytes++;
        unsigned char u = static_cast<unsigned char>(c);
        if ((u & 0xC0) != 0x80) caracteres++;   // ignora bytes de continuação
    }

    return true;
}