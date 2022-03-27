# Month2
## Dynamic Programming
## 背包问题
已经全部解决在dp文件夹中
## leetcode 115 
### dp写法
```cpp

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
```
![](photo/2022-03-26-23-14-19.png)
ps:过了，但是时间很难看，况且题目上说的是可以用int过掉，没想到最后还要用unsigned long，debug半天挺无语的。看看能不能学习一下别人的题解改进一下。
ps:ps:看了力扣上面速度超快的题解，发现别人都是特判了最长的数据，并不具有一般性。