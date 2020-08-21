#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
using namespace std;

template<class T>
class Observer {
public:
  Observer() {};
  virtual ~Observer() {};
  virtual void Notify(T *subject) = 0;
};

#endif
