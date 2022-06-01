# Month 4
**22920202200764刘本宸**
### leetcode79
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