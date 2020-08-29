#include "cell.hpp"

enum class Cell::NotifyActionEnum {kPlantMine, kExpose};
int Cell::exposed_count_ = 0;
int Cell::remaining_flags_count_ = 0;

Cell::Cell():
  is_exposed_(false),
  is_flagged_(false),
  is_mine_(false),
  integer_clue_(0),
  notify_action_(NotifyActionEnum::kPlantMine) {};

Cell::~Cell() {};

Cell::Cell(const Cell& other):
  is_exposed_(other.is_exposed_),
  is_flagged_(other.is_flagged_),
  is_mine_(other.is_mine_),
  integer_clue_(other.integer_clue_),
  notify_action_(other.notify_action_) {}

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
  swap(notify_action_, other.notify_action_);
};

void Cell::PrintCell(ActionResultEnum result) {
  switch (result) {
    case ActionResultEnum::kGameOver:
      if (is_mine_) {
        cout << "*";
      } else {
        cout << integer_clue_;
      }
      break;

    default:
      if (is_exposed_) {
        cout << integer_clue_;
      } else if (is_flagged_) {
        cout << "F";
      } else {
        cout << " ";
      }
      break;
  }
};

ActionResultEnum Cell::ExecuteCommand(char command) {
  if (is_exposed_ == true) {
    return ActionResultEnum::kRepeat;
  } else {
    if (command == 'e') {
      if (is_mine_ == true) {
        return ActionResultEnum::kGameOver;
      } else {
        Expose();
        return ActionResultEnum::kContinue;
      }
    } else /* flag action */ {
      is_flagged_ = !is_flagged_;
      remaining_flags_count_ += (is_flagged_ ? -1 : 1);
      return ActionResultEnum::kFlag;
    }
  }
};

void Cell::Expose() {
  if (is_flagged_ == true) {
    remaining_flags_count_++;
  }
  is_flagged_ = false;
  is_exposed_ = true;
  exposed_count_++;
  if (integer_clue_ == 0) {
    notify_action_ = NotifyActionEnum::kExpose;
    NotifyObservers();
  }
};

void Cell::Notify(Cell *subject) {
  switch (subject->notify_action_) {
    case NotifyActionEnum::kPlantMine:
      if (!is_mine_) {
        ++integer_clue_;
      }
      break;
    
    case NotifyActionEnum::kExpose:
      if (!is_exposed_) Expose();
      break;
  }
};

void Cell::PlantMine() {
  is_mine_ = true;
  integer_clue_ = -1;
  notify_action_ = NotifyActionEnum::kPlantMine;
  NotifyObservers();
};

int Cell::exposed_count() {
  return exposed_count_;
};

int Cell::remaining_flags_count() {
  return remaining_flags_count_;
};

void Cell::set_remaining_flags_count(int value) {
  Cell::remaining_flags_count_ = value;
};
