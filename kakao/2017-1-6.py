from typing import *
import collections
import heapq

def str_to_list(s: str) -> List[int]:
	l = []
	for c in s:
		l.append(ord(c)-ord('A')+1)
#	print(l)
	return l

#m : 높이, n : 폭, board[m][n]
def p6(m: int, n: int, board: List[str]) -> int:
	arr = [str_to_list(s) for s in board]
	on_droping =	 	0b1000000
	will_be_deleted = 	0b0100000
	character = 		0b0011111

	matched = True
	count = 0
	while matched:
		if matched:
			for i in range(m):
				for j in range(n):
					if will_be_deleted & arr[i][j]:
						count += 1
			for _ in range(m):
				for i in range(m-1, -1, -1):
					for j in range(n):
						if i>0:
							if (will_be_deleted|on_droping) & arr[i][j]:
								arr[i-1][j] |= on_droping
								arr[i][j] = arr[i-1][j]
						elif i==0:
							if arr[i][j] & on_droping:
								arr[i][j] = 0
				for i in range(m):
					for j in range(n):
						arr[i][j] &= will_be_deleted|character
			matched = False

#		print("now:")
#		[print(l) for l in arr]

		for i in range(m-1):
			for j in range(n-1):
				if ((character&arr[i][j]) == (character&arr[i+1][j])) and\
					((character&arr[i][j]) == (character&arr[i][j+1])) and\
					((character&arr[i][j]) == (character&arr[i+1][j+1])) and\
					character&arr[i][j]:
					arr[i][j] |= will_be_deleted
					arr[i+1][j] |= will_be_deleted
					arr[i][j+1] |= will_be_deleted
					arr[i+1][j+1] |= will_be_deleted
					matched = True
#		print("match after:")
#		[print(l) for l in arr]
	return count

rets = []
rets.append([4,	5,	["CCBDE", "AAADE", "AAABF", "CCBBF"],	14  ])
rets.append([6,	6,	["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"],	15  ])

[print(f'return : {p6(i[0], i[1], i[2])}, expected return : {i[-1]}\n') for i in rets]
