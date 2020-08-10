#include "board.hpp"

const char Board::kHorizontalBorderSegment = '-';
const char Board::kVerticalBorderSegment = '|';

Board::Board() {};
Board::~Board() {};

Board::Board(int game_size)
  : game_size_(game_size),
    // TODO: randomly generate the following 2
    total_bomb_count_(0),
    remaining_bomb_count_(0),

    top_bottom_border_(string(game_size_, kHorizontalBorderSegment)),
    cells_(vector<Cell>(game_size_ * game_size_, Cell())) {};

Board::Board(const Board& other)
  : game_size_(other.game_size_),
    total_bomb_count_(other.total_bomb_count_),
    remaining_bomb_count_(other.remaining_bomb_count_),
    top_bottom_border_(other.top_bottom_border_),
    cells_(other.cells_) {
  cout << "Board copy constructor" << endl;
};

void Board::Swap(Board& other) {
  using std::swap;
  swap(game_size_, other.game_size_);
  swap(total_bomb_count_, other.total_bomb_count_);
  swap(remaining_bomb_count_, other.remaining_bomb_count_);
  swap(top_bottom_border_, other.top_bottom_border_);
  swap(cells_, other.cells_);
};

Board& Board::operator=(const Board& other) {
  cout << "Board copy assignment" << endl;
  Board temp(other);
  Swap(temp);
  return *this;
};

void Board::PrintBoard() const {
  // Top
  cout << " " << top_bottom_border_ << endl;

  // Cells
  PrintCells();

  // Bottom
  cout << " " << top_bottom_border_ << endl;
};

void Board::PrintCells() const {
  for (int i = 0; i < cells_.size(); i++) {
    if (i % game_size_ == 0) {
      cout << kVerticalBorderSegment;
    }
    // TODO: printing placeholders currently
    cout << '2';
    if ((i + 1) % game_size_ == 0) {
      cout << kVerticalBorderSegment << endl;
    }
  }
};

int Board::game_size() const {
  return game_size_;
};
