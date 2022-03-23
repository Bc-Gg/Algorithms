/*
多重背包问题
*/
#include<iostream>
#include<algorithm>
using namespace std;
int f[1010];
int main(){
    int v,w,s;
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> v >> w >> s;
        for(int j = m ; j >= 0 ;j-- )
            for(int k = 0 ; k <= s && k*v <= j; k++)
                f[j] = max(f[j],f[j - k*v ] + k*w);
    }
    cout << f[m];
    return 0;
}