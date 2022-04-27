#include <iostream>
#include <cstring>
using namespace std;
const int N = 21, M = 35;
int vis[N];
int g[N];
int list[] = {2,3,5,7,11,13,17,19,23,29,31};
int is_prime(int a){
    for(int i = 0 ; i < 11 ; i++)
        if (a == list[i]) return 1;
    return 0;
}

void dfs(int pos, int n){
    if(pos == n + 1){
        if(is_prime(1 + g[n])){
            for(int i = 1; i <= n; i++){
                printf("%d", g[i]);
                if(i == n) puts("");
                else printf(" ");
            }
            return;
        }
    }
    for(int i = 2; i <= n; i++){
        if(!vis[i] && is_prime(g[pos-1] + i)){
            vis[i] = 1;
            g[pos] = i;
            dfs(pos+1, n);
            vis[i] = 0;
        }
    }
}

int main()
{
    g[1] = 1;
    int n, cnt = 0;
    while(scanf("%d", &n) != EOF && n){
        cnt++;
        printf("Case %d:\n", cnt);
        memset(vis, 0, sizeof vis);
        if(n > 1) dfs(2, n);
      	else printf("1\n");
        puts("");
    }
    return 0;
}