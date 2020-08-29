#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include <iostream>

#include "board.hpp"

using namespace std;

class BoardView {
  Board* board_;

  static const string kWelcomeMessage;
  static const string kMenu;
  static const string kActionPrompt;
  static const string kRowPrompt;
  static const string kColumnPrompt;
  static const string kGameDifficultyLevelPrompt;
  static const string kGameOverPrompt;
  static const string kGameWinPrompt;
  static const string kAlienCommandPrompt;
public: 
  BoardView();
  BoardView(Board* board);
  BoardView(const BoardView& other);
  BoardView& operator= (const BoardView& other);
  ~BoardView();

  void WelcomePrompt();
  void ActionPrompt();
  void GameDifficultyLevelPrompt();
  void RowPrompt();
  void ColumnPrompt();
  void GameOverPrompt();
  void MenuPrompt();
  void AlienCommandPrompt();
  void PrintGame();
  void GameWinPrompt();
};

#endif
