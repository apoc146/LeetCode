class Solution:
    def __init__(self):
        self.m = -1
        self.n = -1

    def check(self, x, y):
        return 0 <= x < self.m and 0 <= y < self.n

    def memo(self, x, y, matrix, dp):
        if self.check(x, y) and dp[x][y] != -1:
            return dp[x][y]

        val = matrix[x][y]
        xs = [0, -1, 0, +1]
        ys = [-1, 0, +1, 0]
        self.m = len(matrix)
        self.n = len(matrix[0])

        maxVal = 1
        for cnt in range(4):
            ptx, pty = x + xs[cnt], y + ys[cnt]
            if self.check(ptx, pty) and matrix[ptx][pty] > val:
                maxVal = max(maxVal, 1 + self.memo(ptx, pty, matrix, dp))

        dp[x][y] = maxVal
        return maxVal

    def foo(self, x, y, matrix):
        val = matrix[x][y]
        xs = [0, -1, 0, +1]
        ys = [-1, 0, +1, 0]
        self.m = len(matrix)
        self.n = len(matrix[0])

        maxVal = 1
        for cnt in range(4):
            ptx, pty = x + xs[cnt], y + ys[cnt]
            if self.check(ptx, pty) and matrix[ptx][pty] > val:
                maxVal = max(maxVal, 1 + self.foo(ptx, pty, matrix))

        return maxVal

    def longestIncreasingPath(self, matrix):
        track = []
        ans = 1
        m = len(matrix)
        n = len(matrix[0])
        dp = [[-1 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                print(i, j)
                ans = max(ans, self.memo(i, j, matrix, dp))

        return ans
