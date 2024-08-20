#ifndef RETANGULO_HPP

#define RETANGULO_HPP

class Retangulo {

private:
  double largura;
  double altura;

public:
  Retangulo(double = 1.0, double = 1.0);

  double perimetro();
  double area();
  void desenho();

  double getLarg();
  void setLarg(double);
  double getAlt();
  void setAlt(double);

};

#endif