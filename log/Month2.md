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

## leetcode 152 
### 思路
类似最大子列和，但是要注意到可能出现负负得正的情况，所以在每次计算的时候记录下来所有绝对值大的数（也就是开两个数组，一个记录正的最大，一个记录负的最小），嗯代码第一次写的很简单，交了两发就ac了。但是时间和空间都很难看，尝试优化。
### 第一次ac
```cpp
    class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 从其数列性质可以看出只需要自底向上算一遍就行了
        vector<int> dpmax(nums);
        vector<int> dpmin(nums);
        for(int i = 1 ; i < nums.size();i++){
            dpmax[i] = max(dpmax[i-1] * nums[i],max(dpmin[i-1]* nums[i],nums[i]));
            dpmin[i] = min(dpmin[i-1] * nums[i],min(dpmax[i-1] * nums[i], nums[i]));
        }
        int res = -0xfffffff;
        for(auto v: dpmax){
            res = max(res,v);
        }
        return res;
    }
};
```
![](photo/2022-03-27-16-06-52.png)
### 第二次ac
思路：其实dpmax和dpmin都是可以去掉的，我们在每一次循环中只需要当前的最大值和最小值，所以只需要两个int变量就可以解决问题。这样在每次循环的时候只需要先判断nums[i]的符号再进行乘法运算就好了。但是改造之后都是O(n)的复杂度。
```cpp

``` class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx = max(1,nums[0]), minn = min(1,nums[0]),ans = nums[0];
        int len = nums.size();// -------------这个变量len是本程序执行的精华，可以达到0ms
        for(int i = 1 ; i < len;i++){
            auto num = nums[i];
            if(num < 0){
                auto t = maxx;
                maxx = max(minn * num, num);
                minn = min(t * num, num);
            }
            else{
                maxx = max(maxx * num, num);
                minn = min(minn * num, num);
            }
            ans = max(maxx,ans);
        }
        return ans;
    }
};
```
![](photo/2022-03-27-16-27-17.png)
**后记** 后面把第一个ac程序加了一个len之后也可以达到0ms。看来是vector.size()太慢了。查了一下cppreference，应该是O（1）的复杂度，不知道为啥能这么慢。无语。以后学会了，每次调用先把这个长度信息存起来。