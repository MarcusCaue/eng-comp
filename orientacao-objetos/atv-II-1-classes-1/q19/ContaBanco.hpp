#ifndef CONTA_BANCO_HPP

#define CONTA_BANCO_HPP

class ContaBanco {
  private:
    double saldo;

  public:
    ContaBanco(double);

    void creditar(double);
    void debitar(double);

    double getSaldo();
};

#endif