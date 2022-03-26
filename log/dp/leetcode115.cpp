
class Solution {
    
public:
    ulong dp[1010][1010] ={0};
    const long long N = 1e3 +10;
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        auto lent = t.size();
        auto lens = s.size();
        //init 
        for(int i = 0 ; i <= lent; i++) dp[lens][i] = 0;// s[lens:] == None
        for(int i = 0 ; i <= lens; i++) dp[i][lent] = 1;// t[lent:] == None
        //dp
        for(int i = lens-1 ; i>=0 ;i--){
            for(int j  = lent -1; j>=0 ;j--){
                dp[i][j] = dp[i+1][j];
                if (s[i] == t[j]) dp[i][j]+= dp[i+1][j+1];
                // cout << dp[i][j]<< endl;
            }
        }
        return dp[0][0];
    }
};