#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Parser.hpp"
#include <iostream>


TEST_CASE("each line in file", "result after method") {



    Parser parseTest;

    REQUIRE(parseTest.removeComment("@1 // hi") == "@1 ");
    REQUIRE(parseTest.removeComment("// ") == "null");
    REQUIRE(parseTest.removeComment("D;JGT") == "D;JGT");
    REQUIRE(parseTest.removeComment("M=//D") == "M=");
    REQUIRE(parseTest.removeComment("// @2 means load constant 2 into the A-register") == "null");

}
