#include "board_view.hpp"

using namespace std;

const string BoardView::kActionPrompt = "Please enter your action for the next move, e for expose or f for flag: ";
const string BoardView::kRowPrompt = "Please enter the Row Letter of your next move: ";
const string BoardView::kColumnPrompt = "Please enter the Column Letter of your next move: ";
const string BoardView::kAlienCommandPrompt = "Sorry I don't understand this command\n\n";
const string BoardView::kFlagCountPrompt = "Flags Left: ";

const string BoardView::kGameDifficultyLevelPrompt =
  "\n"
  "l: Low\n"
  "m: Intermidiate\n"
  "h: High\n"
  "Choose a difficulty level: ";

const string BoardView::kGameOverPrompt =
  "BOOM! GAME OVER!\n"
  "Nice work though my dear chap!\n\n"
  "Type:\n"
  "'cheers' to select a different difficulty\n"
  "'refresh' to repeat the game\n"
  "'quit' to quit the game\n\n";

const string BoardView::kGameWinPrompt =
  "CONGRADULATIONS!\n"
  "You have won!\n\n"
  "Type:\n"
  "'cheers' to select a different difficulty\n"
  "'refresh' to repeat the game\n"
  "'quit' to quit the game\n\n";

const string BoardView::kWelcomeMessage =
  "Welcome to Minesweeper 2020 Corona Version\n"
  "Type 'menu' anytime to see the control menu of the game\n"
  "Type 'cheers' to continue\n\n";

const string BoardView::kMenu =
  "\n"
  "ACCEPTABLE AT ALL TIMES:\n"
  "'cheers': select game difficulty level\n"
  "'menu': see the control menu of the game\n"
  "'quit': quit the game\n\n"
  "ACCEPTABLE ONLY IN GAME:\n"
  "'refresh': start a new game of current difficulty level\n\n";

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

void BoardView::PrintGame() const {
  PrintFlagCounts();
  board_->PrintBoard();
};

void BoardView::GameDifficultyLevelPrompt() const {
  cout << kGameDifficultyLevelPrompt;
};

void BoardView::ActionPrompt() const {
  cout << kActionPrompt;
};

void BoardView::RowPrompt() const {
  cout << kRowPrompt;
};

void BoardView::ColumnPrompt() const {
  cout << kColumnPrompt;
};

void BoardView::GameOverPrompt() const {
  cout << kGameOverPrompt;
}

void BoardView::WelcomePrompt() const {
  cout << kWelcomeMessage;
};

void BoardView::MenuPrompt() const {
  cout << kMenu;
}

void BoardView::AlienCommandPrompt() const {
  cout << kAlienCommandPrompt;
}

void BoardView::GameWinPrompt() const {
  cout << kGameWinPrompt;
}

void BoardView::PrintFlagCounts() const {
  cout << endl;
  cout << kFlagCountPrompt;
  cout << Cell::remaining_flags_count();
  cout << endl;
}
