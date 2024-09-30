#ifndef FORMABI_H
#define FORMABI_H 

class FormaBidimensional {
  protected:
    int numLados;
  
  public:
    FormaBidimensional(int numLados) : numLados(numLados) { }
    virtual void desenhar() const = 0;
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
};

#endif