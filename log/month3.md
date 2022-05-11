# Month3
### leetcode 93 medium
```cpp
class Solution {
    vector<string> ans;
    vector<int> ip;

public:
    void dfs(const string& s, int cnt, int st) {
        if (cnt == 4) {
            if (st == s.size()) {
                string ipAddr;
                for (int i = 0; i < 4; ++i) {
                    ipAddr += to_string(ip[i]);
                    if (i != 4 - 1) {
                        ipAddr += ".";
                    }
                }
                ans.push_back(move(ipAddr));
            }
            return;
        }
        if (st == s.size()) {
            return;
        }
        else if (s[st] == '0') {
            ip[cnt] = 0;
            dfs(s, cnt + 1, st + 1);
        }
        else{
            int addr = 0;
            for (int end = st; end < s.size(); ++end) {
                addr = addr * 10 + (s[end] - '0');
                if (addr > 0 && addr <= 255) {
                    ip[cnt] = addr;
                    dfs(s, cnt + 1, end + 1);
                } else {
                    break;
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ip.resize(4);
        dfs(s, 0, 0);
        return ans;
    }
};

```
**和时间复杂度低的代码差不多，人家是0ms，我就是4ms，很怪。前导0的剪枝一开始没想到，瞟了一眼答案，最后还是做出来了**
![](photo/2022-05-09-23-17-34.png)


### leetcode 526 medium
```cpp
# include<vector>
# include<cstring>
using namespace std;
class Solution {
public:
    int cnt;
    vector<vector<int >> perm;
    vector<int> v;
    void find_perm(int n){
        perm.resize(n+1);
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(!(i%j) || !(j%i)) perm[i].push_back(j);
            }
        }
    }

    void back(int lev, int n){
        if(lev > n) {
            cnt ++;
            return;
        }
        for(auto p :perm[lev]){
            if(!v[p]){
                v[p] = 1;
                back(lev+1, n);
                v[p] = 0;
            }
        }
    }

    int countArrangement(int n) {
        find_perm(n);
        v.resize(n+1);
        back(1,n);
        return cnt;
    }
};
```
**排列树的基本框架，但是带了一个优美排列的套路。所以相当于是每一个位置的排列都是有限制的，就是要在整个的排列上加一个限制，全排列的迭代改成因数的vector的迭代就好了**
![](photo/2022-05-11-16-56-06.png)