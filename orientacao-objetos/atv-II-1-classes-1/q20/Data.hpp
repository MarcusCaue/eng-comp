#ifndef DATA_HPP

#define DATA_HPP

class Data {

private:
  int dia;
  int mes;
  int ano;

public:
  Data(int, int, int);

  void mostrarData();
  
  int getDia();
  void setDia(int);

  int getMes();
  void setMes(int);

  int getAno();
  void setAno(int);

};

#endif