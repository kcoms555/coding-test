import collections
from typing import *
from itertools import combinations

def solution(orders: List[str], course: List[int]) -> List[str]:
    counter_dict = {}
    answer = []
    for count in course:
        counter_dict[count] = counter = collections.defaultdict(int)
        for order in orders:
            orderlist = combinations(order, count)
            for menu in orderlist:
                #각 메뉴는 정렬됨이 보장되어 있지 않다
                counter["".join(sorted(menu))] += 1
    for count in course:
        if not counter_dict[count]:
            continue
        max_ = max(counter_dict[count].values())
        if max_ < 2:
            continue
        for item in counter_dict[count].items():
            if item[1] == max_:
                answer.append(item[0])
    
    return sorted(answer)
