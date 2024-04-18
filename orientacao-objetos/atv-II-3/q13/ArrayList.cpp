#include "ArrayList.hpp"
#include <iostream>

using namespace std;

void somaArray(ArrayList &lst, int n)
{
   int *array = lst.arr;
   for (int i = 0; i < lst.pos; i++)
      array[i] += n;
}

void subArray(ArrayList &lst, int n)
{
   int *array = lst.arr;
   for (int i = 0; i < lst.pos; i++)
      array[i] -= n;
}

void mulArray(ArrayList &lst, int n)
{
   int *array = lst.arr;
   for (int i = 0; i < lst.pos; i++)
      array[i] *= n;
}

void divArray(ArrayList &lst, int n)
{
   int *array = lst.arr;
   for (int i = 0; i < lst.pos; i++)
      array[i] /= n;
}

int ArrayList::getIndex(int element) const
{
   for (int i = 0; i < this->pos; i++)
      if (this->arr[i] == element)
         return i;

   return -1;
}
int ArrayList::busca(int index) const
{
   if (index < this->pos)
      return this->arr[index];

   cout << "ERRO! ÍNDICE INVÁLIDO!!!!!" << endl;
   exit(1);
}
void ArrayList::remove(int index)
{
   if (index >= this->pos || index < 0)
   {
      cout << "ERRO! ÍNDICE INVÁLIDO!!!!!" << endl;
      exit(1);
   }

   for (int i = index; i < this->pos - 1; i++)
      this->arr[i] = this->arr[i + 1];
   
   this->pos--;
}
void ArrayList::removeEl(int element)
{
   int indexElement = getIndex(element);
   while (indexElement != -1)
   {
      remove(indexElement);
      indexElement = getIndex(element);
   }
}

ArrayList::ArrayList(int tam) : pos(0)
{
   if (tam > 0)
   {
      this->tam = tam;
      this->arr = new int[tam];
   }
   else
   {
      this->arr = nullptr;
      this->tam = 0;
   }
}

ArrayList::~ArrayList()
{
   if (this->arr)
      delete [] this->arr;
}

ArrayList &ArrayList::add(int v)
{
   if (this->pos < this->tam)
      this->arr[this->pos++] = v;

   return *this;
}

void ArrayList::print() const
{
   cout << "[";
   for (int i = 0; i < this->pos - 1; i++)
      cout << this->arr[i] << " ";
   cout << this->arr[pos - 1] << "]" << endl;
}