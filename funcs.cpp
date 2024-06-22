#include <iostream>
#include <vector>


void print_win(char letter) {
    std::cout << "Player " << letter << " wins!!!\n";
}


bool check_horizontal(char letter, std::vector<std::vector<char>> grid) {
  bool win = false;
  for (int i = 0; i < grid.size(); i++) {
    int count = 0;
    for (int j = 0; j < grid[i].size(); j++) {
      if (grid[i][j] == letter) {
        count++;
      } else {
        count = 0;
      }
      if (count == 3) {
        win = true;
        print_win(letter);
        return win;
      }
    }
  }
  return win;
}


bool check_vertical(char letter, std::vector<std::vector<char>> grid) {
  bool win = false;
  for (int i = 0; i < grid.size(); i++) {
    int count = 0;
    for (int j = 0; j < grid.size(); j++) {
      if (grid[j][i] == letter) {
        count++;
      } else {
        count = 0;
      }
      if (count == 3) {
        win = true;
        print_win(letter);
        return win;
      }
    }
    return win;
  }
}


bool check_diagonal(char letter, std::vector<std::vector<char>> grid) {
  bool win = false;
  int count = 0;

  // Check main diagonal
  for (int i = 0; i < grid.size(); i++) {
    if (grid[i][i] == letter) {
      count++;
    } else {
      count = 0;
    }
    if (count == 3) {
      win = true;
      print_win(letter);
      return win;
    }
  }

  count = 0;
  // Check anti-diagonal
  for (int i = 0; i < grid.size(); i++) {
    if (grid[i][grid.size() - 1 - i] == letter) {
      count++;
    } else {
      count = 0;
    }
    if (count == 3) {
      win = true;
      print_win(letter);
      return win;
    }
  }
  return win;
}



bool check_player(char player_char,  std::vector<std::vector<char>> grid) {
  bool a = check_horizontal(player_char, grid);
  bool b = check_vertical(player_char, grid);
  bool c = check_diagonal(player_char, grid);
  return a || b || c;
}

void welcome_message() {
  std::cout << "________________________\n";
  std::cout << "WELCOME TO TIC-TAC-TOE!!\n";
  std::cout << "________________________\n\n";

  std::cout << "Player 1 is 'O's amd player 2 is 'X's\n\n";
  std::cout << "Check out the coordinate system!\n";
  std::cout << "{0,0 | 0,1 | 0,2\n";
  std::cout << " 1,0 | 1,1 | 1,2\n";
  std::cout << " 2,0 | 2,1 | 2,2}\n\n";
}

void display_status(std::vector<std::vector<char>> grid) {
  std::cout << "\n";
  for (int i = 0; i < grid.size(); i++) {
    if (i > 0) {
      std::cout << " ";
    } else {
      std::cout << "{";
    }
    for (int j = 0; j < grid[i].size(); j++) {
      std::cout << grid[i][j] << " ";
      if (j < grid[i].size() - 1) {
        std::cout << "| ";
      } else if  (i < grid.size() - 1) {
        std::cout << "\n";
      }
    }
  }
  std::cout << "}\n";
  std::cout << "\n";
}

bool check_input(int x, int y) {
  return (0 <= x && x <= 2) && (0 <= y && y <= 2);
}



void enter_char(char game_char, std::string coord, std::vector<std::vector<char>>& grid) {
    int x, y;
    std::cout << "Player " << game_char << "'s turn.\n";
    bool try_again = true;
    while (try_again) {
      std::cin >> coord;
      y = coord.front() - '0';
      x = coord.back() - '0';
      try_again = !check_input(x, y);
      if (try_again) {
        std::cout << "Try again layer " << game_char << ".\n";
        std::cout << "Only type digits between 0 and 2.\n";
        continue;
      }
      if (grid[y][x] != '_') {
        try_again = true;
        std::cout << "Try again layer " << game_char << ".\n";
        std::cout << "Your rival has already played there.\n";
      }
    }
    grid[y][x] = game_char;
}
