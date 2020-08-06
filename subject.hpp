#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

#include "observer.hpp"

using namespace std;

class Subject
{
  vector<Observer*> observers_;
public: 
  void Attach(Observer* o);
  void Detach(Observer* o);
  void NotifyObservers();
};

#endif
