#include "Parser.hpp"

#include <vector>

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
