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

        // removes comments and whitespaces
        string removeRedundancy(string);

        // if 0 is returned it is an A-ins, else if 1 then C, else if 2 it is label
        int instructionType();

        string symbol(string);

        vector<char>setNull();

        vector<string> codes(string);

        string getCurrentInstruction() const;

        string getA() const {
            return a;
        }

        // FOR TESTING
        void push(string ins) {

            lineQueue.push(ins);
        }
        // FOR TESTING
        void pop() {

            lineQueue.pop();
        }


    private:
        queue<string>lineQueue;

        string a;

        void setA(string);






        string current_instruction;

};
