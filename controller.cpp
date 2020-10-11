#include "controller.hpp"

enum class Controller::GameStateEnum {kInit, kChooseDifficulty, kInGame, kGameOver, kWin};
const char Controller::kGameLevelOptions[3] {'l', 'm', 'h'};
const char Controller::kActionOptions[2] {'e', 'f'};

Controller::Controller()
  : last_command_(""),
    action_('\0'),
    row_('\0'),
    column_('\0'),
    board_(nullptr),
    board_view_(nullptr),
    game_state_(GameStateEnum::kInit) {};

Controller::~Controller() {};

bool Controller::DispatchCommand(string command) {
  last_command_ = command;

  // quit, menu and cheers are accepted at all stages of game and will yield the same result
  if (last_command_.compare("quit") == 0) {
    return false;
  }
  else if (last_command_.compare("menu") == 0) {
    board_view_->MenuPrompt();
  }
  else if (last_command_.compare("cheers") == 0) {
    ClearActionData();
    ProceedToChooseDifficulty();
  }
  else {
    switch(game_state_) {
      case(GameStateEnum::kInit):
        board_view_->WarningPrompt(WarningPromptEnum::kInvalidCommand);
        break;

      case(GameStateEnum::kChooseDifficulty):
        ChooseDifficulty();
        break;

      case(GameStateEnum::kInGame):
        DispatchInGameCommand();
        break;

      /*
        default case covers GameStateEnum::kGameOver and GameStateEnum::kWin
        because those 2 stages only accept refresh, in addition to global commands - menu, cheers, refresh
      */
      default:
        DispatchGameOverOrWinCommand();
        break;
    }
  }
  return true;
}

void Controller::ProceedToChooseDifficulty() {
  game_state_ = GameStateEnum::kChooseDifficulty;
  board_view_->GameDifficultyLevelPrompt();
}

void Controller::ChooseDifficulty() {
  if (last_command_.size() == 1 and find(kGameLevelOptions, kGameLevelOptions + 3, last_command_[0]) != kGameLevelOptions + 3) {
    game_state_ = GameStateEnum::kInGame;
    StartGame(last_command_[0]);
    board_view_->ActionPrompt();
  }
  else {
    board_view_->WarningPrompt(WarningPromptEnum::kInvalidDifficultyLevel);
    board_view_->GameDifficultyLevelPrompt();
  }
}

// refresh, e, f, coordinate (1 character)
void Controller::DispatchInGameCommand() {
  if (last_command_.compare("refresh") == 0) {
    RefreshGame();
  }
  else if (last_command_.size() == 1) {
    DispatchUserAction();
  }
  else {
    board_view_->WarningPrompt(WarningPromptEnum::kInvalidCommand);
  }
};

void Controller::DispatchUserAction() {
  char command_char = last_command_[0];
  if (action_ == '\0') {
    if (find(kActionOptions, kActionOptions + 2, command_char) != kActionOptions + 2) {
      action_ = command_char;
      CoordinatePrompt();
    } else {
      board_view_->WarningPrompt(WarningPromptEnum::kInvalidUserAction);
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
    board_view_->WarningPrompt(WarningPromptEnum::kInvalidCoordinate);
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

    case ActionResultEnum::kWin:
      game_state_ = GameStateEnum::kWin;
      board_view_->PrintGame();
      board_view_->GameWinPrompt();
      break;

    case ActionResultEnum::kRepeat:
      board_view_->WarningPrompt(WarningPromptEnum::kRepeatedPosition);
      // NO break statement here becuz we want to execute the default actions after an repeated action

    default:
      ClearActionData();
      board_view_->PrintGame();
      board_view_->ActionPrompt();
      break;
  }
}

void Controller::DispatchGameOverOrWinCommand() {
  if (last_command_.compare("refresh") == 0) {
    RefreshGame();
  } else {
    board_view_->WarningPrompt(WarningPromptEnum::kInvalidCommand);
  }
}

void Controller::ClearActionData() {
  action_ = '\0';
  row_ = '\0';
  column_ = '\0';
}

void Controller::RefreshGame() {
  game_state_ = GameStateEnum::kInGame;
  char prev_difficulty_level = board_->difficulty_level();
  ClearActionData();
  StartGame(prev_difficulty_level);
  board_view_->ActionPrompt();
}

void Controller::StartGame(char difficulty_level) {
  board_ = shared_ptr<Board>(new Board(difficulty_level));
  unique_ptr<BoardView> new_boardview(new BoardView(board_));
  board_view_ = move(new_boardview);
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
