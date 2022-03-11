# include<stdio.h>
# include<iostream>
# include<vector>
using namespace std;
long long  ans[100] = {3,6};
long long st[9] ={0,1,1,1,0,1,1,1,0},sub[9];

void sum1(int n){
    long long s = 0;
    for(int i = 0 ; i < 9 ; i++){
        if((i/3) != (i%3)) s+=st[i];
    }
    ans[n-1] = s;
}

int dp(int a){
    for(int i = 2 ; i < a ; i++){
        for(int j = 0 ; j < 9 ; j++){
            int head = j / 3, tail = j % 3;
            sub[j] = 0;
            sub[j] = st[3*head] + st[3*head+1] + st[3*head+2] - st[3*head+tail];
        }
        for(int j = 0 ; j < 9 ; j++){
            st[j] = sub[j];
        }
        sum1(i+1);
    }
}

int main(){
    int a;
    dp(51);
    while(scanf("%d",&a)!=EOF){
            printf("%lld\n",ans[a-1]);
    }
    return 0;
}
