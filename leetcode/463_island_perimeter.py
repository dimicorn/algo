class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])
        self.perim = 0
        self.visited = set()
        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j] == 1:
                    self.dfs(grid, i, j)
                    return self.perim
        
    def dfs(self, grid, i, j):
        if (i, j) in self.visited:
            if grid[i][j] == 0:
                self.perim += 1
            return
        self.visited.add((i, j))
        if not (0 <= i < self.n) or not (0 <= j < self.m) or grid[i][j] == 0:
            self.perim += 1
            return
        print(i, j, self.perim)
        self.dfs(grid, i-1, j)
        self.dfs(grid, i+1, j)
        self.dfs(grid, i, j-1)
        self.dfs(grid, i, j+1)
            
