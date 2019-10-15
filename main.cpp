#include <iostream>
#include "Parser.hpp"
#include "CodeGen.hpp"
#include "SymbolTable.hpp"
#include <fstream>
#include <string>
#include <memory>

using namespace std;

static void first_pass(SymbolTable& table, Parser parser) {

    int rom_counter = 0;

    while (parser.anotherInstruction()) {

        int mode = parser.instructionType();

        if (mode == 2)
        {
            string symbol = parser.symbol(parser.getCurrentInstruction());
            table.addEntry(symbol, rom_counter);
        }

        else if (mode == 0 || mode == 1)
        {
            rom_counter++;
        }

        parser.adv();

    }

}

static void second_pass(SymbolTable& table, Parser parser, CodeGen codeGen) {

        ofstream outFile;
        outFile.open("Prog.hack");

        int var_mem_loc = 16;

        while (parser.anotherInstruction()) {

        int mode = parser.instructionType();

        string word16;

        string current_ins = parser.getCurrentInstruction();

        vector<string>mnemonics = parser.codes(current_ins);

        switch (mode)
        {

            case (0):
            {
                string symbol = parser.symbol(current_ins);

                if (table.contains(symbol))
                {
                    string addr = to_string(table.getAddress(symbol));
                    word16 = codeGen.aInstructionBits(addr);
                    break;
                }

                // for new variables
                else if (( (int) symbol[0] >= 97 && (int) symbol[0] <= 122 ) || ( (int) symbol[0] >= 65 && (int) symbol[0] <=  90))
                {

                    table.addEntry(symbol, var_mem_loc);
                    word16 = codeGen.aInstructionBits(to_string(var_mem_loc));
                    var_mem_loc++;
                    break;
                }

                else {
                    word16 = codeGen.aInstructionBits(symbol);
                    break;
                }

            }
            case (1):
                word16 = "111" + parser.getA() + codeGen.compBits(mnemonics[0]) + codeGen.destBits(mnemonics[1]) + codeGen.jumpBits(mnemonics[2]);
                break;


            case (-1):
                break;

        }

        if (mode == 0 || mode == 1)
        {
            outFile << word16 +"\n";
        }

        parser.adv();

    }


}


int main(int argc, char *argv[]) {

    if (argc != 2)
    {
        cerr << "Usage: ./ <filename>" << endl;
        return 1;
    }

    ifstream infile(argv[1]);

    if (!infile) {

        cerr << "Cannot access file" << endl;
        return 2;

    }

    ofstream outFile;
    outFile.open("Prog.hack");

    Parser parser(infile);
    CodeGen codeGen;
    SymbolTable table;

    // pointer will need to be copied to other functions
    shared_ptr<SymbolTable> tablePtr = make_shared<SymbolTable>();

    first_pass(*tablePtr, parser);
    second_pass(*tablePtr, parser, codeGen);

    cout << "Translation complete!" << endl;

}
