#include<iostream>
using namespace std;
const int N = 1001000;
int a[N];
int f[N],b[N];
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < n; i++){ // forward
        f[i]= 1;
        for(int j = 0 ; j < i ; j++){
            if(a[i] > a[j]) f[i] = max(f[i], f[j]+1);
        }
    }
    for(int i = n - 1 ; i>= 0 ;i--){ // backward
        b[i] = 1;
        for(int j = n-1 ; j >= i ; j--){
            if(a[i] > a[j]) b[i] = max(b[i], b[j]+1);
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        // cout << f[i] << ' ' << b[i] << endl;   
        ans = max(ans,f[i]+b[i]);
    }
    cout << n - (ans - 1);
    return 0;
}