#include "cell.hpp"

Cell::Cell(): is_exposed_(false), is_flagged_(false), is_mine_(false), integer_clue_(0), index(-1) {};

Cell::~Cell() {};

Cell::Cell(const Cell& other):
  Subject(other),
  is_exposed_(other.is_exposed_),
  is_flagged_(other.is_flagged_),
  is_mine_(other.is_mine_),
  integer_clue_(other.integer_clue_) {}

Cell& Cell::operator=(const Cell& other) {
  Cell temp(other);
  Swap(temp);
  return *this;
}

void Cell::Swap(Cell &other) {
  using std::swap;
  swap(is_exposed_, other.is_exposed_);
  swap(is_flagged_, other.is_flagged_);
  swap(is_mine_, other.is_mine_);
  swap(integer_clue_, other.integer_clue_);
}

// TODO: more logic in this later
void Cell::PrintCell() {
  if (is_mine_) {
    cout << "*";
  } else if (integer_clue_ == 0) {
    cout << " ";
  } else if (integer_clue_ > 0) {
    cout << integer_clue_;
  }
}

void Cell::Notify() {
  if (!is_mine_) {
    ++integer_clue_;
  }
}

void Cell::PrintIndex() {
  cout << index << ", ";
}

void Cell::PlantMine() {
  is_mine_ = true;
  integer_clue_ = -1;
  NotifyObservers();
};
