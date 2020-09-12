from typing import *
import collections
import heapq

def p3(cacheSize: int, cities: List[str]) -> int:
	'''
	# solution using Deque with maxlen
	cache = collections.deque( maxlen = cacheSize )
	elapsed = 0
	hit = 1
	miss = 5

	for city in cities:
		if city.lower() in cache:
			elapsed += hit
		else:
			elapsed += miss
			cache.appendleft(city.lower())

	return elapsed
	'''
	# solution using Deque
	cache = collections.deque()
	elapsed = 0
	hit = 1
	miss = 5

	for city in cities:
		if city.lower() in cache:
			elapsed += hit
		else:
			elapsed += miss
			cache.appendleft(city.lower())
			if len(cache) > cacheSize:
				cache.pop()

	return elapsed

rets = []
rets.append([ 3, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"], 50])
rets.append([ 3, ["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"], 21])
rets.append([ 2, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "    NewYork", "Rome"], 60])
rets.append([ 5, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "    NewYork", "Rome"], 52])
rets.append([ 2, ["Jeju", "Pangyo", "NewYork", "newyork"], 16])
rets.append([ 0, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA"], 25])

[print(f'return : {p3(i[0], i[1])}, expected return : {i[-1]}') for i in rets]
