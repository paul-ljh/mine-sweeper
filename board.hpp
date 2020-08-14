#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> 

#include "subject.hpp"
#include "cell.hpp"

using namespace std;

class Board : public Subject {
  int board_size_;
  int cells_count_;
  int total_bomb_count_;
  int remaining_bomb_count_;
  string top_bottom_border_;
  vector<Cell*> cells_;

  // const int neighbour_index_differences_[8];
  static const char kHorizontalBorderSegment;
  static const char kVerticalBorderSegment;

  // void PrintBorders() const;
  void PrintCells();
  void Swap(Board& other);
  void GenerateMines();
  void GenerateClues();
  void SetUpCellsRelations();
  bool ValidateNeighbourIndex(int self_index, int neighbour_index);

public:
  Board();
  Board(int board_size);
  Board(const Board& other);
  Board& operator= (const Board& other);
  ~Board();

  void PrintBoard();

  int board_size() const;
};

#endif
