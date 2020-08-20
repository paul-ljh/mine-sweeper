#include "board_view.hpp"

using namespace std;

const string BoardView::kActionPrompt = "Please enter your action for the next move, e for expose or f for flag: ";
const string BoardView::kRowPrompt = "Please enter the Row Letter of your next move: ";
const string BoardView::kColumnPrompt = "Please enter the Column Letter of your next move: ";
const string BoardView::kGameDifficultyLevelPrompt =
  "l: Low\n"
  "m: Intermidiate\n"
  "h: High\n"
  "Choose a difficulty level: ";
const string BoardView::kGameOverPrompt = 
  "BOOM! GAME OVER!\n"
  "Nice work though my dear chap!\n\n"
  "Type 'cheers' to start a new game\n"
  "OR\n"
  "'quit' to quit the game\n"
  "OR\n"
  "'refresh' to repeat the game\n";
const string BoardView::kWelcomeMessage =
  "Welcome to Minesweeper 2020 Corona Version\n"
  "Type 'cheers' to continue or restart the game anytime\n";

BoardView::BoardView() {};

BoardView::BoardView(Board* board): board_(board) {};

BoardView::BoardView(const BoardView& other): board_(other.board_) {};

BoardView& BoardView::operator=(const BoardView& other) {
  using std::swap;
  BoardView temp(other);
  swap(board_, temp.board_);
  return *this;
};

BoardView::~BoardView() {};

void BoardView::PrintGame() {
  board_->PrintBoard();
};

void BoardView::GameDifficultyLevelPrompt() {
  cout << kGameDifficultyLevelPrompt;
};

void BoardView::ActionPrompt() {
  cout << kActionPrompt;
};

void BoardView::RowPrompt() {
  cout << kRowPrompt;
};

void BoardView::ColumnPrompt() {
  cout << kColumnPrompt;
};

void BoardView::GameOverPrompt() {
  cout << kGameOverPrompt;
}

void BoardView::WelcomePrompt() {
  cout << kWelcomeMessage;
};

// void BoardView::set_board(Board& other) {
//   board_ = other;
// }

