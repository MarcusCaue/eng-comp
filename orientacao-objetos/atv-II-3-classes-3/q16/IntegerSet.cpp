#include "IntegerSet.hpp"
#include <iostream>

using std::cout, std::endl;

IntegerSet unionOfSets(IntegerSet &s1, IntegerSet &s2) {
  IntegerSet uniao = s1;
  uniao.setedElements = s1.setedElements;

  for (int i = 0; i < 100; i++) {
    if (s1.set[i] == 0 && s2.set[i] == 1) {
      uniao.set[i] = 1;
      uniao.setedElements++;
    }
  }

  return uniao;
}

IntegerSet intersectionOfSets(IntegerSet &s1, IntegerSet &s2) {
  IntegerSet intersection = IntegerSet();

  for (int i = 0; i < 100; i++) {
    if (s1.set[i] == 1 && s2.set[i] == 1) {
      intersection.set[i] = 1;
      intersection.setedElements++;
    }
  }

  return intersection;
}

IntegerSet::IntegerSet() : setedElements(0) {
  for (int i = 0; i < 100; i++)
    this->set[i] = 0;
}

IntegerSet::IntegerSet(int elements[], int tam) : setedElements(0) {
  int i;
  for (i = 0; i < tam; i++) {
    this->set[i] = elements[i];
    if (elements[i] == 1)
      this->setedElements++;
  }

  // Completando com zeros
  for (i = tam; i < 100; i++)
    this->set[i] = 0;
}

void IntegerSet::print() const {
  const int* elementos = this->set;

  cout << "[ ";

  for (int i = 0; i < 100; i++) {
    if (elementos[i] != 0)
      cout << i << " ";
  }

  cout << "]" << endl;
}

void IntegerSet::insertElement(int element) {
  if (element < 0 || element > 99) {
    cout << "O conjunto só aceita números no intervalo [0, 99]" << endl;
    return;
  }

  if (*(this->set + element) != 1) {
    *(this->set + element) = 1;
    this->setedElements++;
  }
}

void IntegerSet::deleteElement(int element) {
  if (element < 0 || element > 99) {
    cout << "Só estão presentes no conjunto números no intervalo [0, 99]" << endl;
    return;
  }

  if (*(this->set + element) != 0) {
    *(this->set + element) = 0;
    this->setedElements--;
  }
}

int IntegerSet::getTam() const { return this->setedElements; }
