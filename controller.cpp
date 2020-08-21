#include "controller.hpp"

enum class Controller::GameStateEnum {kInit, kChooseDifficulty, kInGame, kGameOver, kWin};
const string Controller::kGameLevelOptions[3] {"l", "m", "h"};
const char Controller::kActionOptions[2] {'e', 'f'};

Controller::Controller()
  : action_('\0'),
    row_('\0'),
    column_('\0'),
    board_(nullptr),
    board_view_(nullptr),
    game_state_(GameStateEnum::kInit) {};

Controller::~Controller() {
  delete board_;
  delete board_view_;
};

bool Controller::DispatchCommand(string command) {
  if (command.compare("quit") == 0) {
    return false;
  } 
  else if (command.compare("menu") == 0) {
    board_view_->MenuPrompt();
  }
  else if (command.compare("cheers") == 0) {
    ClearActionData();
    ProceedToChooseDifficulty();
  }
  else {
    switch(game_state_) {
      case(GameStateEnum::kInit):
        board_view_->AlienCommandPrompt();
        break;

      case(GameStateEnum::kChooseDifficulty):
        ChooseDifficulty(command);
        break;

      case(GameStateEnum::kInGame):
        DispatchInGameCommand(command);
        break;
      
      case(GameStateEnum::kGameOver):
        // TODO
        break;
      
      case(GameStateEnum::kWin):
        // TODO
        break;
    }
  }
  return true;
}

void Controller::ProceedToChooseDifficulty() {
  game_state_ = GameStateEnum::kChooseDifficulty;
  board_view_->GameDifficultyLevelPrompt();
}

void Controller::ChooseDifficulty(string command) {
  if (find(kGameLevelOptions, kGameLevelOptions + 3, command) != kGameLevelOptions + 3) {
    game_state_ = GameStateEnum::kInGame;
    StartGame(command);
    board_view_->ActionPrompt();
  } else {
    cout << "Choose a valid game level for God's teeth!\n" << endl;
    board_view_->GameDifficultyLevelPrompt();
  }
}

// refresh, e, f, coordinate
void Controller::DispatchInGameCommand(string command) {
  if (command.compare("refresh") == 0) {
    string prev_difficulty_level = board_->difficulty_level();
    ClearActionData();
    StartGame(prev_difficulty_level);
    board_view_->ActionPrompt();
  }
  
  else if (command.size() == 1) {
    char command_char = command[0];
    DispatchUserAction(command_char);
  }
};

void Controller::DispatchUserAction(char command_char) {
  if (action_ == '\0') {
    if (find(kActionOptions, kActionOptions + 2, command_char) != kActionOptions + 2) {
      action_ = command_char;
      CoordinatePrompt();
    } else {
      cout << "Choose a valid action God Save the Queen!\n";
      board_view_->ActionPrompt();
    }
  }

  else if (board_->VerifySingleCoordinate(command_char) == true) {
    if (row_ == '\0' and column_ == '\0') {
      row_ = command_char;
      CoordinatePrompt();
    } else {
      column_ = command_char;
      board_->ExecuteCommand(action_, row_, column_);
      DispatchActionResult();
    }
  }
  
  else {
    cout << "Choose a valid coordinate Merlin's Beard!\n" << endl;
    CoordinatePrompt();
  }
}

void Controller::DispatchActionResult() {
  switch (board_->last_action_result()) {
    case ActionResultEnum::kGameOver:
      game_state_ = GameStateEnum::kGameOver;
      ClearActionData();
      board_view_->PrintGame();
      board_view_->GameOverPrompt();
      break;
    
    case ActionResultEnum::kRepeat:
      cout << "You have swept this one already mate!\n" << endl;

    default:
      ClearActionData();
      board_view_->PrintGame();
      board_view_->ActionPrompt();
      break;
  }
}

void Controller::ClearActionData() {
  action_ = '\0';
  row_ = '\0';
  column_ = '\0';
}

void Controller::StartGame(string difficulty_level) {
  board_ = new Board(difficulty_level);
  board_view_ = new BoardView(board_);
  board_view_->PrintGame();
}

void Controller::CoordinatePrompt() {
  if (row_ == '\0' and column_ == '\0') {
    board_view_->RowPrompt();
  } else {
    board_view_->ColumnPrompt();
  }
}

void Controller::Welcome() {
  board_view_->WelcomePrompt();
};
