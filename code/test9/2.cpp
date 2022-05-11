#include<bits/stdc++.h>
using namespace std;
int a[70],v[70],n,l,c;
bool dfs(int stick,int cab,int last){
    if(stick>c) return true;
    if(cab==l) return dfs(stick+1,0,1);
    int fail=0;
    for(int i=last;i<=n;i++){
        if(!v[i]&&cab+a[i]<=l&&fail!=a[i]){
            v[i]=1;
            if(dfs(stick,cab+a[i],i+1)) return true;
            fail=a[i];
            v[i]=0;
            if(cab==0||cab+a[i]==l) return false;       
        }
    }
    return false;
}
int main(){
    while(cin>>n&&n){
        int sum=0,val=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            val=max(val,a[i]);
        }
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        for(l=val;l<=sum;l++){
            if(sum%l) continue;
            c=sum/l;
            memset(v,0,sizeof(v));
            if(dfs(1,0,1)) break;
        }
        cout<<l<<endl;
    }
    return 0;
}
