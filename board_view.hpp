#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include <iostream>

#include "board.hpp"

using namespace std;

class BoardView {
  Board* board_;

  static const string kActionPrompt;
  static const string kRowPrompt;
  static const string kColumnPrompt;
  static const string kGameDifficultyLevelPrompt;
  static const string kGameOverPrompt;
public: 
  BoardView();
  BoardView(Board* board);
  BoardView(const BoardView& other);
  BoardView& operator= (const BoardView& other);
  ~BoardView();

  void PrintGame();
  void ActionPrompt();
  void GameDifficultyLevelPrompt();
  void RowPrompt();
  void ColumnPrompt();
  void GameOverPrompt();

  // void set_board(Board& other);
};

#endif
