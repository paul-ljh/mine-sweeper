#ifndef BOARD_H
#define BOARD_H

#include "subject.hpp"

using namespace std;

class Board : public Subject
{
  int game_size_;
  int total_bomb_count_;
  int remaining_bomb_count_;

public:
  Board() {};
  Board(int game_size);
  // Board &operator = (const Board &other);
  ~Board();

  int game_size() const;
};

#endif
