#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include <iostream>

#include "board.hpp"
#include "observer.hpp"

using namespace std;

class BoardView : public Observer {
  Board* board_;
public: 
  BoardView();
  BoardView(Board* board);
  BoardView(const BoardView& other);
  BoardView& operator= (const BoardView& other);
  ~BoardView();

  void PrintBoard();
  void Notify() override;
  void PrintIndex() override {};
};

#endif
