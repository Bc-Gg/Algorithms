# include<iostream>
# include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int buy = -prices[0], sell = 0;
        for(int i = 0 ; i < len ;i++){
            buy = max(buy, sell - prices[i]);
            sell = max(buy + prices[i],sell);
        }
        return sell;
    }
int main(){
    int n;
    cin >> n;
    vector<int > v;
    for(int i= 0 ; i < n ; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    cout << maxProfit(v);
    return 0;
}
