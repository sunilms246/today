import heapq

def ucs(g, s, goal):
    q = [(0, s)]
    seen = set()

    while q:
        cost, n = heapq.heappop(q)
        if n in seen: continue
        print(n, cost)
        if n == goal: return
        seen.add(n)
        for x, w in g[n]:
            heapq.heappush(q, (cost + w, x))

g = {
    'A':[('B',1),('C',4)],
    'B':[('D',2)],
    'C':[('D',1)],
    'D':[]
}

ucs(g,'A','D')