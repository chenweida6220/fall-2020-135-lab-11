#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

// Task A. Class Profile
TEST_CASE("testing Task A") {
  Profile p1("gary", "FakeFirst");
  CHECK(p1.getUsername() == "gary");
  CHECK(p1.getFullName() == "FakeFirst (@gary)");
  p1.setDisplayName("FakeSecond");
  CHECK(p1.getFullName() == "FakeSecond (@gary)");

  Profile p2("Wei Da Chen", "Drago12354");
  CHECK(p2.getUsername() == "Wei Da Chen");
  CHECK(p2.getFullName() == "Drago12354 (@Wei Da Chen)");
  p2.setDisplayName("FakeThird");
  CHECK(p2.getFullName() == "FakeThird (@Wei Da Chen)");
}

Network nw;
// Task B. Class Network: Adding users
TEST_CASE("testing Task B") {
  CHECK(nw.addUser("Wei Da Chen", "Drago12354") == false);
  CHECK(nw.addUser("Wei_Da_Chen", "FakeFirst") == false);
  CHECK(nw.addUser("Wei1Da2Chen3", "FakeSecond") == true);
  CHECK(nw.addUser("chenweida6220", "Drago12354") == true);
  CHECK(nw.addUser("chenweida6220", "FakeThird") == false);
  CHECK(nw.addUser("", "") == false);
  CHECK(nw.addUser("123456", "789") == true);
}

// Task C. Class Network: Following others
TEST_CASE("testing Task C") {
  CHECK(nw.follow("Wei Da Chen", "chenweida6220") == false);
  CHECK(nw.follow("Wei1Da2Chen3", "chenweida6220") == true);
  CHECK(nw.follow("Wei1Da2Chen3", "Wei1Da2Chen3") == false);
  CHECK(nw.follow("nonexistant", "Wei1Da2Chen3") == false);
}
