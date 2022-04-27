# include<iostream>
# include<algorithm>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
const int N =105;
int vis[N][N], g[N][N];
int col, row;

void dfs(int i , int j){
    if(i <= col  && j <= row && i >0 && j>0)
        vis[i][j] = 1;
        for(int k = 0 ;k < 4 ;k++){
        if(!vis[i+dx[k]][j+dy[k]] && g[i+dx[k]][j+dy[k]])
            dfs(i+dx[k], j+dy[k]);
    }
}


int main(){
    int ans = 0;
    cin >> col >> row;
    for(int i = 1 ; i <= col; i ++)
        for(int j = 1 ; j <= row; j++)
            scanf("%1d", &g[i][j]);
    for(int i = 1 ; i <= col ;i++)
        for(int j = 1 ; j <= row; j++){
            if(!vis[i][j] && g[i][j]){
                if(g[i+1][j] == 0 && g[i][j+1] == 0 && g[i-1][j] == 0&&g[i][j-1]) continue;
                dfs(i,j);
                ans++;
            }
        }
    cout << ans;
    return 0;
}
