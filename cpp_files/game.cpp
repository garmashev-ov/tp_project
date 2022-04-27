#include "../headers/game.h"

void Game::PlayGame() {
  int pl1_ships_alive = 20;
  int pl2_ships_alive = 20;
  bool pl1_shoots = true;
  while (pl1_ships_alive != 0 && pl2_ships_alive != 0) {
    Field &attacked = pl1_shoots ? player2_ : player1_;
    if (pl1_shoots) {
      interface_->Message("first player shoots");
    } else {
      interface_->Message("second player shoots");
    }
    interface_->PrintField(attacked, false);
    int n = 0;
    int ch = 0;
    while (true) {
      interface_->GetCell(ch, n);
      if (attacked.IsShotCorrect(n, ch)) {
        break;
      }
      interface_->Message("choose another cell");
    }
    if (attacked.field_[n][ch] == 0) {
      attacked.field_[n][ch] = 1;
      interface_->Message("you missed");
      if (pl1_shoots) {
        pl1_shoots = false;
      } else {
        pl1_shoots = true;
      }
      continue;
    }
    attacked.field_[n][ch] = 3;
    if (attacked.IsDestroyed(n, ch)) {
      interface_->Message("ship destroyed");
      attacked.MarkNearbyCells(n, ch);
    } else {
      interface_->Message("ship was hit");
    }
    if (pl1_shoots) {
      --pl2_ships_alive;
    } else {
      --pl1_ships_alive;
    }
  }
  if (pl1_ships_alive == 0) {
    interface_->Message("SECOND PLAYER WINS");
  } else {
    interface_->Message("FIRST PLAYER WINS");
  }
}

void Game::PlaceAllShips(Field &field) {
  interface_->PrintField(field, true);
  interface_->Message("place ship with length 4");
  PlaceShip(field, 4);
  interface_->PrintField(field, true);
  for (int i = 0; i < 2; ++i) {
    interface_->Message("place ship with length 3");
    PlaceShip(field, 3);
    interface_->PrintField(field, true);
  }
  for (int i = 0; i < 3; ++i) {
    interface_->Message("place ship with length 2");
    PlaceShip(field, 2);
    interface_->PrintField(field, true);
  }
  for (int i = 0; i < 4; ++i) {
    interface_->PrintField(field, true);
    interface_->Message("place ship with length 1");
    PlaceShip(field, 1);
  }
  interface_->ClearScreen();
}

void Game::PlaceShip(Field &field, int size) {
  int n1 = 0, ch1 = 0, n2 = 0, ch2 = 0;
  while (true) {
    interface_->GetCell(ch1, n1);
    interface_->GetCell(ch2, n2);
    if (field.CorrectPlacement(n1, ch1, n2, ch2, size)) {
      break;
    }
    interface_->Message("choose another cell");
  }
  if (n1 > n2 || ch1 > ch2) {
    std::swap(n1, n2);
    std::swap(ch1, ch2);
  }
  for (int i = n1; i <= n2; ++i) {
    field.field_[i][ch1] = 2;
  }
  for (int i = ch1; i <= ch2; ++i) {
    field.field_[n1][i] = 2;
  }
}