#include <iostream>

#include "subject.hpp"
using namespace std;

void Subject::Attach(Observer* o) {
  observers_.push_back(o);
}

void Subject::Detach(Observer* o) {
  remove(observers_.begin(), observers_.end(), o);
}

void Subject::NotifyObservers() {
  for (auto o : observers_) {
    o->Notify();
  }
}

