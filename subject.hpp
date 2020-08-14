#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <iostream>

#include "observer.hpp"

using namespace std;

class Subject {

public:
  // TODO: move back under private
  vector<Observer*> observers_;

  void Attach(Observer* o);
  void Detach(Observer* o);
  void NotifyObservers();
};

#endif
