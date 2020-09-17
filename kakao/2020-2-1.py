import re
from typing import *
def solution(new_id: str) -> str:
    #1
    new_id = new_id.lower()
    #2
    new_id = "".join(re.split("[^a-z0-9-_.]", new_id))
    #3
    new_id = "".join(re.sub("\.+", ".", new_id))
    #4
    new_id = "".join(re.split("^\.|\.$", new_id))
    #5
    new_id = new_id if new_id else "a"
    #6
    if len(new_id) >= 16:
        new_id = new_id[:15]
        new_id = "".join(re.split("\.$", new_id))
    #7
    while len(new_id) <= 2:
        new_id = new_id + new_id[-1]
    return new_id
