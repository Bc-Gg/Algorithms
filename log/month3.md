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