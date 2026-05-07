from collections import deque

def bfs(g, start):

    visited = [start]
    queue = [start]

    print("\nBFS Step-by-Step:\n")

    while queue:

        print("Queue:", queue)

        node = queue.pop(0)

        print("Visited:", node)

        for n in g[node]:

            if n not in visited:

                print("  Adding:", n)

                visited.append(n)

                queue.append(n)

        print()

    print("Final Traversal:", visited)


# INPUT

edges = input("Enter edges (A-B): ").split()

g = {}

for e in edges:

    a, b = e.split('-')

    if a not in g:
        g[a] = []

    if b not in g:
        g[b] = []

    g[a].append(b)

start = input("Enter start node: ")

bfs(g, start)
