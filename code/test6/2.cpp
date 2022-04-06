# include<iostream>
# include<algorithm>
#include<vector>
using namespace std;
const int N = 1010;
struct per{
    int d1,d2;
    int ds;
};
per f[N];
int cmp(per p1, per p2){
    return p1.ds < p2.ds;
}
int main(){
    int k;
    cin >> k;
    for(int i = 1 ; i <= 2*k;i++){
        cin >> f[i].d1 >> f[i].d2;
        f[i].ds = f[i].d1 - f[i].d2;
    }
    int sum = 0;
    sort(f+1,f+2*k+1,cmp);
    for(int i = 1 ; i <= k ;i++) sum+= f[i].d1;
    for(int i = k+1 ; i <= 2*k ;i++) sum+= f[i].d2;
    cout << sum;
    return 0;
}