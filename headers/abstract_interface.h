#ifndef TP__ABSTRACT_INTERFACE_H_
#define TP__ABSTRACT_INTERFACE_H_
#include "field.h"

class AbstractInterface {
 public:
  virtual void GetCell(int &ch, int &n) = 0;
  virtual void Message(const char *msg) = 0;
  virtual void ClearScreen() = 0;
  virtual void PrintField(Field &f, bool show_ships) = 0;
  virtual bool AskYesNo() = 0;
};
#endif
