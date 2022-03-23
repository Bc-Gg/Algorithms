# include<iostream>
# include<vector>
using namespace std;
typedef long long ll;
const int N = 2 * 1e6 +10;
const int m = 1e9+7;

int main(){
    int n,k;
    cin >> n >> k;
    auto plate = new int[n+1]; // 第n个盘子的状态
    auto last = new int[n+1];
    plate[1] = k;
    for(int i = 2 ; i <= n ; i++){
        plate[i] = (plate[i-1] + last[i-1]) * (k-1);
        last[i] = plate[i-1];
    }
    cout << plate[n] + last[n] << endl;
    return 0;
}