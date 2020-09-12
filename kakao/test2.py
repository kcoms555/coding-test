from typing import *
import collections
def is_right(s: Deque[str]) -> bool:
    stack = []
    for c in s:
        if c=='(':
            stack.append(')')
        else:
            if not stack:
                return False
            else:
                if c == stack.pop():
                    continue
                else:
                    return False
    return False if stack else True
def make_good_str(w: Deque[str]) -> Deque:
    #1
    if not w:
        return w
    #2
    u = collections.deque('')
    v = w
    count = 0
    while True:
        c = v.popleft()
        u.append(c)
        if c == '(':
            count += 1
        else:
            count -= 1
        if count == 0:
            break
    #3
    if is_right(u):
        print('make(v)')
        print(make_good_str(v))
        print('u')
        print(u)
        return u+make_good_str(v)
    #4
    else:
        empty = collections.deque('')
        empty.append('(')
        empty += make_good_str(v)
        empty.append(')')
        u.popleft()
        u.pop()
        tmpu = []
        for i in u:
            if i == ')':
                tmpu.append('(')
            else:
                tmpu.append(')')
        return empty + collections.deque(tmpu)
def solution(p):
    return "".join(make_good_str(collections.deque(p)))
solution('()))((()')
