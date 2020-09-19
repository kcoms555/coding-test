from typing import *
MIN = -(2**31)
def maxSubArray(nums: List[int]) -> int:
	f = [0] * len(nums)
	f[0] = nums[0]
	for i in range(1, len(nums)):
		f[i] = max(0, f[i-1]) + nums[i]
	return max(f)

print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
