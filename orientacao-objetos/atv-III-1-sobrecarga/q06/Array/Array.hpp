#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
using namespace std;

class Array {

  friend ostream& operator<<(ostream &cout, const Array &arr);
  friend istream& operator>>(istream &cin, Array &arr);

private:
  int tam;
  int max;
  int *arr;

public:

  Array(int = 10);      
  Array(const Array &);
  ~Array();

  int getSize() const;
  void show() const;

  Array operator=(const Array &b);
  bool operator==(const Array &b) const;
  bool operator!=(const Array &b) const;
  int &operator[](int);
  int operator[](int) const;
  Array operator+(const Array &b) const;
  Array operator+=(const Array &b);

};

#endif