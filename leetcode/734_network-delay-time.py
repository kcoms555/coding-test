import heapq
import collections

def networkDelayTime(times, N, K):
	#list -> adjacency list with dictionary
	graph = collections.defaultdict(list)
	for u, v, w in times:
		graph[u].append((v,w))
	
	distance = collections.defaultdict(int)

	#(consuming_time, node)
	Q = [(0,K)]

	while Q:
		consuming_time, node = heapq.heappop(Q)
		if node not in distance:
			distance[node] = consuming_time
			for to, time in graph[node]:
				heapq.heappush(Q, (consuming_time+time, to))
	
	print(distance)


times = [[2,1,1],[2,3,1],[3,4,1]]
K=2
N=4
networkDelayTime(times, N, K)
