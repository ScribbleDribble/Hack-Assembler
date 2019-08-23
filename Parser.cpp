#include "Parser.hpp"

#include <vector>
#include <memory>

Parser::Parser() {
};

bool Parser::anotherInstruction() const {
    return !lineQueue.empty();
}

void Parser::adv() {
    lineQueue.pop();
}

string Parser::removeRedundancy(string line) {

    vector<char> charVector;

    bool del = false;

    int i;


    for (i = 0; i < line.size(); i++)
    {

        if (i < line.size() - 1)
        {
            if (line[i] == '/' && line[i+1] == '/')
            {
                break;
            }
        }

        if (line[i] != ' ')
        {
            charVector.push_back(line[i]);
        }


    }


    string correctedString( charVector.begin(), charVector.end() );

    return correctedString;

}

int Parser::instructionType() {

    string current_ins = lineQueue.front();
    current_ins = removeRedundancy(current_ins);

    if (current_ins[0] == '@')
    {
        symbol(current_ins);
        return 0;
    }

    else if (current_ins[0] == '(' && current_ins[current_ins.size() - 1] == ')')
    {
        return 2;
    }

    else if (current_ins == "")
    {
        return -1;
    }

    else
    {
        return 1;
    }

    return 1;

}

string Parser::symbol(string current_ins) {


    if (current_ins[0] == '@')
    {
        current_ins = current_ins.erase(0, 1);
    }

    else
    {
        current_ins = current_ins.erase(0, 1);
        current_ins = current_ins.erase(current_ins.size() - 1);
    }

    return current_ins;

}

vector<string> Parser::codes(string current_ins) {

    vector<string> fields;



    vector<char>dest;
    vector<char>comp;
    vector<char>jump;

    bool checkPoint[] = {false, false};

    int j = 0, k = 0;

    for (int i = 0; i < current_ins.size(); i++)
    {
        if (current_ins[i] != '=' && checkPoint[0] == false)
        {
            dest[i] = current_ins[i];
        }

        else if (current_ins[i] == '=' && checkPoint[0] == false)
        {
            checkPoint[0] = true;
        }

        else if (current_ins[i] != ';' && checkPoint[0] == true)
        {
            comp[j++] = current_ins[i];
        }

        else if (current_ins[i] == ';' && checkPoint[0] == true)
        {
            checkPoint[1] = true;
        }

        else if (checkPoint[1] == true)
        {
            jump[k++] = current_ins[i];
        }

    }

    string destMnemonic(dest.begin(), dest.end());
    string compMnemonic(comp.begin(), comp.end());
    string jumpMnemonic(jump.begin(), jump.end());

    fields[0] = destMnemonic;
    fields[1] = compMnemonic;
    fields[2] = jumpMnemonic;

    return fields;

}

/*
string Parser::destCode(string current_ins) {

    vector<char>charVector;

    for (int i = 0; i < current_ins.size(); i++)
    {
        if (current_ins[i] != '=')
        {
            charVector[i] = charVector[i];
        }

        else
        {
            break;
        }
    }

    string destMneumonic(charVector.begin(), charVector.end());
    return destMneumonic;
}
*/



