#include <iostream>
#include <cstdlib>
#include <string>
#include "HugeInteger.hpp"

using std::cout, std::string;

ostream& operator<<(ostream& cout, const HugeInteger& hi) { hi.output(); return cout; }

void HugeInteger::operator=(string num) { this->input(num); }

HugeInteger HugeInteger::operator+(const HugeInteger& oHi) {
  HugeInteger resultado = *this;
  resultado.add(oHi);
  return resultado;
}

HugeInteger HugeInteger::operator+=(const HugeInteger& oHi) {
  this->add(oHi);
  return *this;
}

bool HugeInteger::operator>(const HugeInteger& oHi) { return this->isGreaterThan(oHi); }
bool HugeInteger::operator<(const HugeInteger& oHi) { return this->isLessThan(oHi); }
bool HugeInteger::operator>=(const HugeInteger& oHi) { return this->isGreaterThanOrEqual(oHi); }
bool HugeInteger::operator<=(const HugeInteger& oHi) { return this->isLessThanOrEqual(oHi); }
bool HugeInteger::operator==(const HugeInteger& oHi) { return this->isEqualTo(oHi);  }
bool HugeInteger::operator!=(const HugeInteger& oHi) { return this->isNotEqualTo(oHi); }

bool validaString(string str) {
  for (int i = 0; str[i] != '\0'; i++) {
    int d = static_cast<int>(str[i]);

    if (d < 48 || d > 57)
      return false;
  }

  return true;
}

HugeInteger::HugeInteger() {
  for (int i = 0; i < 40; i++)
    this->digits[i] = '\0';
  
  this->quantDigits = 0;
  
}

void HugeInteger::input(string num) {
  if (validaString(num)) {
    int i;
    
    for (i = 0; num[i] != '\0'; i++)
      this->digits[i] = num[i];

    this->quantDigits = i;
  } 
  else {
    this->digits[0] = '0';

    for (int i = 1; i < 40; i++)
      this->digits[i] = '\0';

    this->quantDigits = 1;
  }
}
void HugeInteger::output() const {  
  for (int i = 0; i < this->quantDigits; i++)
    cout << this->digits[i];
  cout << '\0';
}

void HugeInteger::add(const HugeInteger& otherHi) {
  // Tamanhos dos números
  int lenN1 = this->quantDigits;
  int lenN2 = otherHi.getQuantDigits();
  
  string n1 = copyDigits();
  string n2 = otherHi.copyDigits();

  int lenMaior = lenN1;
  
  // Adiciona zeros à esquerda no n2
  if (lenN1 > lenN2) {
    int quantZeros = (lenN1 - lenN2);
    for (int i = 0; i < quantZeros; i++)
      n2 = '0' + n2;
  }
  // Adiciona zeros à esquerda do n1
  else if (lenN2 > lenN1) {
    lenMaior = lenN2;
    int quantZeros = (lenN2 - lenN1);
    for (int i = 0; i < quantZeros; i++)
      n1 = '0' + n1;
    this->quantDigits += quantZeros;
  }
  
  // Indo do dígito menos significativo até o mais significativo
  int excedente = 0;

  for (int i = lenMaior - 1; i > -1; i--) {
    int d1 = n1[i] - '0';
    int d2 = n2[i] - '0';
    int result = d1 + d2 + excedente;

    if (result < 10) {
      // Adiciona apenas um dígito
      n1[i] = result + '0';
      excedente = 0;
    }
    else {
      // Adiciona dois dígitos
      n1[i] = (result % 10) + '0';
      excedente = 1;
    }
  }

  for (int i = 0; i < lenMaior; i++)
    this->digits[i] = n1[i];
  
  if (excedente == 1)
    reorganizaNum();
}

void HugeInteger::reorganizaNum() {
  
  if (this->quantDigits < 40) {
    for (int i = this->quantDigits; i > -1; i--)
      this->digits[i] = this->digits[i - 1];
    
    this->quantDigits++;
    this->digits[0] = '1';
  }
  
}

bool HugeInteger::isEqualTo(const HugeInteger& otherHi) const {
  int lenN1 = this->quantDigits;
  int lenN2 = otherHi.getQuantDigits();

  if (lenN1 != lenN2)
    return false;
  else {
    string n1 = copyDigits();
    string n2 = otherHi.copyDigits();
    
    for (int i = 0; i < lenN1; i++)
      if (n1[i] != n2[i])
        return false;
  }

  return true;
}
bool HugeInteger::isNotEqualTo(const HugeInteger& otherHi) const {
  if (isEqualTo(otherHi))
    return false;
  
  return true;
}

bool HugeInteger::isGreaterThan(const HugeInteger& otherHi) const {
  int lenN1 = this->quantDigits;
  int lenN2 = otherHi.getQuantDigits();

  if (lenN1 > lenN2)
    return true;
  else if (lenN2 > lenN1)
    return false;

  string n1 = copyDigits();
  string n2 = otherHi.copyDigits();
  
  for (int i = 0; i < lenN1; i++) {
    int d1 = n1[i] - '0';
    int d2 = n2[i] - '0';

    if (d1 > d2)
      return true;
    else if (d2 > d1)
      return false;
  }

  return false;
}
bool HugeInteger::isLessThan(const HugeInteger& otherHi) const {
  int lenN1 = this->quantDigits;
  int lenN2 = otherHi.getQuantDigits();

  if (lenN1 < lenN2)
    return true;
  else if (lenN2 < lenN1)
    return false;

  string n1 = copyDigits();
  string n2 = otherHi.copyDigits();

  for (int i = 0; i < lenN1; i++) {
    int d1 = n1[i] - '0';
    int d2 = n2[i] - '0';

    if (d2 > d1)
      return true;
    else if (d1 > d2)
      return false;
  }

  return false;
}

bool HugeInteger::isGreaterThanOrEqual(const HugeInteger& otherHi) const {
  if (isEqualTo(otherHi) || isGreaterThan(otherHi))
    return true;

  return false;
}
bool HugeInteger::isLessThanOrEqual(const HugeInteger& otherHi) const {
  if (isEqualTo(otherHi) || isLessThan(otherHi))
    return true;

  return false;
}

string HugeInteger::getDigits() const {
  return this->digits;
}
string HugeInteger::copyDigits() const {
  int len = this->quantDigits;
  string copy = "";
  
  for (int i = 0; i < len; i++)
    copy += this->digits[i];

  return copy;
}
int HugeInteger::getQuantDigits() const {
  return this->quantDigits;
}