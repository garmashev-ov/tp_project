#include <iostream>
#include "field.cpp"
#include "console_interface.cpp"
#include "game.cpp"

int main() {
  Field player1, player2;
  AbstractInterface *interface = new ConsoleInterface;
  Game game{player1, player2, interface};
  game.interface_->Message("Do you want to place ships in random order? (y/n)\n");
  if (game.interface_->AskYesNo()) {
    while (true) {
      game.RandomPlacement(1);
      interface->PrintField(game.player1_, true);
      interface->Message("Save? (y/n)\n");
      if (!game.interface_->AskYesNo()) {
        game.player1_.ClearField();
      } else {
        interface->ClearScreen();
        break;
      }
    }
  } else {
    game.PlaceAllShips(game.player1_);
  }
  game.interface_->Message("Do you want to place ships in random order? (y/n)\n");
  if (game.interface_->AskYesNo()) {
    while (true) {
      game.RandomPlacement(2);
      interface->PrintField(game.player2_, true);
      interface->Message("Save? (y/n)\n");
      if (!game.interface_->AskYesNo()) {
        game.player2_.ClearField();
      } else {
        interface->ClearScreen();
        break;
      }
    }
  } else {
    game.PlaceAllShips(game.player2_);
  }
  game.PlayGame();
}




