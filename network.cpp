#include <iostream>
using namespace std;

#include "profile.h"
#include "network.h"

Network::Network() {
  numUsers = 0;
  for (int i = 0; i < sizeof(profiles)/sizeof(profiles[0]); i++) {
    for (int j = 0; j < sizeof(profiles)/sizeof(profiles[0]); j++) {
      following[i][j] = 0;
    }
  }
}

int Network::findID(string usrn) {
  for (int i = 0; i < sizeof(profiles)/sizeof(profiles[0]); i++) {
    if (profiles[i].getUsername() == usrn) {
      return i;
    }
  }
  return -1;
}

bool Network::addUser(string usrn, string dspn) {
  bool checker = true;

  for (int i = 0; i < usrn.length(); i++) {
    // also works for empty strings
    if (!isalnum(usrn[i])) {
      return false;
    }
  }

  // if ID could be found and numUsers is maxed
  if (findID(usrn) != -1 || numUsers >= 20) {
    return false;
  }

  profiles[numUsers] = {usrn, dspn};
  numUsers++;
  return checker;
}

bool Network::follow(string usrn1, string usrn2) {
  // if same username
  if (usrn1 == usrn2) {
    return false;
  }
  
  if (findID(usrn1) != -1 && findID(usrn2) != -1) {
    following[findID(usrn1)][findID(usrn2)] = true;
    return true;
  }
  return false;
}

void Network::printDot() {
  cout << "diagraph {" << endl;

  for (int i = 0; i < numUsers; i++) {
    cout << "   \"@" << profiles[i].getUsername() << "\"" << endl;
  }

  cout << endl;

  for (int j = 0; j < numUsers; j++) {
    for (int k = 0; k < numUsers; k++) {
      if (following[j][k] == true) {
        cout << "   \"@" << profiles[j].getUsername() << "\" -> " << "\"@" << profiles[k].getUsername() << "\""<< endl;
      }
    }
  }

  cout << "}";
}
