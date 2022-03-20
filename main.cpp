#include <iostream>
#include "field.cpp"
#include "interface.cpp"

int main() {
  Field player1;
  Field player2;
  player1.PlaceAllShips();
  system ("cls");
  player2.PlaceAllShips();
  system ("cls");
  Game(player1, player2);
}

void Game(Field &pl1, Field &pl2) {
  int pl1_ships_alive = 20;
  int pl2_ships_alive = 20;
  bool pl1_shoots = true;
  while (pl1_ships_alive != 0 && pl2_ships_alive != 0) {
    Field &attacked = pl1_shoots? pl2 : pl1;
    std::cout << (pl1_shoots ? "first player shoots\n" : "second player shoots\n");
    PrintField(attacked, false);
    int n = 0;
    int ch = 0;
    incorrect_input:
    GetCell(ch, n);
    if (ch > 10 || n > 10 || ch < 0 || n < 0) {
      std::cout << "incorrect input\n";
      goto incorrect_input;
    }
    if (attacked.field_[n][ch] == 3 || attacked.field_[n][ch] == 1) {
      std::cout << "choose another cell\n";
      goto incorrect_input;
    }
    if (attacked.field_[n][ch] == 0) {
      attacked.field_[n][ch] = 1;
      std::cout << "you missed\n";
      if (pl1_shoots) {
        pl1_shoots = false;
      } else {
        pl1_shoots = true;
      }
      continue;
    }
    attacked.field_[n][ch] = 3;
    if (attacked.IsDestroyed(n, ch)) {
      std::cout << "ship destroyed\n";
      attacked.MarkNearbyCells(n, ch);
    } else {
      std::cout << "ship is hit\n";
    }
    if (pl1_shoots) {
      --pl2_ships_alive;
    } else {
      --pl1_ships_alive;
    }
  }
}


