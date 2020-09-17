from typing import *
import collections

class DB_Node:
    def __init__(self):
        self.child = collections.defaultdict(DB_Node)
        self.score = []
def search(s: str, node: DB_Node) -> List[DB_Node]:
    if s == "-":
        return node.child.values()
    else:
        return [node.child[s]]
def sort_all(root: DB_Node):
    l0 = search("-", root)
    l1 = []
    l2 = []
    l3 = []
    for node in l0:
        l1 += search("-", node)
    for node in l1:
        l2 += search("-", node)
    for node in l2:
        l3 += search("-", node)
    for node in l3:
        node.score.sort()

#이 이진탐색은 탐색 인덱스가 없을 시, target에서 가까운 값을 갖는 인덱스 중 상위의 인덱스 값을 반환
#ex2) 0, [1,3] -> 0
#ex1) 2, [1,3] -> 1
#ex3) 4, [1,3] -> -1(없음)
def binary_search(target: int, data: List[int]) -> int:
    start = 0
    end = len(data) - 1

    if not data:
        return -1
    if data[end] < target:
        return -1
    while start <= end:
        mid = (start + end) // 2

        if data[mid] == target:
            tmp = mid
            while data[tmp] == target:
                tmp -= 1
                if tmp < 0:
                    return 0
            return tmp+1
        elif data[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
#    while data[start]<target:
#        start += 1
    return start

def solution(info: List[str], query: List[str]) -> List[int]:
    answer = []
    db_root = DB_Node()
    for s in info:
        _0, _1, _2, _3, _4 = s.split()
        node = db_root
        node = node.child[_0]
        node = node.child[_1]
        node = node.child[_2]
        node = node.child[_3]
        node.score.append(int(_4))
    sort_all(db_root)
    for q in query:
        _0, _1, _2, _3, _4 = q.replace("and", "").split()
        counter = 0
        l0 = search(_0, db_root)
        l1 = []
        l2 = []
        l3 = []
        for node in l0:
            l1 += search(_1, node)
        for node in l1:
            l2 += search(_2, node)
        for node in l2:
            l3 += search(_3, node)
        for node in l3:
            if len(node.score) == 0:
                continue
            index = binary_search(int(_4), node.score)
            if index == -1:
                counter += 0
            else:
                counter += len(node.score) - index
        answer.append(counter)
    return answer
