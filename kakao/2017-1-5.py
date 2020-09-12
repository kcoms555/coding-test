from typing import *
import collections
import heapq
import re

def get_inter(set1: Dict[int, int], set2: Dict[int, int]) -> Dict[int, int]:
	multiset = collections.defaultdict(int)
	for index in set1:
		if index in set2:
			multiset[index] = min(set1[index], set2[index])
	return multiset

def get_union(set1: Dict[int, int], set2: Dict[int, int]) -> Dict[int, int]:
	multiset = collections.defaultdict(int)
	for index in set1:
		multiset[index] = max(set1[index], set2[index])
	for index in set2:
		multiset[index] = max(set1[index], set2[index])
	return multiset

def p5(str1: str, str2: str) -> int:
	#str1 = "".join(re.split("[^a-zA-Z]*", str1.lower())
	#str2 = "".join(re.split("[^a-zA-Z]*", str2.lower())
	str1 = str1.lower()
	str2 = str2.lower()
	multiset1 = collections.defaultdict(int)
	multiset2 = collections.defaultdict(int)
	for index in range(len(str1)-1):
		if str1[index:index+2].isalpha():
			multiset1[str1[index:index+2]] += 1
	for index in range(len(str2)-1):
		if str2[index:index+2].isalpha():
			multiset2[str2[index:index+2]] += 1
	if not get_union(multiset1, multiset2):
		return 65536
	similarity = sum(get_inter(multiset1, multiset2).values())/sum(get_union(multiset1, multiset2).values())
	return int(similarity * 65536)
	
	

rets = []
rets.append(["FRANCE",	"french",	16384  ])
rets.append(["handshake",	"shake hands",	65536  ])
rets.append(["aa1+aa2",	"AAAA12",	43690  ])
rets.append(["E=M*C^2",	"e=m*c^2",	65536  ])

[print(f'return : {p5(i[0], i[1])}, expected return : {i[-1]}\n') for i in rets]
