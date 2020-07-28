#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include "board.hpp"

class BoardView
{

public: 
  BoardView() {};
  BoardView(Board &board);
  // BoardView &operator = (const BoardView &other);
  ~BoardView();

  void PrintBoard();
};

#endif
