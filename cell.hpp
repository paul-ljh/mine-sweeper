#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell
{
  bool is_exposed_;
  bool is_flagged_;

public:
  Cell();
  ~Cell();
  Cell(const Cell& other);
  Cell& operator=(const Cell& other);
};

#endif
