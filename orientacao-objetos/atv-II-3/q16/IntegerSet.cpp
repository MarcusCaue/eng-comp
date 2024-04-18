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

IntegerSet::IntegerSet() {
  for (int i = 0; i < 100; i++)
    this->set[i] = 0;
  this->setedElements = 0;
}

IntegerSet::IntegerSet(int *elements, int tam) {
  this->setedElements = 0;

  int i;
  for (i = 0; i < tam; i++) {
    this->set[i] = elements[i];
    if (elements[i] == 1)
      this->setedElements++;
  }

  for (i = tam; i < 100; i++)
    this->set[i] = 0;
}

void IntegerSet::print() {
  int *elementos = this->set;
  cout << "[ ";
  for (int i = 0; i < 100; i++) {
    if (elementos[i] == 1)
      cout << i << " ";
  }
  cout << "]" << endl;
}

void IntegerSet::insertElement(int element) {
  if (element < 0 || element > 99) {
    cout << "O conjunto so aceita numeros no intervalo [0, 99]" << endl;
    return;
  }

  if (*(this->set + element) != 1) {
    this->setedElements++;
    *(this->set + element) = 1;
  }
}

void IntegerSet::deleteElement(int element) {
  if (element < 0 || element > 99) {
    cout << "So estao presentes no conjunto numeros no intervalo [0, 99]" << endl;
    return;
  }

  if (*(this->set + element) != 0) {
    this->setedElements--;
    *(this->set + element) = 0;
  }
}

int IntegerSet::getTam() const { return this->setedElements; }
