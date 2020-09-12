from typing import *
import collections
import heapq

def int_to_time(timestamp: int) -> str:
	hh, mm = divmod(timestamp, 60)
	return str(hh).zfill(2)+':'+str(mm).zfill(2)

def time_to_int(s: str) -> int:
	hh, mm = s.split(':')
	return int(hh) * 60 + int(mm)
	
# n회 t분 간격으로, 최대 m명 탑승
def p4(n: int, t: int, m: int, timetable: List[int]) -> str:
	crew_queue = collections.deque(sorted([time_to_int(s) for s in timetable]))
	buses = [(nth * t, m) for nth in range(n)]
	bus_queue = collections.deque([(time_to_int("09:00")+timeoffset, limit)
									for timeoffset, limit in buses])

	last_bus_time = time_to_int("09:00")
	last_crew_time = time_to_int("23:59")
	is_seat_available = False
	while bus_queue:
		is_seat_avilable = False
		last_bus_time, seats = bus_queue.popleft()
		while crew_queue:
			#크루가 더 빠르고 태울 수 있을 때
			if crew_queue[0] <= last_bus_time and seats > 0:
				last_crew_time = crew_queue[0]
				seats -= 1
				crew_queue.popleft()
			else:
				break;
		if seats:
			is_seat_available = True
		else:
			is_seat_available = False

	if last_bus_time >= last_crew_time:
		if is_seat_available:
			return int_to_time(last_bus_time)
		else:
			return int_to_time(last_crew_time-1)
	elif last_bus_time < last_crew_time:
		return int_to_time(last_bus_time)

'''
# n회 t분 간격으로, 최대 m명 탑승
def p4(n: int, t: int, m: int, timetable: List[int]) -> str:
	crew_queue = collections.deque(sorted([time_to_int(s) for s in timetable]))
	buses = [(nth * t, m) for nth in range(n)]
	bus_queue = collections.deque([(time_to_int("09:00")+timeoffset, limit)
									for timeoffset, limit in buses])

	last_bus_time = time_to_int("09:00")
	last_crew_time = time_to_int("23:59")
	is_seat_available = False
#	print([int_to_time(s) for s, seats in bus_queue], m)
#	print([int_to_time(s) for s in crew_queue])
	while bus_queue:
#		print(f'set seat False')
		is_seat_avilable = False
		last_bus_time, seats = bus_queue.popleft()
		while crew_queue:
			#크루가 더 빠르고 태울 수 있을 때
			if crew_queue[0] <= last_bus_time and seats > 0:
				last_crew_time = crew_queue[0]
#				print(f'bus({int_to_time(last_bus_time)}) taking ({int_to_time(last_crew_time)})')
				seats -= 1
				crew_queue.popleft()
			else:
				break;
		if seats:
#			print(f'set seat True : {seats}')
			is_seat_available = True
		else:
#			print(f'set seat False : {seats}')
			is_seat_available = False
#	print(f'lastbus : {int_to_time(last_bus_time)}, last_cruew : {int_to_time(last_crew_time)}')

	if last_bus_time >= last_crew_time:
		if is_seat_available:
			return int_to_time(last_bus_time)
		else:
			return int_to_time(last_crew_time-1)
	elif last_bus_time < last_crew_time:
		# 승객이 타지 않았거나?
		return int_to_time(last_bus_time)
'''		


rets = []
rets.append([1,	1,	5,	["08:00", "08:01", "08:02", "08:03"],	"09:00"  ])
rets.append([2,	10,	2,	["09:10", "09:09", "08:00"],	"09:09" ]) 
rets.append([2,	1,	2,	["09:00", "09:00", "09:00", "09:00"],	"08:59"  ])
rets.append([1,	1,	5,	["00:01", "00:01", "00:01", "00:01", "00:01"],	"00:00"  ])
rets.append([1,	1,	1,	["23:59"],	"09:00"  ])
rets.append([10,60,	45,	["23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"],	"18:00"  ])

[print(f'return : {p4(i[0], i[1], i[2], i[3])}, expected return : {i[-1]}\n') for i in rets]
