#include "SymbolTable.hpp"
#include <iterator>

using namespace std;


SymbolTable::SymbolTable() {};

bool SymbolTable::contains(string symbol) {

    map<string, int>::iterator iter;

    for (iter = symbolTable.begin(); iter != symbolTable.end(); iter++)
    {
        if (iter->first == symbol)
        {
            return true;
        }
    }

    return false;

}

int SymbolTable::getAddress(string symbol) {

    map<string, int>::iterator iter;

    for (iter = symbolTable.begin(); iter != symbolTable.end(); iter++)
    {
        if (iter->first == symbol)
        {
            return iter->second;
        }

    }


    return -1;

}
