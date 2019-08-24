#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../CodeGen.hpp"


TEST_CASE("dest code", "bits") {

    CodeGen cg;

    REQUIRE(cg.destBits("null") == "000");
    REQUIRE(cg.destBits("M") == "001");
    REQUIRE(cg.destBits("D") == "010");
    REQUIRE(cg.destBits("MD") == "011");

}

TEST_CASE("comp", "bits") {

    CodeGen cg;

    REQUIRE(cg.compBits("D|A") == "010101");
    REQUIRE(cg.compBits("A-D") == "000111");
    REQUIRE(cg.compBits("M") == "110000");
    REQUIRE(cg.compBits("M-D") == "000111");

}

TEST_CASE("symbol", "bits") {

    CodeGen cg;

    REQUIRE(cg.aInstructionBits("5") == "0000000000000101");
    REQUIRE(cg.aInstructionBits("20") == "0000000000010100");
    REQUIRE(cg.aInstructionBits("63") == "0000000000111111");
    REQUIRE(cg.aInstructionBits("0") == "0000000000000000");
    REQUIRE(cg.aInstructionBits("101") ==  "0000000001100101");

}

