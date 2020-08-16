#include "board.hpp"

const string Board::kHorizontalBorderSegment = "- ";
const char Board::kVerticalBorderSegment = '|';
const unordered_map<string, int> Board::kGameLevelToSize ({
  {"l", 10},
  {"m", 20},
  {"h", 26},
});

Board::Board() {};
Board::~Board() {
  for (auto c : cells_) {
    delete c;
  }
};

Board::Board(string difficulty_level)
  : difficulty_level_(difficulty_level),
    board_size_(kGameLevelToSize.find(difficulty_level_)->second),
    cells_count_(board_size_ * board_size_),
    horizontal_border_indices_("   "),
    top_bottom_border_("   "),
    // TODO: extract this out into a member function for different levels of difficulty
    total_bomb_count_(rand() % cells_count_),
    remaining_bomb_count_(total_bomb_count_),
    neighbour_index_differences_{
      -1, 1, // Left & Right
      -board_size_, board_size_, // Up & Down
      -(board_size_ - 1), (board_size_ - 1), // Up-right & Down-left
      -(board_size_ + 1), (board_size_ + 1), // Up-left & Down-right
    } {
  for (int i = 0; i < board_size_; ++i) {
    horizontal_border_indices_ += ('a' + i);
    horizontal_border_indices_ += " ";
    top_bottom_border_ += kHorizontalBorderSegment;
  }

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
  cout << horizontal_border_indices_ << endl; // Indices
  cout << top_bottom_border_ << endl; // Top
  PrintCells();
  cout << top_bottom_border_ << endl; // Bottom
};

void Board::PrintCells() {
  for (int i = 0; i < cells_.size(); i++) {
    if (i % board_size_ == 0) {
      cout << char('a' + i / board_size_) << " " << kVerticalBorderSegment;
    }
    cells_[i]->PrintCell();
    if ((i + 1) % board_size_ == 0) {
      cout << kVerticalBorderSegment << endl;
    } else {
      cout << " ";
    }
  }
};

// TODO: find a way to simplify this
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
    cells_[i]->index = i;
    for (int neighbour_index_diff : neighbour_index_differences_) {
      int neighbour_index = neighbour_index_diff + i;
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

bool Board::VerifySingleCoordinate(char coordinate) {
  return int(coordinate) >= int('a') and int(coordinate) < int('a' + board_size_);
};

bool Board::ExecuteCommand(char command, char x_coordinate, char y_coordinate) {
  int x, y, index;
  x = int(x_coordinate) - int('a');
  y = int(y_coordinate) - int('a');
  index = y * board_size_ + x;
  return cells_[index]->ExecuteCommand(command);
};

int Board::board_size() const {
  return board_size_;
};
