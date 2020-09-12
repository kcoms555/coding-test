from typing import *
import collections
import heapq

# "2016-09-15 00:00:01.001 2.0s" -> (-999, 1001)
def line_to_start_end(line: str) -> (int, int):
	if not line:
		return (0, 0)
	tokens = line.split(' ')
	hh, mm, ss = tokens[1].split(':')
	end = 	int(hh)*60*60*1000 + int(mm)*60*1000 + int(float(ss)*1000)
	start = end - int(float(tokens[2][:-1])*1000) + 1
	return start, end
	
def p7(lines: List[str]) -> int:
	times = [line_to_start_end(line) for line in lines]
	starts = collections.deque(sorted([time[0]-999 for time in times]))
	ends = collections.deque([time[1] for time in times])

	process = 0
	_max = 0
	while starts:
		if ends[0] < starts[0]:
			ends.popleft()
			process -= 1
			continue
		elif ends[0] >= starts[0]:
			starts.popleft()
			process += 1
			_max = process if _max < process else _max
	
	return _max

rets = []
rets.append([[ "2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s" ], 1])
rets.append([[ "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" ], 2])
rets.append([[ "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s" ], 7])

[print(f'return : {p7(i[0])}, expected return : {i[-1]}\n') for i in rets]
