#include <iostream>
#include "../headers/field.h"
#include "../headers/interface.h"

void GetCell(int &ch, int &n) {
  std::string command;
  std::cin >> command;
  for (int i = 0; i < command.size(); ++i) {
    if (isalpha(command[i])) {
      ch = command[i] - 'a' + 1;
      break;
    }
  }
  for (int i = 0; i < command.size(); ++i) {
    if (isdigit(command[i])) {
      n = command[i] - '0';
      if ((n == 1) && (i + 1 < command.size()) && (command[i + 1] == '0')) {
        n = 10;
      }
      break;
    }
  }
}

void PrintField(Field &f, bool show_ships) {
  char coord[11] = "abcdefghij";
  std::cout << "   ";
  for (int i = 0; i < 10; ++i) {
    std::cout << coord[i] << " ";
  }
  std::cout << '\n';
  for (int i = 1; i <= 10; ++i) {
    std::cout << i << " ";
    if (i != 10) {
      std::cout << " ";
    }
    for (int j = 1; j <= 10; ++j) {
      if (show_ships) {
        if (f.field_[i][j] == 2) {
          std::cout << "# ";
        } else {
          std::cout << f.field_[i][j] << " ";
        }
      } else {
        if (f.field_[i][j] == 3) {
          std::cout << "x ";  // destroyed
        } else if (f.field_[i][j] == 1) {
          std::cout << "o ";  // clear
        } else {
          std::cout << "  ";
        }
      }
    }
    std::cout << '\n';
  }
}

void Message(const char *msg) {
  std::cout << msg << '\n';
}

void ClearScreen() {
  #ifdef __linux
    system("clear");
  #elif defined _WIN32
    system("cls");
  #endif
}

