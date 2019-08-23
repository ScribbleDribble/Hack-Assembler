#include <iostream>
#include "Parser.hpp"
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


    Parser parse(infile);
    parse.adv();

}
