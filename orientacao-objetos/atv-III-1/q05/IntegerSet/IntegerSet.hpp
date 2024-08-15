#ifndef INTEGER_SET_HPP
#define INTEGER_SET_HPP

#include <iostream>
using std::ostream;

class IntegerSet {

  friend IntegerSet unionOfSets(IntegerSet&, IntegerSet&);
  friend IntegerSet intersectionOfSets(IntegerSet&, IntegerSet&);
  friend ostream& operator<<(ostream&, IntegerSet&);

private:
  int set[100];
  int setedElements;

public:
  IntegerSet();
  IntegerSet(int[], int);

  void insertElement(int);
  void deleteElement(int);
  void print() const;

  int getTam() const;

  IntegerSet& operator<<(int);
  IntegerSet& operator>>(int);
  IntegerSet operator|(IntegerSet&);
  IntegerSet operator&(IntegerSet&);
};

#endif