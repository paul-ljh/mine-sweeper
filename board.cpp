#include "board.hpp"

Board::Board(int game_size): game_size_(game_size) {};

Board::~Board() {};

int Board::game_size() const {
  return game_size_;
};
