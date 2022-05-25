# include<iostream>

using namespace std;
const int N = 10;
int n,k;
int m[N][N];
int ans;
void dfs(int left, int thisman){
    if(left == 0){
        if(thisman == n-1) ans ++;
        return;
    }
    for(int i = 0 ; i < n ; i ++){
        if(m[thisman][i] && thisman!= i)
            dfs(left-1 , i);
    }
}

int main(){
    int a,b;
    cin >> n >> k;
    while(cin >> a >> b){
        m[a][b] = 1;
    }
    dfs(k-1,0);
    cout << ans;
    return 0;
}