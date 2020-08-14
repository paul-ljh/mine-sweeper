#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdlib.h> 

#include "subject.hpp"
#include "cell.hpp"

using namespace std;

class Board : public Subject {
  string difficulty_level_;
  int board_size_;
  int cells_count_;
  int total_bomb_count_;
  int remaining_bomb_count_;
  int neighbour_index_differences_[8];
  string top_bottom_border_;
  string horizontal_border_indices_;
  vector<Cell*> cells_;
  
  static const string kHorizontalBorderSegment;
  static const char kVerticalBorderSegment;
  static const unordered_map<string, int> kGameLevelToSize;

  // void PrintBorders() const;
  void PrintCells();
  void Swap(Board& other);
  void GenerateMines();
  void GenerateClues();
  void SetUpCellsRelations();
  bool ValidateNeighbourIndex(int self_index, int neighbour_index);

public:
  Board();
  Board(string difficulty_level);
  Board(const Board& other);
  Board& operator= (const Board& other);
  ~Board();

  void PrintBoard();

  int board_size() const;
};

#endif
