#ifndef TP__INTERFACE_H_
#define TP__INTERFACE_H_
#include "abstract_interface.h"

class ConsoleInterface : public AbstractInterface {
 public:
  void GetCell(int &ch, int &n) override;
  void Message(const char *msg) override;
  void ClearScreen() override;
  void PrintField(Field &f, bool show_ships) override;
};

#endif
