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

        cout << parser.getCurrentInstruction() << endl;

        switch (mode)
        {
            case (0):
                word16 = codeGen.aInstructionBits(parser.symbol(parser.getCurrentInstruction()));
                break;

            case (1):
                word16 = "111" + parser.getA() + codeGen.compBits(mnemonics[0]) + codeGen.destBits(mnemonics[1]) + codeGen.jumpBits(mnemonics[2]);
                break;

            case(2):
                break;
        }

		cout << word16 << endl;

        outFile << word16 +"\n";

        parser.adv();

    }


}
