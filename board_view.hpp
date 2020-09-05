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
  static const string kFlagCountPrompt;

  void PrintFlagCounts() const;
public:
  BoardView();
  BoardView(Board* board);
  BoardView(const BoardView& other);
  BoardView& operator= (const BoardView& other);
  ~BoardView();

  void WelcomePrompt() const;
  void ActionPrompt() const;
  void GameDifficultyLevelPrompt() const;
  void RowPrompt() const;
  void ColumnPrompt() const;
  void GameOverPrompt() const;
  void MenuPrompt() const;
  void AlienCommandPrompt() const;
  void PrintGame() const;
  void GameWinPrompt() const;
};

#endif
