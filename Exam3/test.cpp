#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Decript.cpp"

TEST_CASE("Cypher a, 1 moves letter 1 to the right in the abc") {
  Decript crypting;
  crypting.decripting("a", 1);
  REQUIRE(crypting.get_changed_text() == "b");
}