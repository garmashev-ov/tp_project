#include <iostream>
#include "../headers/field.h"

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

bool Field::IsShotCorrect(int n, int ch) {
  if (ch > 10 || n > 10 || ch <= 0 || n <= 0) {
    return false;
  }
  if (field_[n][ch] == 3 || field_[n][ch] == 1) {
    return false;
  }
  return true;
}

bool Field::CorrectPlacement(int n1, int ch1, int n2, int ch2, int size) {
  if ((n1 != n2 && ch1 != ch2) || n1 < 1 || n2 < 1 || ch1 < 1 || ch2 < 1 || n1 > 10 || n2 > 10 || ch1 > 10 || ch2 > 10
      || std::max(std::abs(n1 - n2), std::abs(ch1 - ch2)) != size - 1) {
    return false;
  }
  if (n1 > n2 || ch1 > ch2) {
    std::swap(n1, n2);
    std::swap(ch1, ch2);
  }
  for (int i = n1 - 1; i <= n2 + 1; ++i) {
    for (int j = ch1 - 1; j <= ch2 + 1; ++j) {
      if (field_[i][j] != 0) {
        return false;
      }
    }
  }
  return true;
}

void Field::ClearField() {
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      field_[i][j] = 0;
    }
  }
}