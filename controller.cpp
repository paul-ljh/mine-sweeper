#include "controller.hpp"

const string Controller::kWelcomeMessage =
  "Welcome to Mine Sweeper 2020 Corona Version\n"
  "Type 'cheers' to continue\n";

const string Controller::kGameSizePrompt = "Type a positive integer to officially start the game\n";

const string Controller::kGameSizeConfirmation = "You have chosen a board of size ";

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
  } else /* game size */{
    // TODO: validate game_size_int
    // TODO: set a constraint on game_size_int
    stringstream game_size(command);
    int game_size_int;
    game_size >> game_size_int;
    cout << kGameSizeConfirmation << game_size_int << endl;

    set_has_game_started(true);
    StartGame(game_size_int);
  }
  // restart game (go back to start cmd)

  // refresh game (with same size n)

  // quit game

  /* action cmd with coordinate
  flag, unflag, expose */    
};

void Controller::WelcomePrompt() {
  cout << kWelcomeMessage;
};

void Controller::LoadGame() {
  cout << kGameSizePrompt;
};

void Controller::StartGame(int game_size) {
  board_ = new Board(game_size);
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
