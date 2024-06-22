#include <iostream>
#include <vector>
#include "funcs.hpp"

int main() {
  std::vector<std::vector<char>> grid = {
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'},
  };
  
  welcome_message();
  bool player_o = false;
  bool player_x = false;
  char game_char;
  std::string coord;

  int turns = 1;
  while (turns <= 9 && (!player_o or !player_x)) {
    if (turns % 2 == 1) {
      game_char = 'o';
    } else {
      game_char = 'x';
    }
    
    enter_char(game_char, coord, grid);
    display_status(grid);

    if (check_player(game_char, grid)) {
      if (game_char == 'o') {
        player_o = true;
      }
      
      if (game_char == 'x') {
        player_x = true;
      }
      
      std::cout << ".:GAME OVER:.\n";
      turns = 10;
    }
    turns++;
  }
  if (turns == 9 && (!player_o or !player_x)) {
    std::cout << ".:IT'S A DRAW:.\n";
    std::cout << ".::GAME OVER::.\n";
  }
}
