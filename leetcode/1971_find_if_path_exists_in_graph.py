class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        self.adj_list = collections.defaultdict(list)

        for node1, node2 in edges:
            self.adj_list[node1].append(node2)
            self.adj_list[node2].append(node1)
        
        self.visited = set()
        return self.dfs(source, destination)

    def dfs(self, node, end):
        if node == end:
            return True

        if node not in self.visited:
            self.visited.add(node)
        
            for neighbor in self.adj_list[node]:
                result = self.dfs(neighbor, end)

                if result:
                    return True
