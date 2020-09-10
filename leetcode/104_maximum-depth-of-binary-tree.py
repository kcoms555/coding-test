def maxDepth(self, root: TreeNode) -> int:
	def getdepth(root):
		if not root:
			return 0
		print(root.val)
		ld = rd = 0
		if root.left:
			ld = 1 + getdepth(root.left)
		if root.right:
			rd = 1 + getdepth(root.right)
		print(f'returning {root.val} : {max(ld, rd)}')
		return max(ld, rd)
	if root:
		return 1+getdepth(root)
	else:
		return 0
