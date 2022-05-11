#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010;
int n, m;
int f[N];
int w[N];
int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &w[i]);
    for(int i = 1 ; i <= n;i++){
        for (int j = m; j >= w[i]; j -- )
            f[j] = max(f[j], f[j - w[i]] + w[i]);
    }
    printf("%d\n", m - f[m]);
    return 0;
}
