#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Parser.hpp"
#include <iostream>
#include <stdlib.h>



TEST_CASE("each line in file", "result after method") {



    Parser parseTest;

    REQUIRE(parseTest.removeRedundancy("@1 // hi") == "@1");
    REQUIRE(parseTest.removeRedundancy("// ") == "");
    REQUIRE(parseTest.removeRedundancy("D;JGT") == "D;JGT");
    REQUIRE(parseTest.removeRedundancy("M=//D") == "M=");
    REQUIRE(parseTest.removeRedundancy("// @2 means load constant 2 into the A-register") == "");
    REQUIRE(parseTest.removeRedundancy("D = M + 1") == "D=M+1");
	REQUIRE(parseTest.removeRedundancy("(INFINITE_LOOP) // this is a comment") == "(INFINITE_LOOP)");
	REQUIRE(parseTest.removeRedundancy(" @1 //nope") == "@1");
	REQUIRE(parseTest.removeRedundancy("") == "");
}


TEST_CASE("instruction", "instruction type") {


    Parser parseTest;

    parseTest.push("@1 // loads constant 1 into A register");
    REQUIRE(parseTest.instructionType() == 0);
    parseTest.pop();

    parseTest.push("D;JGT");
    REQUIRE(parseTest.instructionType() == 1);
    parseTest.pop();

    parseTest.push("D=M+ 1");
    REQUIRE(parseTest.instructionType() == 1);
    parseTest.pop();

    parseTest.push("// hello this is a comment");
    REQUIRE(parseTest.instructionType() == -1);
    parseTest.pop();

    parseTest.push("(END)");
    REQUIRE(parseTest.instructionType() == 2);
    parseTest.pop();

    parseTest.push("*********anSMINSQ 99");
    REQUIRE(parseTest.instructionType() == 1);
    parseTest.pop();

}

TEST_CASE("Label", "symbol") {


    Parser parseTest;
    REQUIRE(parseTest.symbol("(LOOP)") == "LOOP");
    REQUIRE(parseTest.symbol("(END)") == "END");
    REQUIRE(parseTest.symbol("@i") == "i");
    REQUIRE(parseTest.symbol("@sum") == "sum");



}


TEST_CASE("Mnemonic type", "Mnemonic") {


    Parser parseTest;
    vector<string> v = parseTest.codes("D=A");
    REQUIRE(v[1] == "D");
    REQUIRE(v[0] == "A");
    REQUIRE(v[2] == "null");

    v = parseTest.codes("D;JGT");
    REQUIRE(v[1] == "null");
    REQUIRE(v[0] == "D");
    REQUIRE(v[2] == "JGT");

    v = parseTest.codes("AMD=M+1");
    REQUIRE(v[1] == "AMD");
    REQUIRE(v[0] == "M+1");
    REQUIRE(v[2] == "null");

    v = parseTest.codes("D=D-M;JLE");
    REQUIRE(v[1] == "D");
    REQUIRE(v[0] == "D-M");
    REQUIRE(v[2] == "JLE");





}

