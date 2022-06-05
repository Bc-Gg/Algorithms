# Month 4
**22920202200764刘本宸**
### leetcode79 medium
```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # 使用深度优先搜索
        if not board: 
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfs(board, i, j, word):
                    return True
        return False

    def dfs(self, board, i, j, word):
        if len(word) == 0:
            return True
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or word[0] != board[i][j]: 
            return False
        tmp = board[i][j]
        board[i][j] = '0' # 不用另外开辟vis数组
        res = False 
        direction = [(0,1),(0,-1),(1,0),(-1,0)]
        for dx, dy in direction:
            res = res or self.dfs(board,i+dx,j+dy,word[1:])

        board[i][j] = tmp
        return res
```
![](photo/2022-06-02-00-16-48.png)
回溯模版题，练练手

### leetcode 282 hard
```python
class Solution:
    def addOperators(self, num: str, target: int) -> list[str]:
        n = len(num)
        ans = []
        def dfs(expr , i , res , mul): # 乘法要因为优先级单独计算
            if i == n:
                if res == target:
                    ans.append(''.join(expr))
                return
            signIndex = len(expr) # 每次在表达式最后添加operator
            if i > 0:
                expr.append('')  
            val = 0
            for j in range(i, n): 
                if j > i and num[i] == '0': 
                    break
                val = int(str(val) + num[j]) # 更新下一个操作数
                expr.append(num[j])
                if i: 
                    expr[signIndex] = '+'
                    dfs(expr, j + 1, res + val, val)
                    expr[signIndex] = '-'
                    dfs(expr, j + 1, res - val, -val)
                    expr[signIndex] = '*'
                    dfs(expr, j + 1, res - mul + mul * val, mul * val)
                else:  # 表达式开头不能添加符号
                    dfs(expr, j + 1, val, val)
            expr = expr[:signIndex]

        dfs([], 0, 0, 0)
        return ans
```
![](photo/2022-06-02-15-46-28.png)
**本题还是回溯法的模版，对标两个题（24点 && 组合）加了两个难点**
1. 乘法的优先级与加减不一样，要做特别的判断
2. 给定的是一个字符串，要做字符串切割和前导0的判断

### leetcode 306 medium
```cpp
typedef long long ll;
class Solution {
public:
    bool func(string& num, ll pre, ll cur, int now, int n){
        if(now == n)    return true; // 递归出口
        for(int i=now; i<n; ++i){
            if(num[now]=='0'&&i>now)    return false;// 前导0的判断
            ll a = stoll(num.substr(now,i-now+1));
            if(a>pre+cur)   return false; // 找大了，跳过
            if(a==pre + cur){
                if(func(num,cur,a,i+1,n))   return true;
                break;
            }
        }return false;
    }
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for(int i=0; i<len/2; ++i){
            if(num[0]=='0' && i>0)  return false;
            for(int j=i+1; j<i+1+(len-i-1)/2; ++j){ // 枚举所有的开始的数字
                if(num[i+1]=='0' && j>i+1)   continue;//前导0的判断
                ll pre = stoll(num.substr(0,i+1));
                ll cur = stoll(num.substr(i+1,j-i));
                if(func(num,pre,cur,j+1,len))    return true;
            }
        }
        return false;
    }
};
```
![](photo/2022-06-05-10-53-15.png)
1. 尝试了一下stoll，很好用啊，解决了字符串转数字的难题，比官方解答简单很多
2. 思路清晰。先枚举所有的开头的两个数字，再dfs找到所有后续。中间注意前导0和中间过程答案不相等的所有剪枝。主函数中第一个for循环 len/2 是从别的题解里面学来的。很不错。
3. 有十行就解决的代码。copy到最后。可惜是没用记忆化搜索，时间空间都有些差距。
```js
var isAdditiveNumber = function (num) {
    for (let m = 1; m < num.length; m++) {
        let n1 = +num.slice(0, m);
        if (num[0] === '0' && m > 1) return false;
        for (let r = m + 1; r < num.length; r++) {
            if (num[m] === '0' && r - m > 1) break;
            let n2 = +num.slice(m, r), r_2 = r, n_1 = n1, n3 = n1 + n2;
            while (num.slice(r_2, r_2 + `${n3}`.length) === `${n3}`) {
                (r_2 = r_2 + `${n3}`.length), (n_1 = n2), (n2 = n3), (n3 = n_1 + n2);
            }
            if (r_2 === num.length) return true;
        }
    }

    return false;
};
/*
作者：jie-ma
链接：https://leetcode.cn/problems/additive-number/solution/hui-su-10xing-by-jie-ma-nn75/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
```

### leetcode 473 medium
```cpp
class Solution {
public:
    int cmp (int& a, int& b){
        return a > b;
    }
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false; // 火柴个数小于4，无法组成正方形
        int totalLen = accumulate(nums.begin(), nums.end(), 0);
        if (totalLen % 4) return false;
        else{
            vector<int> edges(4);
            sort(nums.begin(),nums.end());
            reverse(nums.begin(),nums.end());
            return dfs(nums, edges, totalLen / 4, 0);
        }
    }
    bool dfs(vector<int> nums, vector<int> edges, int len, int ind) {
        if (ind == nums.size()) return true;
        for (int i = 0; i < 4; i++) {
            // 两种剪枝 1. 大于所需要的正方形的边的长度 2.跳过已经处理过的
            if(edges[i] + nums[ind] > len) continue;
            if(i > 0 && edges[i] == edges[i - 1]) continue;
            edges[i] += nums[ind];
            if (dfs(nums, edges, len, ind + 1)) return true;
            edges[i] -= nums[ind]; // 恢复现场
        }
        return false;
    }

};
```
![](photo/2022-06-05-11-09-41.png)
1. 这次时空复杂度出奇的垃圾。 看了看0ms的样例，问题出在了函数变量来回传上。剪枝函数大同小异
2. 一开始想麻烦了，有点像木棍。