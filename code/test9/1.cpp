# include<iostream>
# include<vector>
# include<cstring>
using namespace std;
const int N = 10010;
int bus[60], road[N];
int n;

int check(int a, int d){
    for(int i = a ; i < 60;i+=d)  if(!bus[i]) return 0;
    return 1;
}

int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        int t;
        scanf("%d",&t);
        bus[t]++;
    }

    return 0;
}