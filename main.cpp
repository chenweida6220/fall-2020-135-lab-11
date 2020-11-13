#include <iostream>
using namespace std;

#include "profile.h"
#include "network.h"

int main() {
  // Task A. Class Profile
  Profile p1("marco", "Marco");
  cout << p1.getUsername() << endl; // marco
  cout << p1.getFullName() << endl; // Marco (@marco)

  p1.setDisplayName("Marco Rossi");
  cout << p1.getUsername() << endl; // marco
  cout << p1.getFullName() << endl; // Marco Rossi (@marco)

  Profile p2("tarma1", "Tarma Roving");
  cout << p2.getUsername() << endl; // tarma1
  cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)

  cout << "----------" << endl << endl;

  // Task B. Class Network: Adding users
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i),
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)

  cout << "----------" << endl << endl;

  // Task C. Class Network: Following others
  Network nw2;
  // add three users
  nw2.addUser("mario", "Mario");
  nw2.addUser("luigi", "Luigi");
  nw2.addUser("yoshi", "Yoshi");

  // make them follow each other
  nw2.follow("mario", "luigi");
  nw2.follow("mario", "yoshi");
  nw2.follow("luigi", "mario");
  nw2.follow("luigi", "yoshi");
  nw2.follow("yoshi", "mario");
  nw2.follow("yoshi", "luigi");

  // add a user who does not follow others
  nw2.addUser("wario", "Wario");

  // add clone users who follow @mario
  for(int i = 2; i < 6; i++) {
      string usrn = "mario" + to_string(i);
      string dspn = "Mario " + to_string(i);
      nw2.addUser(usrn, dspn);
      nw2.follow(usrn, "mario");
  }
  // additionally, make @mario2 follow @luigi
  nw2.follow("mario2", "luigi");

  nw2.printDot();

  cout << "----------" << endl << endl;
}
