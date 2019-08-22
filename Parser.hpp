#include <iostream>
#include <vector>

using namespace std;

class Parser {


    public:

        Parser(istream& inFile): inFile(inFile) {};

        bool anotherInstruction();

        void adv() const;

        int instructionType();

        string symbol();

        // returns mnemonoc in current C-ins. Called if commandType is C_
        string dest();

        string comp();

        string jump();



    private:

        istream& inFile;




};
