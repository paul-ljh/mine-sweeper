#include "board_view.hpp"

using namespace std;

const string BoardView::kActionPrompt = "Please enter your action for the next move, e for expose or f for flag: ";
const string BoardView::kXCoordinatePrompt = "Please enter the X coordinate of your next move: ";
const string BoardView::kYCoordinatePrompt = "Please enter the Y coordinate of your next move: ";
const string BoardView::kGameDifficultyLevelPrompt =
  "Choose a difficulty level:\n"
  "l: Low\n"
  "m: Intermidiate\n"
  "h: High\n";

BoardView::BoardView(): board_(nullptr) {};

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
  cout << kGameDifficultyLevelPrompt << endl;
};

void BoardView::ActionPrompt() {
  cout << kActionPrompt;
};

void BoardView::XCoordinatePrompt() {
  cout << kXCoordinatePrompt;
};

void BoardView::YCoordinatePrompt() {
  cout << kYCoordinatePrompt;
};

