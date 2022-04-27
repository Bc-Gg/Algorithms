# include<iostream>
# include<vector>
# include<utility>
# include<algorithm>
using namespace std;
const int N = 20;
typedef pair<int ,int > PII;
vector<PII> path;
int n;
int maze[N][N];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
int flag = 0;
void dfs(int i, int j){
    maze[i][j]=1;
    if(flag == 1) return;
    if (i == n - 2 && j == n-2){
        flag = 1;
        return;
    }
    for(int k = 0 ; k < 4 ; k++){
        if(flag == 1) return;
        int x = i+dx[k], y = j + dy[k];
        if(!maze[x][y])
        {   
            path.push_back({x,y});
            dfs(x, y);
            if(flag == 1) return;
            maze[x][y] = 0;
            path.pop_back();
        }
    }
}


int main(){
    cin >>n;
    for(int i = 0; i < n; i++)  
        for(int j = 0 ; j < n ;j++)
            scanf("%d",&maze[i][j]);
    path.push_back({1,1});
    dfs(1,1);
    if(flag == 0) cout<< "NO" ;  
    else{
        for(PII p :path){
            printf("(%d,%d)",p.first,p.second);
    }}
    return 0;
}