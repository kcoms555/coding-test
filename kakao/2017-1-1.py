from typing import *
import collections
import heapq

def p1(n: int, arr1: List[int], arr2: List[int]) -> None:
	arr = []
	for i in range(n):
		#solution 1
		'''
		tmp = (arr1[i] | arr2[i])
		s = ""
		for j in range(n-1,-1,-1):
			if (tmp>>j)&1:
				s+='#'
			else:
				s+=' '
		arr.append(s)
		'''

		#solution 2
		arr.append(
			bin(arr1[i] | arr2[i])[2:]
				.zfill(n)
				.replace('1','#')
				.replace('0','#')
		)
	print(arr)

p1( 5,
	[9, 20, 28, 18, 11],
	[30, 1, 21, 17, 28])
print("expected stdout : ")
print(["#####","# # #","### #","#  ##","#####"])

p1( 6,
	[46, 33, 33, 22, 31, 50],
	[27, 56, 19, 14, 14, 10])
print("expected stdout : ")
print(["######","###  #","##  ##"," #### "," #####","### # "])
