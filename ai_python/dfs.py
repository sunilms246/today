def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()

    if start in visited:
        return

    print(start)
    visited.add(start)

    for nxt in graph[start]:
        dfs(graph, nxt, visited)


# Example graph
graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': [],
    'D': []
}

dfs(graph, 'A')