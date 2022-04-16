from collections import deque

# 단조큐 해결 방식
# 시간 복잡도 : s=len(stones) 일때, O(s)
def solution1(stones, k):
    lists = []
    q = deque() ## front 가 가장 큼
    for i,v in enumerate(stones):
        while len(q) > 0 and q[-1][0] <= v:
            q.pop()
        q.append((v, i))
        while len(q) > 0 and q[0][1] < i-k+1:
            q.popleft()
        lists.append(q[0][0])
    return min(lists[k-1:])

# 아래 코드는 방법은 아래와 동일하게 O(s) 안에 연속된 k가 있는지 반환하지만, 아래 방법보다 3배 더 느려서 실패 
def can_they_go_failed(number_of_people, stones, k):
    one_if_stone_left_or_zero = ['0' if stone - (number_of_people - 1) <= 0 else '1' for stone in stones]
    return not k * '0' in ''.join(one_if_stone_left_or_zero)

def can_they_go(number_of_people, stones, k):
    count = 0
    for stone in stones:
        if stone - (number_of_people - 1) > 0:
            count = 0
            continue
        count += 1
        if count >= k:
            return False
    return True

def parametric_search_for_k(stones, k, lower, higher):
    if lower + 1 == higher:
        return lower

    if lower == higher:
        Exception('lower 와 higher가 같을 수 없습니다')

    mid = (lower + higher) // 2
    if can_they_go(mid, stones, k):
        return parametric_search_for_k(stones, k, mid, higher)
    else:
        return parametric_search_for_k(stones, k, lower, mid)

# 파라메트릭 서치 해결 방식
# 시간 복잡도 : s=len(stones) 일때, O(slogs)
def solution2(stones, k):
    if can_they_go(max(stones), stones, k):
        return max(stones)
    return parametric_search_for_k(stones, k, 0, max(stones))

def solution(stones, k):
    return solution2(stones, k)

print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1],3))