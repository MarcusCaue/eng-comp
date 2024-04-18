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