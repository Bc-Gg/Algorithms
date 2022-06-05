//电路板排列问题 回溯法求解
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("5d11.txt");

class Board
{
   friend int Arrangement(int **B, int n, int m, int bestx[]);

private:
   void Backtrack(int i, int cd);
   int n,      //电路板数
       m,      //连接板数
       *x,     //当前解
       *bestx, //当前最优解
       bestd,  //当前最优密度
       *total, //total[j]=连接块j的电路板数
       *now,   //now[j]=当前解中所含连接块j的电路板数
       **B;    //连接块数组
};

template <class Type>
inline void Swap(Type &a, Type &b);

int Arrangement(int **B, int n, int m, int bestx[]);

int main()
{
   int m = 5, n = 8;
   int bestx[9];

   //B={1,2,3,4,5,6,7,8}
   //N1={4,5,6},N2={2,3},N3={1,3},N4={3,6},N5={7,8}

   cout << "m=" << m << ",n=" << n << endl;
   cout << "N1={4,5,6},N2={2,3},N3={1,3},N4={3,6},N5={7,8}" << endl;
   cout << "二维数组B如下：" << endl;

   //构造B
   int **B = new int *[n + 1];
   for (int i = 1; i <= n; i++)
   {
      B[i] = new int[m + 1];
   }

   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         fin >> B[i][j];
         cout << B[i][j] << " ";
      }
      cout << endl;
   }

   cout << "当前最优密度为:" << Arrangement(B, n, m, bestx) << endl;
   cout << "最优排列为：" << endl;
   for (int i = 1; i <= n; i++)
   {
      cout << bestx[i] << " ";
   }
   cout << endl;

   for (int i = 1; i <= n; i++)
   {
      delete[] B[i];
   }
   delete[] B;

   return 0;
}

void Board::Backtrack(int i, int cd) //回溯法搜索排列树
{
   if (i == n)
   {
      for (int j = 1; j <= n; j++)
      {
         bestx[j] = x[j];
      }
      bestd = cd;
   }
   else
   {
      for (int j = i; j <= n; j++)
      {
         //选择x[j]为下一块电路板
         int ld = 0;
         for (int k = 1; k <= m; k++)
         {
            now[k] += B[x[j]][k];
            if (now[k] > 0 && total[k] != now[k])
            {
               ld++;
            }
         }
         
         //更新ld
         if (cd > ld)
         {
            ld = cd;
         }

         if (ld < bestd) //搜索子树
         {
            Swap(x[i], x[j]);
            Backtrack(i + 1, ld);
            Swap(x[i], x[j]);

            //恢复状态
            for (int k = 1; k <= m; k++)
            {
               now[k] -= B[x[j]][k];
            }
         }
      }
   }
}

int Arrangement(int **B, int n, int m, int bestx[])
{
   Board X;

   //初始化X
   X.x = new int[n + 1];
   X.total = new int[m + 1];
   X.now = new int[m + 1];
   X.B = B;
   X.n = n;
   X.m = m;
   X.bestx = bestx;
   X.bestd = m + 1;

   //初始化total和now
   for (int i = 1; i <= m; i++)
   {
      X.total[i] = 0;
      X.now[i] = 0;
   }

   //初始化x为单位排列并计算total
   for (int i = 1; i <= n; i++)
   {
      X.x[i] = i;
      for (int j = 1; j <= m; j++)
      {
         X.total[j] += B[i][j];
      }
   }

   //回溯搜索
   X.Backtrack(1, 0);
   delete[] X.x;
   delete[] X.total;
   delete[] X.now;
   return X.bestd;
}

template <class Type>
inline void Swap(Type &a, Type &b)
{
   Type temp = a;
   a = b;
   b = temp;
}