#ifndef CELL_H
#define CELL_H

#include <iostream>

#include "subject.hpp"
#include "action_result_enum.hpp"

using namespace std;

class Cell : public Observer<Cell>, public Subject<Cell> {
  bool is_exposed_;
  bool is_flagged_;
  bool is_mine_;
  int integer_clue_;
  enum class NotifyActionEnum : int;
  NotifyActionEnum notify_action_;
  static int exposed_count_;
  static int remaining_flags_count_;
public:
  Cell();
  ~Cell();
  Cell(const Cell& other);
  Cell& operator=(const Cell& other);

  void Swap(Cell &other);
  void PlantMine();
  void PrintCell(ActionResultEnum result);
  void Expose();
  ActionResultEnum ExecuteCommand(char command);
  void Notify(Cell *subject) override;
  static int exposed_count();
  static int remaining_flags_count();
  static void set_remaining_flags_count(int value);
};

#endif
