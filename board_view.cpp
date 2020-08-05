#include "board_view.hpp"
#include <iostream>

using namespace std;

BoardView::BoardView(): board_(nullptr)
{};

BoardView::BoardView(Board* board): board_(board)
{};

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
  cout << board_->game_size() << endl;
};

void BoardView::Notify()
{
  cout << "attached" << endl;
  PrintBoard();
};
