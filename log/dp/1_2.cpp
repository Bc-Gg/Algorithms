/*
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000
*/
# include<iostream>
using namespace std;
const int N = 1001;
int f[N];
int main(){
    int v[N], w[N];
    int m,n;
    cin >> m >> n;
    for(int i = 1 ; i <= n;i++ ) cin >> v[i];
    for(int i = 1 ; i <= n ;i++)
        for(int j = m ; j >= v[i] ;j--)// 倒序让降维变得可行
            f[j] = max(f[j],f[j- v[i]] + v[i]);
    cout << f[m];
    return 0;
}