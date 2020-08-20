#include <iostream>
#include <string>
#include <sstream>

#include "board.hpp"
#include "board_view.hpp"
#include "controller.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  Controller game_controller;
  game_controller.Welcome();
  string command;

  while (true) {
    cin >> command;
    cout << endl;
    game_controller.DispatchCommand(command);
  }
  
  return 0;
}
