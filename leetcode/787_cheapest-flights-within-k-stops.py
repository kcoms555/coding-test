from typing import *
import heapq
import collections

def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
	#list -> adjacency list with dictionary
	graph = collections.defaultdict(list)
	for _from, to, price in flights:
		graph[_from].append((to, price))
	
	#(price, node, k stops)
	Q = [(0, src, K)]

	while Q:
		price, node, k = heapq.heappop(Q)
		if node == dst:
			return price
		if k < 0:
			continue
		for to, next_price in graph[node]:
			heapq.heappush(Q, (price+next_price, to, k-1))
	return -1

