#include "./Array.hpp"
#include <iostream>

using namespace std;

// Construtor
Array::Array(int max) {
  this->tam = 0;
  this->max = max;
  this->arr = new int[max];
}

// Construtor de Cópia
Array::Array(const Array &otherArray) {
  this->tam = otherArray.tam;
  this->max = this->tam + 10;
  this->arr = new int[this->tam + 10];

  for (int i = 0; i < this->tam; i++)
    this->arr[i] = otherArray.arr[i];
}

// Destrutor
Array::~Array() {
  this->tam = 0;
  this->max = 0;
  if (arr)
    delete[] arr;
}

int Array::getSize() const { return this->tam; }

void Array::show() const {

  cout << "[ ";
  for (int i = 0; i < this->tam; i++)
    cout << this->arr[i] << " ";

  cout << "]\n";
}

// Operador de atribuição "="
Array Array::operator=(const Array &b) {
  this->tam = b.tam;

  for (int i = 0; i < this->tam; i++)
    this->arr[i] = b.arr[i];

  return *this;
}

// Operador de igualdade "=="
bool Array::operator==(const Array &b) const {
  int lenThis = getSize();
  int lenB = b.getSize();

  if (lenThis != lenB)
    return false;
  
  for (int i = 0; i < lenThis; i++) {
    if (this->arr[i] != b.arr[i])
      return false;
  }

  return true;
}

// Operador de diferença '!='
bool Array::operator!=(const Array &b) const {
  if (! (*this == b))
    return true;
  
  return false;
}

// Operador de transferência de bits '<<'
ostream& operator<<(ostream &cout, const Array &arr) {
  arr.show();
  return cout;
}

// Operador de transferência de bits '>>'
istream& operator>>(istream &cin, Array &arr) {
  for (int i = 0; i < arr.max; i++) {
    cin >> arr.arr[i];
    arr.tam++;
  }
  
  return cin;
}

// Operador de indexação '[]'
int& Array::operator[](int index) {
  if (index >= this->max || index < 0) {
    cout << "Índice inválido. Programa fechado." << endl;
    exit(1);
  }

  return this->arr[index];
}

int Array::operator[](int index) const {
  if (index >= this->tam || index < 0) {
    cout << "Índice inválido. Programa fechado." << endl;
    exit(1);
  }

  return this->arr[index];
}

// Operador de soma '+'
Array Array::operator+(const Array &b) const {
  int maxUniao = this->max + b.max;
  int tamUniao = this->tam + b.tam;

  Array uniao = Array(maxUniao);
  uniao = *this;

  for (int i = 0; i < b.tam; i++)
    uniao[uniao.tam + i] = b.arr[i];
  
  uniao.tam = tamUniao;
  return uniao;
}

// Operador de soma e atribuição "+="
Array Array::operator+=(const Array &b) {
  (*this) = (*this) + b;
  return *this;
}

