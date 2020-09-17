from typing import *
import collections

def log_to_ints(log: str) -> (int, int):
    if not log:
        return (0, 0)
    ltime, rtime = log.split('-')
    return (time_to_int(ltime), time_to_int(rtime))

def time_to_int(time: str) -> int:
    if not time:
        return 0
    hh, mm, ss = time.split(':')
    return int(hh)*60*60 + int(mm)*60 + int(ss)
def int_to_time(timestamp: int) -> str:
    mm, ss = divmod(timestamp, 60)
    hh, mm = divmod(mm, 60)
    return str(hh).zfill(2)+":"+str(mm).zfill(2)+":"+str(ss).zfill(2)

def solution(play_time: str, adv_time: str, logs: List[str]) -> str:
    ptime = time_to_int(play_time)
    atime = time_to_int(adv_time)
    logslist = [log_to_ints(log) for log in logs]
    start_times = collections.deque(sorted([time[0] for time in logslist]))
    end_times = collections.deque(sorted([time[1] for time in logslist]))

    #times[n] == (time, watcher)
    watcher = 0
    times = collections.deque([(0, 0)])
    while start_times or end_times:
        if not start_times:
            time = end_times.popleft()
            watcher -= 1
            times.append((time, watcher))
            continue
        if start_times[0] > end_times[0]:
            time = end_times.popleft()
            watcher -= 1
            times.append((time, watcher))
        # 시청 시작점과 끝점이 같은 시각인 경우 시청자의 수는 변함이 없다고 해도 문제 없다. 따라서 값을 꺼내고 무시한다
        elif start_times[0] == end_times[0]:
            start_times.popleft()
            end_times.popleft()
        else:
            time = start_times.popleft()
            watcher += 1
            times.append((time, watcher))
#    [print(i) for i in times]
    
    #total_times[n] == (total_time, starttime)
    total_times = []
    while times:
        total_time = 0
        left_time = atime
        timeval = None
        watcher = None
        for time, tmpwatcher in times:
            if timeval == None:
                timeval = time
                watcher = tmpwatcher
                continue
            if timeval + left_time <= time:
                total_time += left_time * watcher
                break
            else:
                timegap = time - timeval
                left_time -= timegap
                total_time += timegap * watcher
                
                timeval = time
                watcher = tmpwatcher
        total_times.append((total_time, times[0][0]))
        times.popleft()
        
#    [print(f'{int_to_time(i[1])} : {i[0]//60//60}:{(i[0]//60)%60}:{i[0]%60}s') for i in total_times]
    total_time_max = 0
    total_time_max_start = 0
    for total_time, start_time in total_times:
        if start_time + atime <= ptime:
            if total_time_max < total_time:
                total_time_max = total_time
                total_time_max_start = start_time
    
    return int_to_time(total_time_max_start)

