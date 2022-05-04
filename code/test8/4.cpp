#include <iostream>
#include <cstring>
using namespace std;
const int N = 21, M = 35;
bool st[M];
int g[N], is_prime[M] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0};
int prime[N] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int n;

void dfs(int pos){
    if(pos == n + 1){
        if(is_prime[g[n] + 1]){
            for(int i = 1; i <= n; i++){
                printf("%d", g[i]);
                if(i == n) puts("");
                else printf(" ");
            }
            return;
        }
    }
    for(int i = 0; i <= 10; i++){
        int j = prime[i] - g[pos-1];
        if(j > n) break;
        if(j > 1 && !st[j]){
            st[j] = true;
            g[pos] = j;
            dfs(pos+1);
            st[j] = false;
        }
    }
}

int main()
{
    g[1] = 1;
    int cnt = 0;
    while(scanf("%d", &n) != EOF && n){
        cnt++;
        printf("Case %d:\n", cnt);
        memset(st, false, sizeof st);
        if(n == 1) printf("1\n");
        else if(!(n & 1)) dfs(2);
        puts("");
    }
    return 0;
}