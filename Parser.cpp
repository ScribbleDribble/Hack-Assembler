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

string Parser::removeComment(string line) {

    bool del = false;

    for (i = 0; i < line.size() - 1; i++)
    {
        if (line[i] == '/' && line[i+1] == '/')
        {
            cout << i << line.size() << endl;
            del = true;
            break;
        }
    }

    if (del == true)
    {
        line = line.erase(i, line.size() - 1);

        if (i == 0)
        {
            return "null";
        }
    }

    return line;

}

int Parser::instructionType() {

    string current_ins;



    current_ins = lineQueue.front();

//    if (current_ins[0] == '(')
        // L-ins

    //else if (current_ins[0] == '@')
    //{
        // A ins
    //}


    return 1;

}
