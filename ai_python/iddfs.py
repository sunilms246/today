def dls(graph, node, limit, visited):
    if limit < 0:
        return

    print(node)
    visited.add(node)

    for nxt in graph[node]:
        if nxt not in visited:
            dls(graph, nxt, limit - 1, visited)


def iddfs(graph, start, max_depth):
    for depth in range(max_depth + 1):
        print("\nDepth =", depth)
        dls(graph, start, depth, set())


# Example graph
graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': [],
    'D': []
}

iddfs(graph, 'A', 3)