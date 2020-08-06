#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "subject.hpp"

using namespace std;

class Board : public Subject
{
  int game_size_;
  int total_bomb_count_;
  int remaining_bomb_count_;
  string top_bottom_border_;

  static const char horizontal_border_segment_;
  static const char vertical_border_segment_;

  void PrintBorders() const;
  void PrintCells() const;
  // void Swap(Board& other);

public:
  Board() {};
  Board(int game_size);
  // Board& operator= (const Board& other);
  ~Board();

  void PrintBoard() const;
  int game_size() const;
};

#endif
