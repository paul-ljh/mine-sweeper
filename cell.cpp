#include "cell.hpp"

Cell::Cell(): is_exposed_(false), is_flagged_(false), is_mine_(false), integer_clue_(0), index(-1) {};

Cell::~Cell() {};

Cell::Cell(const Cell& other):
  is_exposed_(other.is_exposed_),
  is_flagged_(other.is_flagged_),
  is_mine_(other.is_mine_),
  integer_clue_(other.integer_clue_) {}

Cell& Cell::operator=(const Cell& other) {
  Cell temp(other);
  Swap(temp);
  return *this;
};

void Cell::Swap(Cell &other) {
  using std::swap;
  swap(is_exposed_, other.is_exposed_);
  swap(is_flagged_, other.is_flagged_);
  swap(is_mine_, other.is_mine_);
  swap(integer_clue_, other.integer_clue_);
};

void Cell::PrintCell() {
  if (is_exposed_) {
    cout << integer_clue_;
  } else if (is_flagged_) {
    cout << "f";
  } else {
    cout << " ";
  }
  // if (is_mine_) {
  //   cout << "*";
  // } else if (integer_clue_ == 0) {
  //   cout << " ";
  // } else if (integer_clue_ > 0) {
  //   cout << integer_clue_;
  // }
};

bool Cell::ExecuteCommand(char command) {
  if (is_exposed_ == true) {
    cout << "You have already swept this one mate" << endl;
  } else {
    if (command == 'e') {
      if (is_mine_ == true) {
        // TODO: gameover
      } else {
        Expose();
      }
    } else /* flag action */ {
      is_flagged_ = !is_flagged_;
    }
  }
  return true;
};

void Cell::Expose() {
  // TODO
};

void Cell::Notify() {
  if (!is_mine_) {
    ++integer_clue_;
  }
};

void Cell::PrintIndex() {
  cout << index << ", ";
};

void Cell::PlantMine() {
  is_mine_ = true;
  integer_clue_ = -1;
  NotifyObservers();
};
