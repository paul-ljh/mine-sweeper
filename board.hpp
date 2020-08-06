#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>

#include "subject.hpp"
#include "cell.hpp"

using namespace std;

class Board : public Subject
{
  int game_size_;
  int total_bomb_count_;
  int remaining_bomb_count_;
  string top_bottom_border_;
  // vector<vector<Cell*>> cells_;

  static const char kHorizontalBorderSegment;
  static const char kVerticalBorderSegment;

  void PrintBorders() const;
  void PrintCells() const;
  void Swap(Board& other);

public:
  Board();
  Board(int game_size);
  Board(const Board& other);
  Board& operator= (const Board& other);
  ~Board();

  void PrintBoard() const;
  int game_size() const;
};

#endif
