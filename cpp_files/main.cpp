#include <iostream>
#include "field.cpp"
#include "interface.cpp"

int main() {
  Field player1;
  Field player2;
  player1.PlaceAllShips();
  ClearScreen();
  player2.PlaceAllShips();
  ClearScreen();
  Game(player1, player2);
}

void Game(Field &pl1, Field &pl2) {
  int pl1_ships_alive = 20;
  int pl2_ships_alive = 20;
  bool pl1_shoots = true;
  while (pl1_ships_alive != 0 && pl2_ships_alive != 0) {
    Field &attacked = pl1_shoots? pl2 : pl1;
    if (pl1_shoots) {
      Message("first player shoots");
    } else {
      Message("second player shoots");
    }
    PrintField(attacked, false);
    int n = 0;
    int ch = 0;
    while (true) {
      GetCell(ch, n);
      if (attacked.IsShotCorrect(n, ch)) {
        break;
      }
      Message("choose another cell");
    }
    if (attacked.field_[n][ch] == 0) {
      attacked.field_[n][ch] = 1;
      Message("you missed");
      if (pl1_shoots) {
        pl1_shoots = false;
      } else {
        pl1_shoots = true;
      }
      continue;
    }
    attacked.field_[n][ch] = 3;
    if (attacked.IsDestroyed(n, ch)) {
      Message("ship destroyed");
      attacked.MarkNearbyCells(n, ch);
    } else {
      Message("ship was hit");
    }
    if (pl1_shoots) {
      --pl2_ships_alive;
    } else {
      --pl1_ships_alive;
    }
  }
}


