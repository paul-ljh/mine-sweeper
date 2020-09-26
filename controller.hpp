#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <sstream>

#include "board.hpp"
#include "board_view.hpp"

using namespace std;

class Controller {
  string last_command_;
  char action_;
  char row_;
  char column_;
  // TODO: unique pointer?
  Board* board_;
  BoardView* board_view_;
  enum class GameStateEnum : int;
  GameStateEnum game_state_;

  static const char kGameLevelOptions[3];
  static const char kActionOptions[2];

  void DispatchInGameCommand();
  void DispatchUserAction();
  void DispatchGameOverOrWinCommand();
  void DispatchActionResult();
  void ProceedToChooseDifficulty();
  void ChooseDifficulty();
  void CoordinatePrompt();
  void ClearActionData();
  void StartGame(char difficulty_level);
  void RefreshGame();

public:
  Controller();
  ~Controller();
  bool DispatchCommand(string command);
  void Welcome();
};

#endif
