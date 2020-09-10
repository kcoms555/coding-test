def invertTree(self, root: TreeNode) -> TreeNode:
	if not root:
		return None
	root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
	return root
