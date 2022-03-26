# include<iostream>
# include<vector>
using namespace std;
typedef long long ll;
const int N = 1e9+7;
# include<iostream>
using namespace std;
int main(){
    ll n,k;
    cin >> n >> k;
    auto plate = new ll[n+1];
    plate[1] = k;
    for(int i = 2 ; i <= n ; i++){
        plate[i] = ((plate[i-1] + plate[i-2]) * (k-1)) % N;
        cout << plate[i] << ' ' << plate[i-1] <<endl;
    }
    cout << (plate[n] + plate[n-1]) % N << endl;
    return 0;
}

/*
int main(){
    int n,k;
    cin >> n >> k;
    auto plate = new int[n+1]; // 第n个盘子的状态
    auto last = new int[n+1]; // 第n-1个盘子的状态
    plate[1] = k;
    for(int i = 2 ; i <= n ; i++){
        plate[i] = (plate[i-1] + last[i-1]) * (k-1);//状态转移
        last[i] = plate[i-1]; // 更新n-1个盘子,这里注意到last[i-1] == plate[i-2]，可以考虑简化状态转移的写法
    }
    cout << plate[n] + last[n] << endl;
    return 0;
}


等价变换后的简便写法：

# include<iostream>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    auto plate = new int[n+1];
    plate[1] = k;
    for(int i = 2 ; i <= n ; i++)
        plate[i] = (plate[i-1] + plate[i-2]) * (k-1);
    cout << plate[n] + plate[n-1] << endl;
    return 0;
}
*/