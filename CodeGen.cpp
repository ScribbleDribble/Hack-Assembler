#include "CodeGen.hpp"
#include <map>
#include <iterator>
#include <stdexcept>

string CodeGen::destBits(const string dest) {

    map<string, string>destMap = {
                                   {"null", "000"}, {"M", "001"}, {"D", "010"}, {"MD", "011"},
                                   {"A", "100"}, {"AM", "101"}, {"AD", "110"}, {"AMD", "111"}
                                 };


    map<string, string>::iterator iter;

    for (iter = destMap.begin(); iter != destMap.end(); iter++ )
    {
        if (iter->first == dest)
        {
            return iter->second;
        }
    }


    throw invalid_argument("Invalid instruction");
}

string CodeGen::compBits(const string dest) {

    // when a = 0
    map<string, string>a0 = {
                                   {"0", "101010"}, {"1", "111111"}, {"-1", ""}, {"D", "001100"},

                                   {"A", "110000"}, {"!D", "001101"}, {"!A", "110001"}, {"-D", "001111"},

                                   {"-A", "110011"}, {"D+1", "011111"}, {"A+1", "110111"}, {"D-1", "001110"},

                                   {"A-1", "110010"}, {"D+A", "000010"}, {"D-A", "010011"}, {"A-D", "000111"},

                                   {"D&A", "000000"}, {"D|A", "010101"}

                                 };


    map<string, string>a1 = {
                                    {"M", "110000"}, {"!M", "1100001"}, {"-M", "110011"}, {"M+1", "110111"},

                                   {"M-1", "110010"}, {"D+M", "000010"}, {"M-D", "000111"}, {"D&M", "000000"},

                                   {"D|M", "010101"}

                                   };

    map<string, string>::iterator iter;

    // when a = 1



    for (iter = a0.begin(); iter != a0.end(); iter++ )
    {
        if (iter->first == dest)
        {
            return iter->second;
        }
    }

    for (iter = a1.begin(); iter != a1.end(); iter++ )
    {
        if (iter->first == dest)
        {
            return iter->second;
        }
    }


    throw invalid_argument("Invalid instruction");

}

string CodeGen::jumpBits(const string dest) {

    map<string, string>jumpMap = {
                                   {"null", "000"}, {"JGT", "001"}, {"JEQ", "010"}, {"JGE", "011"},
                                   {"JLT", "100"}, {"JNE", "101"}, {"JLE", "110"}, {"JMP", "111"}
                                 };


    map<string, string>::iterator iter;

    for (iter = jumpMap.begin(); iter != jumpMap.end(); iter++ )
    {
        if (iter->first == dest)
        {
            return iter->second;
        }
    }


    throw invalid_argument("Invalid instruction");
}


