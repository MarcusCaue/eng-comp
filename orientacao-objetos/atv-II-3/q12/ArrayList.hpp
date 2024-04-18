#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

class ArrayList
{

   friend void somaArray(ArrayList &, int);
   friend void subArray(ArrayList &, int);
   friend void mulArray(ArrayList &, int);
   friend void divArray(ArrayList &, int);

public:
   ArrayList(int);
   ~ArrayList();

   ArrayList &add(int);
   void print() const;

private:
   int *arr;
   int tam;
   int pos;
};

#endif