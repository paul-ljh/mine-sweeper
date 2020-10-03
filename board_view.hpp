#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H

#include <iostream>

#include "board.hpp"
#include "warning_prompt_enum.hpp"

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
  static const string kFlagCountPrompt;

  static const string kRepeatedPositionPrompt;
  static const string kInvalidCommandPrompt;
  static const string kInvalidDifficultyLevelPrompt;
  static const string kInvalidUserActionPrompt;
  static const string kInvalidCoordinatePrompt;

  void PrintFlagCounts() const;
public:
  BoardView();
  BoardView(Board* board);
  BoardView(const BoardView& other);
  BoardView& operator= (const BoardView& other);
  ~BoardView();

  void WarningPrompt(WarningPromptEnum which_warning) const;

  void WelcomePrompt() const;
  void ActionPrompt() const;
  void GameDifficultyLevelPrompt() const;
  void RowPrompt() const;
  void ColumnPrompt() const;
  void GameOverPrompt() const;
  void MenuPrompt() const;
  void PrintGame() const;
  void GameWinPrompt() const;
};

#endif
