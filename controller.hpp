#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <sstream>

#include "board.hpp"
#include "board_view.hpp"

using namespace std;

class Controller {
  bool has_game_started_;
  char action_;
  char x_coordinate_;
  char y_coordinate_;
  Board* board_;
  BoardView* board_view_;

  static const string kWelcomeMessage;
  static const string kGameDifficultyLevelConfirmation;
  static const string kGameLevelOptions[3];
  static const char kActionOptions[2];

public:
  Controller();
  ~Controller();

  void DispatchCommand(string command);
  void WelcomePrompt();
  void LoadGame();
  void StartGame(string difficulty_level);
  void PrintWelcomeMessage();
  void CoordinatePrompt();

  bool has_game_started() const;
  void set_has_game_started(bool new_val);
};

#endif
