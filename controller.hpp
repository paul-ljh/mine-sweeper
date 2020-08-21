#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <sstream>

#include "board.hpp"
#include "board_view.hpp"

using namespace std;

class Controller {
  char action_;
  char row_;
  char column_;
  Board* board_;
  BoardView* board_view_;
  enum class GameStateEnum : int;
  GameStateEnum game_state_;

  static const string kGameLevelOptions[3];
  static const char kActionOptions[2];

  void DispatchInGameCommand(string command);
  void DispatchUserAction(char command_char);
  void DispatchActionResult();
  void ProceedToChooseDifficulty();
  void ChooseDifficulty(string command);
  void StartGame(string difficulty_level);
  void CoordinatePrompt();
  void ClearActionData();

public:
  Controller();
  ~Controller();
  bool DispatchCommand(string command);
  void Welcome();
};

#endif
