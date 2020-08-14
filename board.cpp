#include "board.hpp"

const char Board::kHorizontalBorderSegment = '-';
const char Board::kVerticalBorderSegment = '|';

Board::Board() {};
Board::~Board() {
  for (auto c : cells_) {
    delete c;
  }
};

Board::Board(int board_size)
  : // TODO: board_size_ will be determined by difficulty level
    board_size_(board_size),
    cells_count_(board_size_ * board_size_),

    // TODO: extract this out into a member function for different levels of difficulty
    total_bomb_count_(rand() % cells_count_),
    remaining_bomb_count_(total_bomb_count_),
    top_bottom_border_(string(board_size_, kHorizontalBorderSegment)) {
  cells_.reserve(cells_count_);
  for (int i = 0; i < cells_count_; ++i) {
    cells_.push_back(new Cell());
  }
  SetUpCellsRelations();
  GenerateMines();
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
  cout << " " << top_bottom_border_ << endl; // Top
  PrintCells();
  cout << " " << top_bottom_border_ << endl; // Bottom
};

void Board::PrintCells() {
  for (int i = 0; i < cells_.size(); i++) {
    if (i % board_size_ == 0) {
      cout << kVerticalBorderSegment;
    }
    cells_[i]->PrintCell();
    if ((i + 1) % board_size_ == 0) {
      cout << kVerticalBorderSegment << endl;
    }
  }
};

bool Board::ValidateNeighbourIndex(int self_index, int neighbour_index) {
  // First Column
  if ((self_index % board_size_ == 0) and (
    neighbour_index == self_index - 1 or
    neighbour_index == self_index - (board_size_ + 1) or
    neighbour_index == self_index + (board_size_ - 1))
  ) {
    return false;
  } 
  
  // Last Column
  if (((self_index + 1) % board_size_ == 0) and (
    neighbour_index == self_index + 1 or
    neighbour_index == self_index + (board_size_ + 1) or
    neighbour_index == self_index - (board_size_ - 1))
  ) {
    return false;
  }

  // First Row
  if ((self_index < board_size_) and (
    neighbour_index == self_index - board_size_ or
    neighbour_index == self_index - (board_size_ + 1) or
    neighbour_index == self_index - (board_size_ - 1))
  ) {
    return false;
  }

  // Last Row
  if ((self_index >= cells_count_ - board_size_ and self_index < cells_count_) and (
    neighbour_index == self_index + board_size_ or
    neighbour_index == self_index + (board_size_ + 1) or
    neighbour_index == self_index + (board_size_ - 1)) 
  ) {
    return false;
  }
  return true;
}

void Board::SetUpCellsRelations() {
  for (int i = 0; i < cells_.size(); i++) {
    // TODO: extract it out as a class const, static const when board_size_ becomes pre-set
    vector<int> neighbour_indices {
      // Left & Right
      i-1, i+1,
      // Up & Down
      i - board_size_, i + board_size_,
      // Up-right & Down-left
      i - (board_size_ - 1), i + (board_size_ - 1),
      // Up-left & Down-right
      i - (board_size_ + 1), i + (board_size_ + 1),
    };

    cells_[i]->index = i;
    for (int neighbour_index : neighbour_indices) {
      if (ValidateNeighbourIndex(i, neighbour_index)) {
        cells_[i]->Attach(cells_[neighbour_index]);
      }
    }
  }
}

void Board::GenerateMines() {
  using std::swap;
  int selected_index;
  int original_indices[total_bomb_count_];

  // Randomly select total_bomb_count_ Cells, turn them into mines, then swap them to the front of the array
  for (int i = 0; i < total_bomb_count_; i++) {
    selected_index = rand() % (cells_count_ - i) + i;
    original_indices[i] = selected_index;
    cells_[selected_index]->PlantMine();
    swap(cells_[selected_index], cells_[i]);
  }

  // swap them back to their original positions
  for (int i = total_bomb_count_ - 1; i >= 0; i--) {
    swap(cells_[original_indices[i]], cells_[i]);
  }

  // for (int i = 0; i < cells_.size(); i++) {
  //   cells_[i]->PrintIndex();
  //   cout << ": ";
  //   for (auto o : cells_[i]->observers_) {
  //     o->PrintIndex();
  //   }
  //   cout << endl;
  // }
};

void Board::GenerateClues() {}

int Board::board_size() const {
  return board_size_;
};
