#include "bounty.h"
#include <string>

string Bounty::getLabel() {
  return this->name;
}

void Bounty::setName(string name) {
  this->name = name;
}

void Bounty::setCrime(string crime) {
  this->crime = crime;
}

void Bounty::setValue(int val) {
  this->value = val;
}

int Bounty::getValue() {
  return this->value;
}