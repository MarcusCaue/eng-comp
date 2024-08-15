#ifndef HUGE_INTEGER_HPP
#define HUGE_INTEGER_HPP

#include <string>
#include <iostream>

using std::string, std::cout, std::ostream;

class HugeInteger {

  friend ostream& operator<<(ostream& cout, const HugeInteger& hi);

private:
  char digits[40];
  int quantDigits;

  void reorganizaNum();

public:
  HugeInteger();

  void input(string number);
  void output() const;
  void add(const HugeInteger& otherHugeInteger);
  
  bool isEqualTo(const HugeInteger& otherHugeInteger) const;
  bool isNotEqualTo(const HugeInteger& otherHugeInteger) const;
  bool isGreaterThan(const HugeInteger& otherHugeInteger) const;
  bool isLessThan(const HugeInteger& otherHugeInteger) const;
  bool isGreaterThanOrEqual(const HugeInteger& otherHugeInteger) const;
  bool isLessThanOrEqual(const HugeInteger& otherHugeInteger) const;

  string getDigits() const;
  string copyDigits() const;
  int getQuantDigits() const;

  void operator=(string num);
  HugeInteger operator+(const HugeInteger& otherHugeInteger);
  HugeInteger operator+=(const HugeInteger& otherHugeInteger);
  bool operator==(const HugeInteger& otherHugeInteger);
  bool operator!=(const HugeInteger& otherHugeInteger);
  bool operator>(const HugeInteger& otherHugeInteger);
  bool operator<(const HugeInteger& otherHugeInteger);
  bool operator>=(const HugeInteger& otherHugeInteger);
  bool operator<=(const HugeInteger& otherHugeInteger);
};

#endif