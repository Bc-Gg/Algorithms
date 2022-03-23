# include<iostream>
# include<vector>
using namespace std;
typedef long long ll;
const int N = 2 * 1e6 +10;
const int m = 1e9+7;

int main(){
    ll n,k;
    cin >> n >> k;
    auto plate = new ll[k]; // 第n个盘子的状态
    for(int i = 0 ; i < k ; i++) plate[i] = 1; //一个盘子的状态
    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j < k ;j++){
            plate[j] *= k;
            if(i > 2)
                plate[j] --;
            // cout << plate[j] << ' ';
        }
        // cout <<endl;
    }
    ll sum = 0;
    for(int i = 0 ; i < k ;i++) sum += plate[i];
    cout << sum<< endl;
    return 0;
}