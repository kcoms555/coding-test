from typing import *
import heapq
import collections

def solution(n: int, s: int, a: int, b: int, fares: List[List[int]]):
    graph = collections.defaultdict(list)
    for c, d, f in fares:
        graph[c].append((d,f))
        graph[d].append((c,f))

    distance_s = collections.defaultdict(int)
    path_s = collections.defaultdict(int)

    #(consuming_time, node)
    Q_s = [(0,s,s)]
    while Q_s:
        consuming_time, node, _from = heapq.heappop(Q_s)
        if node not in distance_s:
            path_s[node] = _from
            distance_s[node] = consuming_time
            for to, time in graph[node]:
                heapq.heappush(Q_s, (consuming_time+time, to, node))
    
    #방문 가능한 노드 점검
    possible_nodes = [node for node in distance_s]
    
    cost = collections.defaultdict(int)
    for center_node in possible_nodes:
        distance_a = collections.defaultdict(int)
        distance_b = collections.defaultdict(int)
        distance_s = collections.defaultdict(int)
        path_a = collections.defaultdict(int)
        path_b = collections.defaultdict(int)
        path_s = collections.defaultdict(int)

        Q_a = [(0,center_node,center_node)]
        while Q_a:
            consuming_time, node, _from = heapq.heappop(Q_a)
            if node not in distance_a:
                distance_a[node] = consuming_time
                if node == a:
                    break
                for to, time in graph[node]:
                    heapq.heappush(Q_a, (consuming_time+time, to, node))
        Q_b = [(0,center_node,center_node)]
        while Q_b:
            consuming_time, node, _from = heapq.heappop(Q_b)
            if node not in distance_b:
                distance_b[node] = consuming_time
                if node == b:
                    break
                for to, time in graph[node]:
                    heapq.heappush(Q_b, (consuming_time+time, to, node))
        Q_s = [(0,center_node,center_node)]
        while Q_s:
            consuming_time, node, _from = heapq.heappop(Q_s)
            if node not in distance_s:
                distance_s[node] = consuming_time
                if node == s:
                    break
                for to, time in graph[node]:
                    heapq.heappush(Q_s, (consuming_time+time, to, node))
        cost[center_node] = distance_a[a]+distance_b[b]+distance_s[s] 

    return min(cost.values())

