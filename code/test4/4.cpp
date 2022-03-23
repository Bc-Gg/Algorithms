/*
皮卡丘，0
喵喵，  1
圆企鹅，2
巴大蝶  3
小火龙 4
*/
# include<iostream>
# include<vector>

using namespace std;

const long long N = 1e9+7;

long long num[5] = {1,1,1,1,1},st[5];


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1 ; i < n ;i++){
            st[0] = num[1] + num[2] + num[4];
            st[1] = num[0] + num[2];
            st[2] = num[1] + num[3];
            st[3] = num[2];
            st[4] = num[2] + num[3];
            for(int j = 0 ; j < 5 ; j++) num[j] = st[j] % N;
        }
        long long sum = 0;
        for(int i = 0; i < 5 ;i++) {
            sum += num[i];
            num[i] = 1;
        }
        cout << sum % N << endl;

    }
    return 0;
}