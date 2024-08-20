#ifndef INTEGER_SET_HPP
#define INTEGER_SET_HPP

class IntegerSet {

  friend IntegerSet unionOfSets(IntegerSet&, IntegerSet&);
  friend IntegerSet intersectionOfSets(IntegerSet&, IntegerSet&);

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
};

#endif