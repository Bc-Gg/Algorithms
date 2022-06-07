#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void exchange(int &a, int &b)
{
   int temp = a;
   a = b;
   b = temp;
}

int PARTITION(int *arry, int p, int r)
{
   int x = arry[r];
   int i = p - 1;
   for (int j = p; j < r; j++)
   {
      if (arry[j] < x)
      {
         i++;
         exchange(arry[i], arry[j]);
      }
   }
   exchange(arry[i + 1], arry[r]);
   return i + 1;
}

int RANDOM_PARTITION(int *arry, int p, int r)
{
   time_t t;
   srand((unsigned)time(&t));
   int i = rand() % (r - p) + p;
   exchange(arry[i], arry[r]);
   return PARTITION(arry, p, r);
}

int RANDOMIZED_SELECT(int *arry, int p, int r, int i)
{
   if (p == r)
      return arry[p];
   int q = RANDOM_PARTITION(arry, p, r);
   int k = q - p + 1;

   if (i == k)
      return arry[q];
   else if (i < k)
      return RANDOMIZED_SELECT(arry, p, q - 1, i);
   else
      return RANDOMIZED_SELECT(arry, q + 1, r, i - k);
}

int main()
{
   int arry[12] = {0, 10, 31, 4, 5, 9, 6, 1, 2, 3, 8, -9};
   cout << RANDOMIZED_SELECT(arry, 0, 11, 4) << endl;
   return 0;
}