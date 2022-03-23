#include<iostream>
# include<cstring>
using namespace std;
typedef long long ll;
const int N = 1e6+6;
ll n,m;
ll f[20][1 << 12];
bool st[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < 1<<n; i ++)//init
    {
        int cnt = 0;
        st[i] = true;
        for(int j = 0; j < n; j ++)
        {
            if(i >> j & 1) 
            {
                if(cnt & 1) st[i] = false;
                cnt = 0;
            }
            else    cnt ++;
        }
        if(cnt & 1) st[i] = false;
    }
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for(int i = 1; i <= m; i ++)
        for(int j = 0; j < 1 <<n; j ++)
            for(int k = 0; k < 1 << n; k ++)
                if((j&k)==0 && st[j|k])
                    f[i][j] += f[i-1][k];

    cout << f[m][0] << endl;
    return 0;
}