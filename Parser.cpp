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

    unsigned int i;


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

    current_instruction = correctedString;

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

vector<char> Parser::setNull() {

    vector<char> v;
    v.push_back('n');
    v.push_back('u');
    v.push_back('l');
    v.push_back('l');
    return v;

}

vector<string> Parser::codes(string current_ins) {

    vector<string> fields;


    // individual fields
    vector<char> dest;
    vector<char> comp;
    vector<char> jump;

    jump = setNull();

    // helps log what field we should currently be retrieving from. index 0, if true, indicates we have finished retrieving from
    // dest field and we are now at comp part. etc.
    bool checkPoint[] = {false, false};

    int j = 0, k = 0;

    for (unsigned int i = 0; i < current_ins.size(); i++)
    {

        if (current_ins[i] == ';' && checkPoint[0] == false)
        {
            comp = dest;
            dest.clear();
            dest = setNull();

            checkPoint[0] = true;
            checkPoint[1] = true;

            // remove null status jump by default has
            jump.clear();


        }

        else if (current_ins[i] != '=' && checkPoint[0] == false)
        {
            dest.push_back(current_ins[i]);
        }

        else if (current_ins[i] == '=' && checkPoint[0] == false)
        {
            checkPoint[0] = true;
        }

        else if (current_ins[i] != ';' && checkPoint[0] == true && checkPoint[1] == false)
        {
            comp.push_back(current_ins[i]);
        }

        else if (current_ins[i] == ';' && checkPoint[0] == true)
        {
            checkPoint[1] = true;
            jump.clear();
        }

        else if (checkPoint[1] == true)
        {
            jump.push_back(current_ins[i]);
        }

    }

    string destMnemonic(dest.begin(), dest.end());
    string compMnemonic(comp.begin(), comp.end());
    string jumpMnemonic(jump.begin(), jump.end());

    setA(compMnemonic);

    fields.push_back(compMnemonic);
    fields.push_back(destMnemonic);
    fields.push_back(jumpMnemonic);

    return fields;

}

void Parser::setA(string compMnemonic) {

    a = "-1";

    for (int i = 0; i < compMnemonic.size(); i++)
    {
        if (compMnemonic[i] == 'M')
        {
            a = "1";
        }
    }

    // if comp doenst involve M, set a = 0
    if (a != "1")
    {
        a = "0";
    }

}


string Parser::getCurrentInstruction() const{
    return Parser::current_instruction;
}





