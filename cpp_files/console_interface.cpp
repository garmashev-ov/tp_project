#include <iostream>
#include "../headers/console_interface.h"

void ConsoleInterface::GetCell(int &ch, int &n) {
  std::string command;
  std::cin >> command;
  n = ch = 0;
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

void ConsoleInterface::PrintField(Field &f, bool show_ships) {
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
        } else if (f.field_[i][j] == 0) {
          std::cout << "- ";
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

void ConsoleInterface::Message(const char *msg) {
  std::cout << msg << '\n';
}

void ConsoleInterface::ClearScreen() {
#ifdef __linux
  system("clear");
#elif defined _WIN32
  system("cls");
#endif
}

bool ConsoleInterface::AskYesNo() {
  char response;
  std::cin >> response;
  if (response == 'y' || response == 'Y') {
    return true;
  }
  if (response == 'n' || response == 'N') {
    return false;
  }
  Message("print 'y' for yes, 'n' for no\n");
  AskYesNo();
}

