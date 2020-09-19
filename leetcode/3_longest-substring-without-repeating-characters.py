def lengthOfLongestSubstring(s: str) -> int:
	if not s:
		return 0
	if len(s) == 1:
		return 1
	l = []
	max_ = 0
	now = ''
	i = 0
	for j in range(1, len(s)):
		print(s[i:j]+s[j])
		found = s[i:j].find(s[j])
		if found == -1:
			max_ = max(max_, j-i+1)
			l.append(s[i:j+1])
		else:
			i = i + found + 1
	print(l)
	return max_
print(lengthOfLongestSubstring("bbbbcc"))
print(lengthOfLongestSubstring("abcabcbb"))
print(lengthOfLongestSubstring("dvdf"))
