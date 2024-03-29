#ifndef TP__FIELD_H_
#define TP__FIELD_H_

class Field {
 public:

  int field_[12][12]{};

  bool IsDestroyed(int n, int ch);

  void MarkNearbyCells(int n, int ch);

  bool IsShotCorrect(int n, int ch);

  bool CorrectPlacement(int n1, int ch1, int n2, int ch2, int size);

  void ClearField();

};
#endif
