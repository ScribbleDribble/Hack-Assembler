#include <iostream>
#include "Parser.hpp"
#include "CodeGen.hpp"
#include <fstream>

using namespace std;


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

    while (parser.anotherInstruction()) {

        int mode = parser.instructionType();

        string word16;

        vector<string>mnemonics = parser.codes(parser.getCurrentInstruction());
        cout << mnemonics[0] << mnemonics[1] << mnemonics[2] <<endl;

        switch (mode)
        {
            case (0):
                word16 = codeGen.aInstructionBits(parser.symbol(parser.getCurrentInstruction()));
                break;

            case (1):
                word16 = "111" + parser.getA() + codeGen.destBits(mnemonics[0]) + codeGen.compBits(mnemonics[1]) + codeGen.jumpBits(mnemonics[2]);
                break;

            case(2):
                cout << "ok!" << endl;
                break;
        }

        outFile << word16 +"\n";

        parser.adv();

    }


}
