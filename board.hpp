#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

#include "cell.hpp"

using namespace std;

class Board {
  char difficulty_level_;
  int board_size_;
  int cells_count_;
  int total_bomb_count_;
  vector<int> neighbour_index_differences_;
  string top_bottom_border_;
  string horizontal_indices_border_;
  vector<Cell*> cells_;
  ActionResultEnum last_action_result_;

  static const string kHorizontalBorderIndent;
  static const string kHorizontalBorderSegment;
  static const char kVerticalBorderSegment;
  static const unordered_map<char, int> kGameLevelToSize;

  void PrintCells();
  void GenerateMines();
  void SetUpCellsRelations();
  bool ValidateNeighbourIndex(int self_index, int neighbour_index);

public:
  Board();
  Board(char difficulty_level);
  Board(const Board& other);
  Board& operator= (const Board& other);
  ~Board();

  void Swap(Board& other);
  void PrintBoard();
  bool VerifySingleCoordinate(char coordinate);
  void ExecuteCommand(char command, char x_coordinate, char y_coordinate);
  void IncrementExposedCountBy1();

  int board_size() const;
  ActionResultEnum last_action_result() const;
  char difficulty_level() const;
};

#endif
