#include "controller.hpp"


// TODO: MOVE all static strings to BoardView
const string Controller::kWelcomeMessage =
  "Welcome to Minesweeper 2020 Corona Version\n"
  "Type 'cheers' to continue or restart the game anytime\n";

const string Controller::kGameDifficultyLevelConfirmation = "You have chosen a game of level ";

const string Controller::kGameLevelOptions[3] {"l", "m", "h"};

const char Controller::kActionOptions[2] {'e', 'f'};

Controller::Controller()
  : has_game_started_(false),
    action_('\0'),
    row_('\0'),
    column_('\0'),
    board_(nullptr),
    board_view_(nullptr) {};

Controller::~Controller() {
  delete board_;
  delete board_view_;
};

// TODO: sanitize command
// TODO: break up this method
void Controller::DispatchCommand(string command) {
  // TODO: consider a map(string -> enum), then enum -> action via a switch statement
  if (command.compare("cheers") == 0) {
    ClearUserData();
    board_view_->GameDifficultyLevelPrompt();
    set_has_game_started(false);
  } else {
    if (has_game_started_ == false) {
      if (find(kGameLevelOptions, kGameLevelOptions + 3, command) != kGameLevelOptions + 3) {
        cout << kGameDifficultyLevelConfirmation << command << endl << endl;
        set_has_game_started(true);
        StartGame(command);
        board_view_->ActionPrompt();
      } else {
        cout << "Choose a valid game level for God's teeth!\n" << endl;
        board_view_->GameDifficultyLevelPrompt();
      }
    } else {
      if (command.compare("refresh") == 0) {
        string prev_difficulty_level = board_->difficulty_level();
        ClearUserData();
        // ClearGameData();
        StartGame(prev_difficulty_level);
        board_view_->ActionPrompt();
      }
      
      else if (command.size() == 1) {
        char command_char = command[0];
        if (action_ == '\0') {
          if (find(kActionOptions, kActionOptions + 2, command_char) != kActionOptions + 2) {
            action_ = command_char;
            CoordinatePrompt();
          } else {
            cout << "Choose a valid action God Bless the Queen!\n";
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
            ActionResultDispatcher();
          }
        } else {
          cout << "Choose a valid coordinate Merlin's Beard!\n" << endl;
          CoordinatePrompt();
        }
      }
    }
  }
  // quit game 
  // menu
};

void Controller::ActionResultDispatcher() {
  switch (board_->last_action_result()) {
    case ActionResultEnum::kRepeat:
      cout << "You have swept this one already mate!" << endl;

    case ActionResultEnum::kGameOver:
      board_view_->PrintGame();
      board_view_->GameOverPrompt();
      // TODO: destory Board and BoardView
      break;
    
    default:
      board_view_->PrintGame();
      board_view_->ActionPrompt();
      ClearUserData();
      break;
  }
}

void Controller::ClearUserData() {
  action_ = '\0';
  row_ = '\0';
  column_ = '\0';
}

void Controller::ClearGameData() {
  // board_ = Board();
};

void Controller::WelcomePrompt() {
  cout << kWelcomeMessage;
};

// void Controller::LoadGame() {
//   board_view_.GameDifficultyLevelPrompt();
// };

void Controller::StartGame(string difficulty_level) {
  board_ = new Board(difficulty_level);
  board_view_ = new BoardView(board_);
  // board_view_.set_board(board_);
  board_view_->PrintGame();
};

void Controller::CoordinatePrompt() {
  if (row_ == '\0' and column_ == '\0') {
    board_view_->RowPrompt();
  } else {
    board_view_->ColumnPrompt();
  }
}

bool Controller::has_game_started() const {
  return has_game_started_;
};

void Controller::set_has_game_started(bool new_val) {
  has_game_started_ = new_val;
};
