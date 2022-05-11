#include <iostream>
#include <algorithm>
using namespace std;
const int N=20;
long long res=1e7, a[N], p[N];
int n,m;

int cmp(int a ,int b){
    return a > b;
}

void dfs(long long x, long long cnt)
{
    if (cnt >= res) return;
    if (x > n)
    {
        res = min(res, cnt);
        return;
    }
    for(int i = 1; i <= cnt; i++) 
        if (p[i] + a[x] <= m)     
        {
            p[i] += a[x];
            dfs(x+1, cnt);
            p[i] -= a[x];
        }
    p[cnt+1] = a[x];    
    dfs(x+1, cnt+1);
    p[cnt+1] = 0;  
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n, cmp);
    dfs(1,0);
    cout << res;
    return 0;
}