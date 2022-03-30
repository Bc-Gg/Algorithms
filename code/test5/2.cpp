# include<iostream>
#include<vector>
using namespace std;
const int N = 10010;

int a[N];
int f[N];
int main(){
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    f[0] = a[0];
    f[1] = max(a[0], a[1]);
    for(int i = 2; i < n ; i++){
        if(i !=  n-1)
            f[i] = max(f[i-1], f[i-2] + a[i]);
        else 
            f[i] = f[i-1];
    }
    int ans = max(f[n-1],f[n-2]);
    cout << ans;
    return 0;
}