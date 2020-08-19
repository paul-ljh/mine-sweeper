#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <iostream>

#include "observer.hpp"

using namespace std;

template<class T>
class Subject {
  vector<Observer<T>*> observers_;
public:
  Subject() {};
  virtual ~Subject() {};

  void Attach(Observer<T>* o) {
    observers_.push_back(o);
  };

  void Detach(Observer<T>* o) {
    remove(observers_.begin(), observers_.end(), o);
  };

  void NotifyObservers() {
    for (auto o : observers_) {
      o->Notify(static_cast<T*>(this));
    }
  };
};

#endif
