#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

#include "observer.hpp"

using namespace std;

class Subject {
  // TODO: memory leak here due to absence of destructor
  vector<Observer*> observers_;
public: 
  void Attach(Observer* o);
  void Detach(Observer* o);
  void NotifyObservers();
};

#endif
