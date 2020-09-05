#include <iostream>
#include <string>
#include <sstream>

#include "board.hpp"
#include "board_view.hpp"
#include "controller.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  Controller game_controller;
  string command;
  bool result;

  game_controller.Welcome();
  while (true) {
    cin >> command;
    result = game_controller.DispatchCommand(command);
    if (result == false) {
      break;
    }
  }
  return 0;
}
