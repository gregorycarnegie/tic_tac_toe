#include <iostream>
#include <vector>

bool check_player(char player_char,  std::vector<std::vector<char>> grid);
void welcome_message();
void display_status(std::vector<std::vector<char>> grid);
void enter_char(char game_char, std::string coord, std::vector<std::vector<char>>& grid);
