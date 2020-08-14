#include "controller.hpp"

const string Controller::kWelcomeMessage =
  "Welcome to Minesweeper 2020 Corona Version\n"
  "Type 'cheers' to continue or restart the game anytime\n";

const string Controller::kGameDifficultyLevelPrompt =
  "Choose a difficulty level:\n"
  "l: Low\n"
  "m: Intermidiate\n"
  "h: High\n";

const string Controller::kGameDifficultyLevelConfirmation = "You have chosen a game of level ";

const string Controller::kGameLevelOptions[3] {"l", "m", "h"};

Controller::Controller()
  : has_game_started_(false),
    board_(nullptr),
    board_view_(nullptr) {};

Controller::~Controller() {
  delete board_;
  delete board_view_;
};

// TODO: sanitize command
void Controller::DispatchCommand(string command) {
  // TODO: consider a map(string -> enum), then enum -> action via a switch statement
  if (command.compare("cheers") == 0) {
    LoadGame();
    set_has_game_started(false);
  } else if (find(kGameLevelOptions, kGameLevelOptions + 3, command) != kGameLevelOptions + 3) {
    cout << kGameDifficultyLevelConfirmation << command << endl << endl;
    set_has_game_started(true);
    StartGame(command);
  }
  // else /* game size */{
  //   // TODO: validate game_size_int
  //   // TODO: set a constraint on game_size_int
  //   stringstream game_size(command);
  //   int game_size_int;
  //   game_size >> game_size_int;
  //   cout << kGameSizeConfirmation << game_size_int << endl;

  //   set_has_game_started(true);
  //   StartGame(game_size_int);
  // }
  // refresh game (with same size n)

  // quit game

  /* action cmd with coordinate
  flag, unflag, expose */    
};

void Controller::WelcomePrompt() {
  cout << kWelcomeMessage;
};

void Controller::LoadGame() {
  cout << kGameDifficultyLevelPrompt;
};

void Controller::StartGame(string difficulty_level) {
  board_ = new Board(difficulty_level);
  board_view_ = new BoardView(board_);

  // TODO: re-consider Subject/Observer pattern since MVC does the trick
  board_->Attach(board_view_);
  board_->NotifyObservers();
};

bool Controller::has_game_started() const {
  return has_game_started_;
};

void Controller::set_has_game_started(bool new_val) {
  has_game_started_ = new_val;
};
