#include <iostream>
#include <string>
#include <sstream>

#include "board.hpp"
#include "board_view.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
  string cmd, game_size_string;
  int game_size_int;
  bool has_game_started = false;
  Board board;
  BoardView view;

  while (true)
  {
    if (!has_game_started)
    {
      cout << "Welcome to Mine Sweeper 2020 Corona Version" << endl;
      cout << "Type 'start' to continue" << endl;
    }

    cin >> cmd;
    cout << endl;

    // start game with game size n
    if (cmd.compare("start") == 0)
    {
      cout << "Type a positive integer to officially start the game" << endl;
      cin >> game_size_string;
      cout << endl;

      stringstream size(game_size_string);
      size >> game_size_int;
      cout << "You have chosen a board of size " << game_size_int << endl;
      // TODO: validate game_size_int

      has_game_started = true;
      board = Board(game_size_int);
      view = BoardView(&board);
      board.Attach(&view);
      board.NotifyObservers();
    }
    

    // restart game (go back to start cmd)

    // refresh game (with same size n)

    // quit game

    /* action cmd with coordinate
    flag, unflag, expose */    
  }
  
  return 0;
}
