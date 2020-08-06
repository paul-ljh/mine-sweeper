#include "board.hpp"

const char Board::kHorizontalBorderSegment = '-';
const char Board::kVerticalBorderSegment = '|';

Board::Board() {};
Board::~Board() {};

Board::Board(int game_size)
  : game_size_(game_size),
    // TODO: randomly generate the following 2
    total_bomb_count_(0),
    remaining_bomb_count_(0),
    top_bottom_border_(string(game_size_ * 2, kHorizontalBorderSegment)) {};
    // cells_(vector<vector<Cell*>>(game_size_, vector<Cell*>(game_size_, &Cell()))) {};

Board::Board(const Board& other)
  : game_size_(other.game_size_),
    total_bomb_count_(other.total_bomb_count_),
    remaining_bomb_count_(other.remaining_bomb_count_),
    top_bottom_border_(other.top_bottom_border_)
{
  cout << "copy constructor" << endl;
};

void Board::Swap(Board& other)
{
  using std::swap;
  swap(game_size_, other.game_size_);
  swap(total_bomb_count_, other.total_bomb_count_);
  swap(remaining_bomb_count_, other.remaining_bomb_count_);
  swap(top_bottom_border_, other.top_bottom_border_);
};

Board& Board::operator= (const Board& other)
{
  cout << "copy assignment" << endl;
  Board temp(other);
  Swap(temp);
  return *this;
};

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
