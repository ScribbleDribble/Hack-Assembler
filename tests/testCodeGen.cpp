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

    REQUIRE(cg.aInstructionBits("15") == "0111100000000000");
    REQUIRE(cg.aInstructionBits("1") == "0100000000000000");
    REQUIRE(cg.aInstructionBits("63") == "0111111000000000");
    REQUIRE(cg.aInstructionBits("20") == "0001010000000000");
    REQUIRE(cg.aInstructionBits("101") == "0110010100000000");

}

