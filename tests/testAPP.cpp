#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../CodeGen.hpp"
#include <fstream>
#include <vector>
#include <stdlib.h>


// compare my binary output file with a file containing expected output
TEST_CASE("my binary word", "possibly correct word??") {

    ifstream inFile;
    inFile.open("../Prog.hack");

    string line;

    vector<string> words;


    while (inFile >> line)
    {
        words.push_back(line);
    }

    ifstream testFile;
    testFile.open("testValues.hack");

    vector<string> test_words;
    string line2;
    int i = 0;

    while (testFile >> line2)
    {
        REQUIRE(words[i++] == line2);
    }



}


