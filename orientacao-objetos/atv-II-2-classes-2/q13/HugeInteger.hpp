#ifndef HUGE_INTEGER_HPP

#define HUGE_INTEGER_HPP

#include <string>
using std::string;

class HugeInteger {

private:
  char digits[40];
  int quantDigits;

  void reorganizaNum();

public:
  HugeInteger();

  void input(string);
  void output();
  void add(HugeInteger);
  
  bool isEqualTo(HugeInteger);
  bool isNotEqualTo(HugeInteger);
  bool isGreaterThan(HugeInteger);
  bool isLessThan(HugeInteger);
  bool isGreaterThanOrIqual(HugeInteger);
  bool isLessThanOrIqual(HugeInteger);

  string getDigits();
  string copyDigits();

  int getQuantDigits();
};

#endif