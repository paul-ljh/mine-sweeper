#include "cell.hpp"

Cell::Cell(): is_exposed_(false), is_flagged_(false), is_mine_(false) {};

Cell::~Cell() {};

Cell::Cell(const Cell& other):
  is_exposed_(other.is_exposed_),
  is_flagged_(other.is_flagged_),
  is_mine_(other.is_mine_) {}

Cell& Cell::operator=(const Cell& other) {
  Cell temp(other);
  swap(temp);
  return *this;
}

void Cell::swap(Cell &other) {
  using std::swap;
  swap(is_exposed_, other.is_exposed_);
  swap(is_flagged_, other.is_flagged_);
  swap(is_mine_, other.is_mine_);
}

// TODO: more logic in this later
void Cell::PrintCell() {
  if (is_mine_) {
    cout << "*";
  } else {
    cout << " ";
  }
}

void Cell::set_is_mine(bool new_val) {
  is_mine_ = new_val;
};
