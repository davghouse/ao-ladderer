#ifndef IMPLANT_H_
#define IMPLANT_H_

#include <string>
#include <fstream>
#include "Helper.h"


class Implant{
  // added for GUI
  friend class MainWindow;
public:
  Implant();

  Implant(int ql, std::string slot, std::string a, std::string s, std::string b, std::string f, bool locked = false, bool removed = true);

  bool ladder() const{ return Ladder; }
  int ql() const { return Ql; }
  const std::string& slot() const { return Slot; }
  int slotI() const { return SlotI; }
  const std::string& abi() const { return a; }
  int abiI() const { return aI; }
  const std::string& shi() const { return s; }
  int shiI() const { return sI; }
  const std::string& bri() const { return b; }
  int briI() const { return bI; }
  const std::string& fad() const { return f; }
  int fadI() const { return fI; }

  bool isLocked() const { return lock; }
  bool mustRemove() const { return remove; }

  void setQL(int QL){ Ql = QL; }
  void setRemove(bool removeBool){ remove = removeBool; }

private:
  bool Ladder;
  int Ql;
  
  std::string Slot;
  std::string a;
  std::string s, b, f;

  // added for GUI
  std::string sName, bName, fName;
  
  // following integers are for indexing purposes, allowing quick access in containers like 
  // Stats and Config, where abilities and implants respectively are in a fixed order (by design).
  // they are named to correspond with the string variables above.
  // abi order: strength, agility, stamina, intelligence, sense, psychic
  //            0         1        2        3             4      5
  // slot order: head, eye, ear, chest, rarm, larm, waist, rwrist, lwrist, leg, rhand, lhand, feet
  //             0     1    2    3      4     5     6      7       8       9    10     11     12
  int SlotI;
  int aI;
  int sI, bI, fI;

  // used to prevent laddering implants from being moved
  bool lock;

  // used to allow ladder implants to avoid removal if no final implant occupies their slot
  bool remove;
};

#endif // IMPLANT_H_
