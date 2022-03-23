//完全背包问题
# include<iostream>
# include<algorithm>

using namespace std;
int f[1010];
int v[1010],w[1010];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> v[i] >> w[i];
    for(int i = 1 ; i <= n; i ++){// 枚举物品
        for(int j = v[i] ;j <= m ;j++ ) // 枚举背包容量
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
    cout << f[m];
    return 0;
}