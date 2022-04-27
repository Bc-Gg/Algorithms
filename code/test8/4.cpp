# include<iostream>
# include<algorithm>

using namespace std;
int n;
int output[20];
int vis[20];

int check(int a){// yes->1   no->0
    if(a%2 == 0) return 0;
    int list[11] = {2,3,5,7,11,13,17,19,23,29,31};
    for(int i = 0; i < 11 ; i++)
        if(a == list[i]) return 1;
    return 0;
}


void dfs(int pos){
    if(pos == n+1 && check(1 + output[n]))
    {
        for(int i = 1 ; i <= n ; i++){
            printf("%d ",output[i]);
        }
        cout << endl;
    }
    else{
        if(output[pos-1]%2){
            for(int i = 2 ; i <= n ; i+=2){
                if(!vis[i] && check(i+output[pos-1])){
                    output[pos] = i;
                    vis[i] = 1;
                    dfs(pos+1);
                    vis[i] = 0;
                }
            }
        }
        else{
            for(int i = 3 ; i <= n ; i+=2){
                if(!vis[i] && check(i+output[pos-1])){
                    output[pos] = i;
                    vis[i] = 1;
                    dfs(pos+1);
                    vis[i] = 0;
                }
            }
        }
    }
}


int main(){
    int cnt = 1;
    while(scanf("%d",&n)!=EOF && n){
        printf("Case %d:\n",cnt);
        if(n%2==0){
        output[1] = 1;
        vis[1] = 1; 
        dfs(2);
        }
        cout << endl;
        cnt++;
    }
    return 0;
}