#include <iostream>
#include "field.h"
#include "interface.h"

void Field::PlaceShip(int size) {
  int n1 = 0, ch1 = 0, n2 = 0, ch2 = 0;
  unsuccessful_attempt:
  GetCell(ch1, n1);
  GetCell(ch2, n2);
  if ((n1 != n2 && ch1 != ch2) || n1 < 1 || n2 < 1 || ch1 < 1 || ch2 < 1 || n1 > 10 || n2 > 10 || ch1 > 10 || ch2 > 10
      || std::max(std::abs(n1 - n2), std::abs(ch1 - ch2)) != size - 1) {
    std::cout << "wrong coordinates, try again\n";
    goto unsuccessful_attempt;
  }
  if (n1 > n2 || ch1 > ch2) {
    std::swap(n1, n2);
    std::swap(ch1, ch2);
  }
  for (int i = n1 - 1; i <= n2 + 1; ++i) {
    for (int j = ch1 - 1; j <= ch2 + 1; ++j) {
      if (field_[i][j] != 0) {
        std::cout << "wrong place, try again\n";
        goto unsuccessful_attempt;
      }
    }
  }
  for (int i = n1; i <= n2; ++i) {
    field_[i][ch1] = 2;
  }
  for (int i = ch1; i <= ch2; ++i) {
    field_[n1][i] = 2;
  }
}

void Field::PlaceAllShips() {
  PrintField(*this, true);
  std::cout << "place ship with length 4\n";
  PlaceShip(4);
  PrintField(*this, true);
  for (int i = 0; i < 2; ++i) {
    std::cout << "place ship with length 3\n";
    PlaceShip(3);
    PrintField(*this, true);
  }
  for (int i = 0; i < 3; ++i) {
    std::cout << "place ship with length 2\n";
    PlaceShip(2);
    PrintField(*this, true);
  }
  for (int i = 0; i < 4; ++i) {
    PrintField(*this,true);
    std::cout << "place ship with length 1\n";
    PlaceShip(1);
  }
  PrintField(*this, true);
}

void Field::MarkNearbyCells(int n, int ch) {
  bool vertical_ship = false;
  if (field_[n + 1][ch] == 3 || field_[n - 1][ch] == 3) {
    vertical_ship = true;
  }
  while (field_[n + 1][ch] == 3) {
    ++n;
  }
  while (field_[n][ch + 1] == 3) {
    ++ch;
  }
  while (field_[n][ch] == 3) {
    if (field_[n + 1][ch + 1] == 0) {
      field_[n + 1][ch + 1] = 1;
    }
    if (field_[n][ch + 1] == 0) {
      field_[n][ch + 1] = 1;
    }
    if (field_[n - 1][ch + 1] == 0) {
      field_[n - 1][ch + 1] = 1;
    }
    if (field_[n - 1][ch] == 0) {
      field_[n - 1][ch] = 1;
    }
    if (field_[n - 1][ch - 1] == 0) {
      field_[n - 1][ch - 1] = 1;
    }
    if (field_[n][ch - 1] == 0) {
      field_[n][ch - 1] = 1;
    }
    if (field_[n + 1][ch - 1] == 0) {
      field_[n + 1][ch - 1] = 1;
    }
    if (field_[n + 1][ch] == 0) {
      field_[n + 1][ch] = 1;
    }
    if (vertical_ship) {
      --n;
    } else {
      --ch;
    }
  }
}

bool Field::IsDestroyed(int n, int ch) {
  bool is_destroyed = true;
  int cnt = 1;
  while (field_[n + cnt][ch] >= 2) {
    if (field_[n + cnt][ch] == 2) {
      is_destroyed = false;
      break;
    }
    cnt++;
  }
  cnt = 1;
  while (field_[n - cnt][ch] >= 2) {
    if (field_[n - cnt][ch] == 2) {
      is_destroyed = false;
      break;
    }
    cnt++;
  }
  cnt = 1;
  while (field_[n][ch + cnt] >= 2) {
    if (field_[n][ch + cnt] == 2) {
      is_destroyed = false;
      break;
    }
    cnt++;
  }
  cnt = 1;
  while (field_[n][ch - cnt] >= 2) {
    if (field_[n][ch - cnt] == 2) {
      is_destroyed = false;
      break;
    }
    cnt++;
  }
  return is_destroyed;
}