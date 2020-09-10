def trap(self, height: List[int]) -> int:
	iheight = height[::-1]
	count=0
	_sum = sum(height)
	_len = len(height)
	if not height:
		return 0
	# max height ~ 0
	for i in range(max(height), 0, -1):
		left = height.index(i)
		right = iheight.index(i)
		count += _len - left - right
		
		height[left] -= 1
		iheight[right] -= 1
		
	if count>0:
		return count-_sum
	else:
		return 0
