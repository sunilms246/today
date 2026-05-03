from collections import deque

def bfs(graph, start):
    q = deque([start])
    seen = {start}

    while q:
        node = q.popleft()
        print(node)

        for nxt in graph[node]:
            if nxt not in seen:
                seen.add(nxt)
                q.append(nxt)

# Example graph
graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': [],
    'D': []
}

bfs(graph, 'A')