# include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 1010;
int n,m;
struct obj{
    int st;
    int v,w;
};
vector<obj> vec;
int f[N];
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int v,w,s;
        cin >> v >> w >> s;
        if(s > 0){
            for(int j = 1 ; j <= s ;j*=2){
                s -= j;
                vec.push_back({-1,v*j,w*j});
            }
            if(s > 0) vec.push_back({-1,v*s,w*s});
        }
        else{
            vec.push_back({s,v,w});
        }
    }
    for(auto obj : vec){
      if(obj.st == 0)   
        for(int i = obj.v; i <= m ; i++)//一开始错因为 v 和 w 写反了
                f[i] = max(f[i], f[i - obj.v] + obj.w);
        else
            for(int i = m; i >= obj.v; i --) 
                f[i] = max(f[i], f[i - obj.v] + obj.w);
    }
    cout << f[m];
    return 0;
}