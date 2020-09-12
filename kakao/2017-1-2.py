from typing import *
import collections
import heapq

def p2(dartResult: str) -> int:
	score = [0,0,0,0]
	index = 0
	tmpnum = ''
	for c in dartResult:
		if tmpnum:
			index += 1
			if c.isnumeric():
				score[index] = int(tmpnum + c)
				tmpnum = ''
				continue
			else:
				score[index] = int(tmpnum)
				tmpnum = ''

		if c.isnumeric():
			tmpnum = c
		elif c.isalpha():
			if c == 'S':
				score[index] **= 1
			elif c == 'D':
				score[index] **= 2
			elif c == 'T':
				score[index] **= 3
		else:
			if c == '#':
				score[index] *= -1
			elif c== '*':
				score[index-1] *= 2
				score[index] *= 2
	return sum(score[1:])

rets = []
rets.append([ "1S2D*3T", 37 ])
rets.append([ "1D2S#10S", 9 ])
rets.append([ "1D2S0T", 3 ])
rets.append([ "1S*2T*3S", 23 ])
rets.append([ "1D#2S*3S", 5 ])
rets.append([ "1T2D3D#", -4 ])
rets.append([ "1D2S3T*", 59 ])

[print(f'return : {p2(i[0])}, expected return : {i[1]}') for i in rets]
