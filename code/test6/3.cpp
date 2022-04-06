# include<iostream>
#include<vector>
# include<algorithm>
using namespace std;
const int N = 5e4 +10;
vector < pair <int , int > > v;

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ;i++){
        int a,b;
        cin >> a>> b;
        v.push_back({a+b,a});
    }
    sort(v.begin(),v.end());
    int ans = -1e7;
    int sum = 0;
    for(auto p: v){
        ans = max(ans,sum -(p.first - p.second));
        sum += p.second;
    }
    cout << ans;
    return 0;
}