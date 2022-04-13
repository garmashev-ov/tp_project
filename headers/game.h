#ifndef TP_HEADERS_GAME_H_
#define TP_HEADERS_GAME_H_
#include "abstract_interface.h"

class Game {
 public:
  Field player1_;
  Field player2_;
  AbstractInterface *interface_;
  void PlayGame();
  void PlaceAllShips(Field &field);
  void PlaceShip(Field &field, int size);
};
#endif
