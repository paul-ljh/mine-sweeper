#include "board_view.hpp"
#include <iostream>

using namespace std;

BoardView::BoardView(): board_(nullptr) {};

BoardView::BoardView(Board* board): board_(board) {};

// BoardView::BoardView(const BoardView& other):
//   board_(new Board(*(other.board_))) {};

BoardView& BoardView::operator= (const BoardView& other)
{
  using std::swap;
  BoardView temp(other);
  swap(board_, temp.board_);
  return *this;
};

BoardView::~BoardView()
{};

void BoardView::PrintBoard()
{
  board_->PrintBoard();
};

void BoardView::Notify()
{
  PrintBoard();
};
