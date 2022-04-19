#include <iostream>
#include "field.cpp"
#include "console_interface.cpp"
#include "game.cpp"

int main() {
  Field player1, player2;
  AbstractInterface *interface = new ConsoleInterface;
  Game game{player1, player2, interface};
  game.PlaceAllShips(game.player1_);
  game.PlaceAllShips(game.player2_);
  game.PlayGame();
}




