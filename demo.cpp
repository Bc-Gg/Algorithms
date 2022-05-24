/*1.计算至少有一对生日相同的概率即概率算法计算 1-（365！/（340！* 365^25 ）） 
  2.1~3对生日相同的概率  
  3.输出300次实验结果的平均值和方差 
*/

#include <iostream>
using namespace std;
#include <math.h>
#include<ctime>
#include<stdlib.h>
#include <iomanip>  //有效数字
double caculate(int);
int model(int);
int model_1(int);
int main()
{
    int n;
    
    cout<< "请输入总人数：" << endl;
    cin>> n;
    cout<< "所有人生日都不相同的概率：" <<endl;
    cout<< "计算的精确值：" <<caculate(n) << endl;
    model(n);
    model_1(n);
    return 0;
}

//计算精确值 
double caculate(int num)
{
    int day=365;
    double result = 1, i;//计算的重复概率
    for (i = 1; i <num; i++)
    {
       result*= (day - i) / day;//两个人不在同一天就是（365/365）*（364/365）
    }
     return result;
}

// 所有人生日都不相同的概率 ，至少一对人生日相同的概率 
int model(int num)
{
    int day=365;
    double sn;
    double result;//仿真的重复概率
    int cont = 0, i, j = 0;//模拟中不重复的次数
    srand((unsigned)time(NULL)); /*播种子,这里用到了time需要包含头文件time.h*/
    for (j = 0; j <300000; j++)
    {
       int* p = new int[day+1];
       for (i = 0; i < day;i++)
          p[i]= 0;//清零数组
        for (i = 1; i <num; i++)
       {
          int n;
          
          n= rand() % day + 1;
          if (!p[n])  //等价与if（p[n]==0） 
               p[n]= 1;
          else
               break;//使用break完全结束一个循环，跳出循环体执行循环后面的语句 
        }
          if (i == num) cont++;
         delete[]p;
 }
   result= cont * 1.0 / 300000;//数字越大越精确；这个即为平均值
   cout<< "模拟的所有人生日都不相同的概率：" <<fixed<<setprecision(8)<<result<<endl;
   cout<<"至少一对人生日相同的概率为：" <<fixed<<setprecision(8)<<1-result<<" ";
   sn=(cont*pow(result,2)+(num-cont)*pow(1-result,2))/300000;
   cout<<"方差为："<<fixed<<setprecision(8)<<sn<<endl; 
   
   return 0;
}

//g对人生日相同的概率
int model_1(int num)//g用来记录有几对生日相同 
{
    int day=365;
    int g[3]={1,2,3};
    double result[3],sn[3];//仿真的重复概率
    int cont = 0, group[3]={0,0,0};
	int i, j = 0;//模拟不重复的次数
    srand((unsigned)time(NULL)); /*播种子,这里用到了time需要包含头文件time.h*/
    for (j = 0; j <300000; j++)
    {
       int* p = new int[day+1];
       for (i = 0; i < day;i++)
          p[i]= 0;//清零数组
        for (i = 1; i <=num; i++)
       {
          int n;
          
          n= rand() % day + 1;
          if (!p[n])  //等价于if（p[n]==0） 
               p[n]= 1;
          else
          {
		  cont++;p[n]= 0;
		  }
               //break;//使用break完全结束一个循环，跳出循环体执行循环后面的语句 
        }
        for(int i=0;i<3;i++){
        	if (cont == g[i]) group[i]++;
		}
          
         delete[]p;
 }
    for(int i=1;i<=3;i++){
        result[i]= group[i] * 1.0 / 300000;//数字越大越精确
        sn[i]=(group[i]*pow((1-result[i]),2)+(num-group[i])*pow(result[i],2))/300;
        cout<<"恰好"<<i<<"对生日相同的概率和方差：";
        cout<<fixed<<setprecision(8)<<result[i]<<" "<<sn[i]<<endl;
		}
  
   return 0;
} 
