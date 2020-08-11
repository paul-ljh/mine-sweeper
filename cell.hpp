#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell
{
  bool is_exposed_;
  bool is_flagged_;
  bool is_mine_;

  void swap(Cell &other);

public:
  Cell();
  ~Cell();
  Cell(const Cell& other);
  Cell& operator=(const Cell& other);

  void PrintCell();
  void set_is_mine(bool new_val);
};

#endif
