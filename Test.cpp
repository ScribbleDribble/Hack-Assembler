#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Parser.hpp"
#include <iostream>


TEST_CASE("each line in file", "result after method") {



    Parser parseTest;

    REQUIRE(parseTest.removeRedundancy("@1 // hi") == "@1");
    REQUIRE(parseTest.removeRedundancy("// ") == "");
    REQUIRE(parseTest.removeRedundancy("D;JGT") == "D;JGT");
    REQUIRE(parseTest.removeRedundancy("M=//D") == "M=");
    REQUIRE(parseTest.removeRedundancy("// @2 means load constant 2 into the A-register") == "");
    REQUIRE(parseTest.removeRedundancy("D = M + 1") == "D=M+1");
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
