# include<iostream>
#include<vector>
using namespace std;
const int N = 100100;

int a[N];
int f1[N];
int f2[N];
int main(){
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    if(n == 1){ cout << a[0]; return 0;}
    f1[0] = f1[1] = a[0];
    f2[0] = 0;
    f2[1] = a[1];
    for(int i = 2 ; i < n - 1; i++){// 选第一个
        f1[i] = max(f1[i-1], f1[i-2] + a[i]);
    }
    f1[n-1] = f1[n-2];
    for(int i = 2; i < n;i++){
        f2[i] = max(f2[i-1],f2[i-2]+a[i]);
    }
    cout << max(f1[n-1],f2[n-1]);
    return 0;
}