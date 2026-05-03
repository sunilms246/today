def agent(start, goal):
    # Define correct path
    graph = {
        'A': 'B',
        'B': 'C',
        'C': None
    }

    current = start

    while current != goal:
        print("Current:", current)
        current = graph[current]   # move using path
        print("Move →", current)

    print("Goal Reached:", current)


# Works even if you think in random order
agent('A', 'C')