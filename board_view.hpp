#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include <iostream>

#include "board.hpp"

using namespace std;

class BoardView {
  Board* board_;

  static const string kActionPrompt;
  static const string kXCoordinatePrompt;
  static const string kYCoordinatePrompt;
  static const string kGameDifficultyLevelPrompt;
public: 
  BoardView();
  BoardView(Board* board);
  BoardView(const BoardView& other);
  BoardView& operator= (const BoardView& other);
  ~BoardView();

  void PrintGame();
  void ActionPrompt();
  void GameDifficultyLevelPrompt();
  void XCoordinatePrompt();
  void YCoordinatePrompt();
};

#endif
