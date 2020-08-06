#include "board.hpp"

const char Board::horizontal_border_segment_ = '-';
const char Board::vertical_border_segment_ = '|';
// const string Board::top_bottom_border = string(game_size_ * 2, horizontal_border_segment_);

Board::Board(int game_size)
  : game_size_(game_size),
    top_bottom_border_(string(game_size_ * 2, horizontal_border_segment_)) {};

Board::~Board() {};

// void Board::Swap(Board& other)
// {
//   using std::swap;
//   int game_size_;
//   int total_bomb_count_;
//   int remaining_bomb_count_;
//   const string top_bottom_border_;
// };

// Board& Board::operator= (const Board& other)
// {

// };

void Board::PrintBoard() const 
{
  PrintBorders();
};

void Board::PrintBorders() const 
{
  // string top_bottom_border(game_size_ * 2, horizontal_border_segment_);
  // Top
  cout << top_bottom_border_ << endl;
  // Bottom
  cout << top_bottom_border_ << endl;
};

void Board::PrintCells() const
{};

int Board::game_size() const {
  return game_size_;
};
