#include <stdlib.h> 
#include "board.hpp"

const char Board::kHorizontalBorderSegment = '-';
const char Board::kVerticalBorderSegment = '|';

Board::Board() {};
Board::~Board() {};

Board::Board(int board_size)
  : board_size_(board_size),
    cells_count_(board_size_ * board_size_),

    // TODO: extract this out into a member function for different levels of difficulty
    total_bomb_count_(rand() % cells_count_),
    remaining_bomb_count_(total_bomb_count_),
    top_bottom_border_(string(board_size_, kHorizontalBorderSegment)),
    cells_(vector<Cell>(cells_count_, Cell())) {
  InitializeAllCells(); 
};

Board::Board(const Board& other)
  : board_size_(other.board_size_),
    total_bomb_count_(other.total_bomb_count_),
    remaining_bomb_count_(other.remaining_bomb_count_),
    top_bottom_border_(other.top_bottom_border_),
    cells_(other.cells_) {
  cout << "Board copy constructor" << endl;
};

void Board::Swap(Board& other) {
  using std::swap;
  swap(board_size_, other.board_size_);
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

void Board::PrintBoard() {
  // Top
  cout << " " << top_bottom_border_ << endl;

  // Cells
  PrintCells();

  // Bottom
  cout << " " << top_bottom_border_ << endl;
};

void Board::PrintCells() {
  for (int i = 0; i < cells_.size(); i++) {
    if (i % board_size_ == 0) {
      cout << kVerticalBorderSegment;
    }
    cells_[i].PrintCell();
    if ((i + 1) % board_size_ == 0) {
      cout << kVerticalBorderSegment << endl;
    }
  }
};

void Board::InitializeAllCells() {
  using std::swap;
  int selected_index, original_index;
  int indices[total_bomb_count_];
  Cell temp;

  // Randomly select total_bomb_count_ Cells, turn them into mines, then swap them to the front of the array
  for (int i = 0; i < total_bomb_count_; i++) {
    selected_index = rand() % (cells_count_ - i) + i;
    cells_[selected_index].set_is_mine(true);
    indices[i] = selected_index;
    swap(cells_[selected_index], cells_[i]);
  }

  // swap them back to their original positions
  for (int i = total_bomb_count_ - 1; i >= 0; i--) {
    int original_index = indices[i];
    swap(cells_[original_index], cells_[i]);
  }
};

int Board::board_size() const {
  return board_size_;
};
