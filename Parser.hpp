#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Parser {


    public:

        Parser();

        Parser(istream& inFile) {
            string line;
            while (inFile >> line) {
                lineQueue.push(line);
            }

        };

        bool anotherInstruction() const;

        void adv();

        // if 0 is returned it is an A-ins, else if 1 then C, else if 2 it is label
        int instructionType();

        string symbol();

        // returns mnemonic in current C-ins. Called if commandType is C_
        string destCode();

        string compCode();

        string jumpCode();

        string removeComment(string);



    private:

        queue<string> lineQueue;
        const vector<string> dest = {"null", "M", "D", "MD", "A", "AM", "AD", "AMD"};
        const vector<string> jump = {"null", "JGT", "JEQ", "JGE", "JLT", "JNE", "JLE", "JMP"};
        const vector<string> a0 = {"0", "1", "-1", "D", "A", "!D", "!A", "-D", "D+1", "A+1", "D-1"
                                    "A-1", "D-1", "D+A", "D-A", "A-D", "D&A", "D|A"};




};
