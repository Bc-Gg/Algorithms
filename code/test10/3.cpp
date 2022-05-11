# include<iostream>
# include<vector>
# include<cstring>
# include<algorithm>
using namespace std;

const int N = 205;
int m[N][N];
int mem[N][N];
int n,k;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int ans = 1;

int dfs(int x, int y){
    if(mem[x][y]>0) return mem[x][y];
    auto temp = 1;
    for(int i = 0 ; i < 4 ;i++){
        auto xx = x + dx[i], yy = y + dy[i];
        // printf("%d , %d \tindex :(%d %d) ,(%d %d)\n",m[xx][yy], m[x][y],xx,yy,x,y);
        if(xx > 0 && xx <= n && yy > 0 && yy <= k && m[xx][yy] > m[x][y]){
            temp = max(temp,dfs(xx,yy)+1);
        }
    }
    mem[x][y] = temp;
        return temp;
}

int main(){
    scanf("%d%d",&n, &k);;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= k; j++){
            scanf("%d" ,&m[i][j]);
        }
    }
    for(int i = 1 ; i <= n ;i++){
        for(int j = 1 ; j <= k ;j++){
            ans = max(ans,dfs(i, j));
            // printf("\n");
            // for(int a = 1 ; a <= n ; a ++)
            //     for(int b = 1 ; b <= k ; b++)
            //         printf("%d%c",mem[a][b], b == k ? '\n' : ' ');
        }
    }
    printf("%d",ans);
    return 0;
}